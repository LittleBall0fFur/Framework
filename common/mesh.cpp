#include <common/mesh.h>
#include <iostream>
Mesh::Mesh(int _width, int _height, GLuint _texture, float _uvWidth, float _uvHeight)
{
  // Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
  this->texture = _texture;
	int sprite_width = _width;
	int sprite_height = _height;
	GLfloat g_vertex_buffer_data[] = {
		 0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
		-0.5f * sprite_width, -0.5f * sprite_height, 0.0f,
		-0.5f * sprite_width,  0.5f * sprite_height, 0.0f,

		-0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		 0.5f * sprite_width,  0.5f * sprite_height, 0.0f,
		 0.5f * sprite_width, -0.5f * sprite_height, 0.0f
	};

  float u = _uvWidth;
  float v = _uvHeight;
  //u = 0.5f;
  //v = 0.5f;
  //std::cout << v << std::endl;
  //std::cout << u << std::endl;
	// Two UV coordinates for each vertex.
	GLfloat g_uv_buffer_data[] = {
		u, v,
		0.0f, v,
		0.0f, 0.0f,

		0.0f, 0.0f,
		u, 0.0f,
		u, v
	};

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

Mesh::~Mesh()
{

}
