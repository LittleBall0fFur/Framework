/**
*@file camera.h
*
*@brief Camera header file.
*
*/
#ifndef CAMERA_H
#define CAMERA_H

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera{
public:
  Camera();
  ~Camera();

  void computeMatricesFromInputs(GLFWwindow* window);
  glm::mat4 getViewMatrix();
  glm::vec3 getCursor();

  glm::vec3 getPosition(){return position;}
private:
  glm::vec3 position;
  glm::vec3 cursor;
  glm::mat4 ViewMatrix;
};
#endif
