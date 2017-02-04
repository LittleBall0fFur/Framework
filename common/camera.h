/**
*@file camera.h
*
*@brief Camera header file.
*
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
  Camera();
  ~Camera();

  void computeMatricesFromInputs(GLFWwindow* window);
  void updateCamera(float _deltaTime);

  glm::vec3 getCursor(){return cursor;}
  glm::vec3 getPosition(){return position;}
  glm::vec3 getRotation(){return rotation;}
  glm::mat4 getViewMatrix(){return viewMatrix;}
  glm::mat4 getProjectionMatrix(){return projectionMatrix;}

  /// @brief set the projectionMatrix in 'perspective mode'.
  /// @return void
  void perspective();
  /// @brief set the projectionMatrix in 'orthogonal mode'.
  /// @return void
  void orthogonal();

  void tilt(float amount){ rotation.x += amount; }; ///< @brief tilt the Camera
	void pan(float amount){ rotation.y += amount; }; ///< @brief pan the Camera
	void roll(float amount){ rotation.z += amount; }; ///< @brief roll the Camera
	void dolly(float amount){ position += (glm::vec3(direction.x, direction.y, direction.z) * amount); }; ///< @brief dolly the Camera
	void track(float amount){ position += (glm::vec3(right.x, right.y, right.z) * amount); }; ///< @brief track the Camera
	void boom(float amount){ position += (glm::vec3(up.x, up.y, up.z) * amount); }; ///< @brief boom the Camera

  glm::vec3 rotation;
private:
  glm::vec3 position;

  glm::vec3 cursor;
  glm::mat4 viewMatrix;///< @brief The viewMatrix of the Camera
  glm::mat4 projectionMatrix; ///< @brief The (orthographic) projectionMatrix of the Camera
  glm::vec3 offset;

  glm::vec3 up; ///< @brief The up vector of the Camera.
	glm::vec3 right; ///< @brief The right vector of the Camera.
	glm::vec3 direction; ///< @brief The vector where the Camera is looking.

  float deltaTime;

};
#endif
