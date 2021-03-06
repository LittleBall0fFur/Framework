#include "texture.h"

Texture::Texture(){
  glTexture[0] = 0;

  pixelbuffer = NULL;
  width = 0;
	height = 0;
	depth = 3;

	warrantybit = 1;
}

Texture::~Texture(){
  glDeleteTextures(1, &glTexture[0]);
  deletePixelBuffer();
}

GLuint Texture::loadTGA(const std::string& imagepath)
{
  std::cout << "Loading TGA: " << imagepath << std::endl;
	FILE *file;
	unsigned char type[4];
	unsigned char info[6];

	file = fopen(imagepath.c_str(), "rb");
	if (!file) {
		std::cout << "error: unable to open file" << std::endl;
		return 0;
	}

	size_t s;
	s = fread (&type, sizeof (char), 3, file);
	fseek (file, 12, SEEK_SET);
	s = fread (&info, sizeof (char), 6, file);

	//image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		std::cout << "error: image type neither color or grayscale" << std::endl;
		fclose(file);
		return 0;
	}

    unsigned int imagesize;
    unsigned int width, height;
    unsigned char* data;
    unsigned char bitdepth;

	width = info[0] + info[1] * 256;
	height = info[2] + info[3] * 256;
	bitdepth = info[4] / 8;

	if (bitdepth != 1 && bitdepth != 3 && bitdepth != 4) {
		std::cout << "bytecount not 1, 3 or 4" << std::endl;
		fclose(file);
		return 0;
	}

    // Check if the image's width and height is a power of 2. No biggie, we can handle it.
	if ((width & (width - 1)) != 0) {
		std::cout << "warning: " << imagepath << "’s width is not a power of 2" << std::endl;
	}
	if ((height & (height - 1)) != 0) {
		std::cout << "warning: " << imagepath << "’s height is not a power of 2" << std::endl;
	}
	if (width != height) {
		std::cout << "warning: " << imagepath << " is not square" << std::endl;
	}

	imagesize = width * height * bitdepth;
	//imgheight = height;
	//imgwidth = width;
  // Create a buffer
  data = new unsigned char [imagesize];

  // Read the actual data from the file into the buffer
  fread(data,1,imagesize,file);

  // Everything is in memory now, the file wan be closed
  fclose (file);

  // Create one OpenGL texture
  // Be sure to also delete it from where you called this with glDeleteTextures()
  GLuint textureID;
  glGenTextures(1, &textureID);

  // "Bind" the newly created texture : all future texture functions will modify this texture
  glBindTexture(GL_TEXTURE_2D, textureID);

  // filter the Texture
  unsigned char filter = 0;
  switch (filter) {
      case 0:
          // No filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          break;
      case 1:
          // Linear filtering.
		  		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		  		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
          break;
      case 2:
          // Bilinear filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
          glGenerateMipmap(GL_TEXTURE_2D);
          break;
      case 3:
          // Trilinear filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
          glGenerateMipmap(GL_TEXTURE_2D);
          break;
      default:
          // No filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          break;
  }

  // wrapping
  // GL_REPEAT, GL_MIRRORED_REPEAT or GL_CLAMP_TO_EDGE
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  // handle transparency and grayscale and give the image to OpenGL
  switch (bitdepth) {
      case 4:
          glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
          glEnable(GL_BLEND);
          glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
          break;
      case 3:
          glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
          break;
      case 1:
          glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width, height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
          break;
      default:
          std::cout << "error: bitdepth not 4, 3, or 1" << std::endl;
          break;
  }

  // OpenGL has now copied the data. Free our own version
  delete [] data;

  // Return the returnID of the texture we just created
  this->height = height;
  this->width = width;
  this->textureBuffer = textureID;
  return textureID;
}

GLuint loadBMP_custom(const char * imagepath)
{
	printf("Reading image %s\n", imagepath);

	// Data read from the header of the BMP file
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int imageSize;
	unsigned int width, height;
	// Actual RGB data
	unsigned char * data;

	// Open the file
	FILE * file = fopen(imagepath,"rb");
	if (!file) {
		printf("Can't open %s.\n", imagepath);
		getchar();
		return 0;
	}

	// Read the header, i.e. the 54 first bytes

	// If less than 54 bytes are read, problem
	if ( fread(header, 1, 54, file)!=54 ) {
		printf("Not a correct BMP file\n");
		return 0;
	}
	// A BMP files always begins with "BM"
	if ( header[0]!='B' || header[1]!='M' ) {
		printf("Not a correct BMP file\n");
		return 0;
	}
	// Make sure this is a 24bpp file
	if ( *(int*)&(header[0x1E])!=0  )         {printf("Not a correct BMP file\n");    return 0;}
	if ( *(int*)&(header[0x1C])!=24 )         {printf("Not a correct BMP file\n");    return 0;}

	// Read the information about the image
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char [imageSize];

	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);

	// Everything is in memory now, the file wan be closed
	fclose (file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	// OpenGL has now copied the data. Free our own version
	delete [] data;

	// Poor filtering, or ...
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	// ... nice trilinear filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Return the ID of the texture we just created
	return textureID;
}

GLuint Texture::loadTGAImage(const std::string& _filePath, int _filter, int _wrap)
{
	std::cout << "Loading TGA: " << _filePath << std::endl;

	// Load .tga file
	FILE *file;
	unsigned char type[4];
	unsigned char info[6];

	file = fopen(_filePath.c_str(), "rb");

	if (!file) {
		std::cout << "unable to open file" << std::endl;
		return false;
	}

	size_t s;
	s = fread (&type, sizeof (char), 3, file);
	fseek (file, 12, SEEK_SET);
	s = fread (&info, sizeof (char), 6, file);

	//image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		std::cout << "image type neither color or grayscale" << std::endl;
		fclose(file);
		return false;
	}

	PixelBuffer* pixels = new PixelBuffer();
	pixels->width = info[0] + info[1] * 256;
	pixels->height = info[2] + info[3] * 256;
	pixels->bitdepth = info[4] / 8;
	pixels->filter = _filter;
	pixels->wrap = _wrap;

	if (pixels->bitdepth != 1 && pixels->bitdepth != 3 && pixels->bitdepth != 4) {
		std::cout << "bytecount not 1, 3 or 4" << std::endl;
		fclose(file);
		return false;
	}

	long file_size = pixels->width * pixels->height * pixels->bitdepth;

	//allocate memory for image data
	pixels->data = new unsigned char[file_size];

	//read in image data
	s = fread(pixels->data, sizeof(unsigned char), file_size, file);
	if (s == 0) return false;

	//close file
	fclose(file);

	// BGR(A) to RGB(A)
	if (pixels->bitdepth == 3 || pixels->bitdepth == 4) {
		BGR2RGB(pixels);
	}
	// Check if the image's width and height is a power of 2. No biggie, we can handle it.
	if ((pixels->width & (pixels->width - 1)) != 0) {
		warrantybit = 0;
		//std::cout << "warning: " << filename << "’s width is not a power of 2" << std::endl;
	}
	if ((pixels->height & (pixels->height - 1)) != 0) {
		warrantybit = 0;
		//std::cout << "warning: " << filename << "’s height is not a power of 2" << std::endl;
	}
	if (pixels->width != pixels->height) {
		//_warrantybit = 0;
		//std::cout << "warning: " << filename << " is not square" << std::endl;
	}

	// Generate the OpenGL Texture
	createFromBuffer(pixels);
	delete pixels;
	return glTexture[0];
}

void Texture::BGR2RGB(PixelBuffer* _pixels)
{
	// this also works as BGRA2RGBA
	long counter = 0;
	long s = _pixels->width * _pixels->height;
	for (long i=0; i<s; i++) {
		//swap every 1st byte with every 3rd byte
		unsigned char temp = _pixels->data[counter];
		_pixels->data[counter] = _pixels->data[counter+2];
		_pixels->data[counter+2] = temp;

		counter += _pixels->bitdepth;
	}
}

void Texture::createFromBuffer(PixelBuffer* _pixels)
{
	//allocate memory and copy image data to pixelBuffer
	deletePixelBuffer();
	if (_pixels->bitdepth == 1) {
		// use 8-bit grayscale texture as 32-bit white + alpha
		pixelbuffer = new PixelBuffer(_pixels->width, _pixels->height, 4, _pixels->filter, _pixels->wrap);
		int size = _pixels->width * _pixels->height;
		int counter = 0;
		for (int i = 0; i < size; i++) {
			pixelbuffer->data[counter+0] = 255;
			pixelbuffer->data[counter+1] = 255;
			pixelbuffer->data[counter+2] = 255;
			pixelbuffer->data[counter+3] = _pixels->data[(counter+3)/4];

			counter += 4;
		}
	} else {
		pixelbuffer = new PixelBuffer(_pixels->width, _pixels->height, _pixels->bitdepth, _pixels->filter, _pixels->wrap);
		int size = _pixels->width * _pixels->height * _pixels->bitdepth;
		for (int i = 0; i < size; i++) {
			pixelbuffer->data[i] = _pixels->data[i];
		}
	}

	// set Entity properties
	this->width = _pixels->width;
	this->height = _pixels->height;
	this->depth = _pixels->bitdepth;

	// generate a number of texturenames (just 1 for now)
	glGenTextures(1, this->glTexture);

	// setup first texture (the only one in this case)
	// if you created more, use this->_gltexture[x], where x is the id of the texturename.
	glBindTexture(GL_TEXTURE_2D, this->glTexture[0]);

	// handle transparency
	if (this->depth == 4) {
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _pixels->data);
	}
	if (this->depth == 3) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, _pixels->data);
	}
	if (this->depth == 1) {
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixelbuffer->data);
	}

	// 0 = GL_REPEAT
	// 1 = GL_MIRRORED_REPEAT
	// 2 = GL_CLAMP_TO_EDGE
	if (_pixels->wrap == 0) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	} else if (_pixels->wrap == 1) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	} else if (_pixels->wrap == 2) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}

	// filter the Texture
	if (_pixels->filter == 0) {
		// No filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	} else if (_pixels->filter == 1) {
		// Linear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	} else if (_pixels->filter == 2) {
		// Bilinear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
	} else if (_pixels->filter == 3) {
		// Trilinear filtering.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
}

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

GLuint Texture::loadDDS(const char * imagepath)
{
	unsigned char header[124];

	FILE *fp;

	/* try to open the file */
	fp = fopen(imagepath, "rb");
	if (fp == NULL){
		printf("Can't open %s.\n", imagepath);
		getchar();
		return 0;
	}

	/* verify the type of file */
	char filecode[4];
	fread(filecode, 1, 4, fp);
	if (strncmp(filecode, "DDS ", 4) != 0) {
		fclose(fp);
		return 0;
	}

	/* get the surface desc */
	fread(&header, 124, 1, fp);

	unsigned int height      = *(unsigned int*)&(header[8 ]);
	unsigned int width	     = *(unsigned int*)&(header[12]);
	unsigned int linearSize	 = *(unsigned int*)&(header[16]);
	unsigned int mipMapCount = *(unsigned int*)&(header[24]);
	unsigned int fourCC      = *(unsigned int*)&(header[80]);


	unsigned char * buffer;
	unsigned int bufsize;
	/* how big is it going to be including all mipmaps? */
	bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
	buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
	fread(buffer, 1, bufsize, fp);
	/* close the file pointer */
	fclose(fp);

	unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4;
	unsigned int format;
	switch(fourCC)
	{
	case FOURCC_DXT1:
		format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
		break;
	case FOURCC_DXT3:
		format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
		break;
	case FOURCC_DXT5:
		format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
		break;
	default:
		free(buffer);
		return 0;
	}

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);

	unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
	unsigned int offset = 0;

	/* load the mipmaps */
	for (unsigned int level = 0; level < mipMapCount && (width || height); ++level)
	{
		unsigned int size = ((width+3)/4)*((height+3)/4)*blockSize;
		glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,
			0, size, buffer + offset);

		offset += size;
		width  /= 2;
		height /= 2;

		// Deal with Non-Power-Of-Two textures. This code is not included in the webpage to reduce clutter.
		if(width < 1) width = 1;
		if(height < 1) height = 1;

	}

	free(buffer);

	return textureID;
}
GLuint Texture::getTGA(const std::string& imagepath)
{
    std::cout << "Loading TGA: " << imagepath << std::endl;

	FILE *file;
	unsigned char type[4];
	unsigned char info[6];

	file = fopen(imagepath.c_str(), "rb");
	if (!file) {
		std::cout << "error: unable to open file" << std::endl;
		return 0;
	}

	size_t s;
	s = fread (&type, sizeof (char), 3, file);
	fseek (file, 12, SEEK_SET);
	s = fread (&info, sizeof (char), 6, file);

	//image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		std::cout << "error: image type neither color or grayscale" << std::endl;
		fclose(file);
		return 0;
	}

    unsigned int imagesize;
    unsigned int width, height;
    unsigned char* data;
    unsigned char bitdepth;

	width = info[0] + info[1] * 256;
	height = info[2] + info[3] * 256;
	bitdepth = info[4] / 8;

	if (bitdepth != 1 && bitdepth != 3 && bitdepth != 4) {
		std::cout << "bytecount not 1, 3 or 4" << std::endl;
		fclose(file);
		return 0;
	}

    // Check if the image's width and height is a power of 2. No biggie, we can handle it.
	if ((width & (width - 1)) != 0) {
		std::cout << "warning: " << imagepath << "’s width is not a power of 2" << std::endl;
	}
	if ((height & (height - 1)) != 0) {
		std::cout << "warning: " << imagepath << "’s height is not a power of 2" << std::endl;
	}
	if (width != height) {
		std::cout << "warning: " << imagepath << " is not square" << std::endl;
	}

	imagesize = width * height * bitdepth;
	//imgheight = height;
	//imgwidth = width;
  // Create a buffer
  data = new unsigned char [imagesize];

  // Read the actual data from the file into the buffer
  fread(data,1,imagesize,file);

  // Everything is in memory now, the file wan be closed
  fclose (file);

  // Create one OpenGL texture
  // Be sure to also delete it from where you called this with glDeleteTextures()
  GLuint textureID;
  glGenTextures(1, &textureID);

  // "Bind" the newly created texture : all future texture functions will modify this texture
  glBindTexture(GL_TEXTURE_2D, textureID);

  // filter the Texture
  unsigned char filter = 0;
  switch (filter) {
      case 0:
          // No filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          break;
      case 1:
          // Linear filtering.
		  		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		  		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
          break;
      case 2:
          // Bilinear filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
          glGenerateMipmap(GL_TEXTURE_2D);
          break;
      case 3:
          // Trilinear filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
          glGenerateMipmap(GL_TEXTURE_2D);
          break;
      default:
          // No filtering.
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
          break;
  }

  // wrapping
  // GL_REPEAT, GL_MIRRORED_REPEAT or GL_CLAMP_TO_EDGE
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

  // handle transparency and grayscale and give the image to OpenGL
  switch (bitdepth) {
      case 4:
          glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
          glEnable(GL_BLEND);
          glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
          break;
      case 3:
          glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
          break;
      case 1:
          glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width, height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
          break;
      default:
          std::cout << "error: bitdepth not 4, 3, or 1" << std::endl;
          break;
  }

  // OpenGL has now copied the data. Free our own version
  delete [] data;

  // Return the returnID of the texture we just created
  return textureID;
}
