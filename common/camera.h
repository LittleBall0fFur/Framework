/**
*@file camera.h
*
*@brief Camera header file.
*
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
  Camera();
  ~Camera();

  void computeMatricesFromInputs(GLFWwindow* window);
  void updateCamera(float _deltaTime);

  glm::vec3 getCursor(){return cursor;}
  glm::vec3 getPosition(){return position;}
  glm::mat4 getViewMatrix(){return ViewMatrix;}
private:
  glm::vec3 position;
  glm::vec3 cursor;
  glm::mat4 ViewMatrix;

  float deltaTime;

};
#endif
