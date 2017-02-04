#include "camera.h"

Camera::Camera(){
	cursor = glm::vec3( 0, 0, 0 );
	position = glm::vec3( 0, 0, 5 );
	rotation = glm::vec3( 0, 3.14159265359f, 0 );

	direction = glm::vec3(0, 0, -5);
	up = glm::vec3(0, 1, 0);
	right = glm::vec3(1, 0, 0);

	this->orthogonal();
}

Camera::~Camera(){

}

void Camera::updateCamera(float _deltaTime){
	this->deltaTime = _deltaTime;

	// Direction vector: Spherical coordinates to Cartesian coordinates conversion
	direction = glm::vec3(
		cos(rotation.x) * sin(rotation.y),
		sin(rotation.x),
		cos(rotation.x) * cos(rotation.y)
	);
	//_direction = glm::vec3(0, 0, -5);

	// Right vector
	right = glm::vec3(
		sin(rotation.y - 1.57079632679),
		0,
		cos(rotation.y - 1.57079632679)
	);
	right = glm::rotateZ(right, rotation.z*(float)57.2957795); // rotateZ() in Degrees
	//_right = glm::vec3(1, 0, 0);

	// Up vector
	up = glm::cross(right, direction);
	//_up = glm::vec3(0, 1, 0);

	glm::vec3 pos = glm::vec3(position.x, position.y, position.z);
	glm::vec3 offset = glm::vec3(offset.x, offset.y, offset.z);

	// View matrix
	viewMatrix = glm::lookAt(
			pos - offset, // Camera is at (xpos,ypos,1), in World Space
			pos - offset + direction, // and looks towards Z
			up  // Head is up
	);
}

float speed = 300.0f; // 300 units / second

void Camera::computeMatricesFromInputs(GLFWwindow* window)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );
}

void Camera::perspective()
{
	// offset is 0,0,0 because in 3D we want 0,0,0 in the middle of the screen
	offset = glm::vec3(0, 0, 0);
	position = glm::vec3( 0, 0, 650 ) + offset;

	// FoV, aspectratio, nearclip, farclip
	projectionMatrix = glm::perspective(45.0f, (float)1920/(float)1080, 0.1f, 10000.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
}

void Camera::orthogonal()
{
	// to compensate for the camera being not in the correct position
	offset = glm::vec3(1920/2, 1080/2, 0);

	// Initial position : on +Z
	// Unintuitively, this is the centre of the screen, so add _offset
	position = glm::vec3( 0, 0, 650 ) + offset;

	projectionMatrix = glm::ortho(0.0f, (float)1920, (float)1080, 0.0f, 0.1f, 1000.0f);

	// Disable depth test (we don't need it in 2D)
	glDisable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);
}
