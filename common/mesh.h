#ifndef MESH_H
#define MESH_H

// Include GLEW
#include <GL/glew.h>
//#include <common/line.h>

class Mesh
{
public:
  Mesh();
  Mesh(int _width, int _height, GLuint _texture, float _uvWidth = 1, float _uvHeight = 1);
  virtual ~Mesh();

  void run();

  GLuint getVertexbuffer(){ return vertexbuffer; }
  GLuint getUvbuffer(){ return uvbuffer; }
  GLuint getTexture(){ return texture; }

  //void generateLineMesh(Line* _line);
  //void generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv);

private:
  GLuint vertexbuffer;
  GLuint uvbuffer;
  GLuint texture;

  unsigned int numverts;
};
#endif //MESH_H
