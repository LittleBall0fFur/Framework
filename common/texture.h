#ifndef TEXTURE_H
#define TEXTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include <GL/glew.h>

#include <glfw3.h>

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

  int getHeight(){return height;};
  int getWidth(){return width;};
  GLuint getTextureBuffer() {return textureBuffer;};
  GLuint getGLTexture() {return glTexture[0];};


private:
  int height;
  int width;
  int depth;
  GLuint textureBuffer;
  GLuint glTexture[1];

  unsigned char warrantybit;

};

#endif
