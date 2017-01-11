#ifndef MESH_H
#define MESH_H

// Include GLEW
#include <GL/glew.h>

class Mesh
{
public:
  Mesh(int _width, int _height, GLuint _texture, float _uvWidth = 1, float _uvHeight = 1);
  virtual ~Mesh();

  void run();

  GLuint getVertexbuffer(){ return vertexbuffer; }
  GLuint getUvbuffer(){ return uvbuffer; }
  GLuint getTexture(){ return texture; }

private:
  GLuint vertexbuffer;
  GLuint uvbuffer;
  GLuint texture;
};
#endif //MESH_H
