#ifndef RENDERER_H
#define RENDERER_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

//Remove later
#include <common/shader.h>
#include <common/texture.h>
#include <common/scene.h>
#include <common/vector2.h>
#include <common/mesh.h>
#include <common/resourcemanager.h>

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	bool quit();
	void renderScene(Scene* _scene);

	int getWindowWidth(){return window_width;}
	int getWindowHeight(){return window_height;}
	GLFWwindow* getWindow(){return window;}

private:
	GLFWwindow* window;
	ResourceManager resman;

  int window_width;
  int window_height;

	std::string fragment_shader;
  std::string vertex_shader;

  GLuint programID;

  // Get a handle for our buffers
  GLuint vertexPosition_modelspaceID;
  GLuint vertexUVID;
	GLuint vertexUvOffsetID;

  // Get a handle for our "MVP" uniform
  GLuint matrixID;
  // Get a handle for our "myTextureSampler" uniform
  GLuint textureID;
	glm::mat4 getModelMatrix(Vector2 position, Vector2 scale, float rotation);

  glm::mat4 projectionMatrix;

	Texture* texture;
	Mesh* mesh;
	//Shader* shader;

	float uvWidth;
	float uvHeight;

	Shader* uberShader;

  void init();
  void renderMesh(Mesh* _mesh, glm::mat4 _MVP);
	void renderEntity(glm::mat4 &modelmatrix, Entity* _entity, Camera* camera);
};

#endif
