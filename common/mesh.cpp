#include <common/mesh.h>
#include <iostream>

Mesh::Mesh()
{
	vertexbuffer = 0;
	//_normalbuffer = 0;
	uvbuffer = 0;

	numverts = 0;
}

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

  float u = _uvHeight;
  float v = _uvWidth;
	// Two UV coordinates for each vertex.
	GLfloat g_uv_buffer_data[] = {
		v, u,
		0.0f, u,
		0.0f, 0.0f,

		0.0f, 0.0f,
		v, 0.0f,
	  v, u
	};

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

/*void Mesh::generateLineMesh(Line* _line)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;

	unsigned int s = _line->getPoints().size();

	// Create the vertices
	for (unsigned int i = 0; i < s; i++) {
		vertices.push_back(_line->getPoints()[i]);

		// 'double up' every vertex but the first.
		// the endpoint of the previous segment is the startpoint of the next.
		if (i != 0) {
			vertices.push_back(_line->getPoints()[i]);
		}
	}
	// close the line by going back to the first point
	vertices.push_back(_line->getPoints()[0]);

	// Copy the UV's
	unsigned int s2 = vertices.size();
	for (unsigned int i = 0; i < s2; i++) {
		uvs.push_back(glm::vec2(0.5f, 0.5f));
	}

	numverts = s2; // doesn't matter, Renderer will recalculate.

	this->generateBuffers(vertices, uvs);
}

void Mesh::generateBuffers(std::vector<glm::vec3>& vertex, std::vector<glm::vec2>& uv)
{
	//create GLuint _vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertex.size() * sizeof(glm::vec3), &vertex[0], GL_STATIC_DRAW);

	//create GLuint _normalbuffer;
	//glGenBuffers(1, &_normalbuffer);
	//glBindBuffer(GL_ARRAY_BUFFER, _normalbuffer);
	//glBufferData(GL_ARRAY_BUFFER, normal.size() * sizeof(glm::vec3), &normal[0], GL_STATIC_DRAW);

	//create GLuint _uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uv.size() * sizeof(glm::vec2), &uv[0], GL_STATIC_DRAW);
}
*/

Mesh::~Mesh()
{

}
