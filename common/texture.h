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

  float getHeight(){return height;};
  float getWidth(){return width;};
  GLuint getTextureBuffer() {return textureBuffer;};

private:
  float height;
  float width;
  GLuint textureBuffer;
};

#endif
