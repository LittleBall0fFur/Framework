#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>

#include <glfw3.h>

//defines a PixelBuffer
struct PixelBuffer
{
	int width;
	int height;
	/// 1 = grayscale
	/// 3 = 24 bit RGB
	/// 4 = 32 bit RGBA
	unsigned char bitdepth;
	/// 0 = none
	/// 1 = linear
	/// 2 = bilinear
	/// 3 = trilinear
	int filter;
	/// 0 = GL_REPEAT
	/// 1 = GL_MIRRORED_REPEAT
	/// 2 = GL_CLAMP_TO_EDGE
	int wrap;
	unsigned char* data;

	PixelBuffer()
	{
		width = 0;
		height = 0;
		bitdepth = 0;
		filter = 0;
		wrap = 0;
		data = (unsigned char*)0;
	}

	PixelBuffer(int _w, int _h, unsigned char _b, int _f, int _wr)
	{
		width = _w;
		height = _h;
		bitdepth = _b;
		filter = _f;
		wrap = _wr;
		long size = _w * _h * _b;
		data = new unsigned char[size];
		for (long i=0; i<size; i++) {
			data[i] = 255;
		}
	}
	~PixelBuffer() { delete[] data; data = 0; /*std::cout << "delete PixelBuffer" << std::endl;*/ }
	void destroy() { delete[] data; data = 0; /*std::cout << "destroy PixelBuffer" << std::endl;*/ }
};

class Texture
{
public:
  Texture();
  virtual ~Texture();
  GLuint loadBMP_custom(const char * imagepath);

  GLuint loadTGA(const std::string& imagepath);
  static GLuint getTGA(const std::string& imagepath);
  GLuint loadTGAImage(const std::string& _filePath, int _filter, int _wrap);
  GLuint loadDDS(const char * imagepath);

  float getHeight(){return height;};
  float getWidth(){return width;};
  GLuint getTextureBuffer() {return textureBuffer;};
  PixelBuffer* getPixelBuffer(){return pixelbuffer;};
  GLuint getGLTexture() {return glTexture[0];};
	PixelBuffer* getPixels() {return pixelbuffer;};

  void BGR2RGB(PixelBuffer* _pixels);
  void createFromBuffer(PixelBuffer* _pixels);

private:
  float height;
  float width;
  int depth;
  GLuint textureBuffer;
  GLuint glTexture[1];

  PixelBuffer* pixelbuffer;
  unsigned char warrantybit;

 void deletePixelBuffer() {
		if (pixelbuffer != NULL) {
			delete pixelbuffer;
			pixelbuffer = NULL;
		}
	};
};

#endif
