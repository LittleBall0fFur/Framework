#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

class Shader
{
public:
  Shader();
  ~Shader();
  GLuint loadShaders(const char * vertex_file_path, const char * fragment_file_path);
  GLuint getProgramID(){return programID;};
  GLuint getUvOffsetID(){return uvOffsetID;};

private:
  GLuint programID;
	GLuint matrixID;
	GLuint textureID;
  GLuint uvOffsetID;
  
	void attachID();
};
#endif
