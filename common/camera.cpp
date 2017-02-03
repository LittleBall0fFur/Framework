#include "camera.h"

Camera::Camera(){
	cursor = glm::vec3( 0, 0, 0 );
	position = glm::vec3( 0, 0, 5 );
}

Camera::~Camera(){

}

void Camera::updateCamera(float _deltaTime){
	this->deltaTime = _deltaTime;
}

float speed = 300.0f; // 300 units / second

void Camera::computeMatricesFromInputs(GLFWwindow* window)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );
	// Right and Down vector
/*	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);

	// Move up
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		position += up * deltaTime * speed;
	}
	// Move down
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= up * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}*/

	// View matrix
	ViewMatrix = glm::lookAt(
			position, // Camera is at (xpos,ypos,5), in World Space
			position + glm::vec3(0, 0, -5), // and looks towards Z
			glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
			);
}
