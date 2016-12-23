#include "input.h"

Input::Input(){

}

Input::~Input(){

}
/*// Get mouse position
double xpos, ypos;
glfwGetCursorPos(window, &xpos, &ypos);
cursor = glm::vec3( xpos, ypos, 0 );
*/

// Right and Down vector
glm::vec3 right = glm::vec3(1, 0, 0);
glm::vec3 up = glm::vec3(0, -1, 0);

// Move up
if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
  position += up * _deltaTime * speed;
}
// Move down
if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
  position -= up * _deltaTime * speed;
}
// Strafe right
if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
  position += right * _deltaTime * speed;
}
// Strafe left
if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
  position -= right * _deltaTime * speed;
}
