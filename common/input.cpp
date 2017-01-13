#include <common/input.h>

Input::Input()
{
	window = NULL;

	int i;
	for(i=0; i<GLFW_KEY_LAST; i++) {
		keys[i] = false;
		keysUp[i] = false;
		keysDown[i] = false;
	}
	for(i=0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		mouse[i] = false;
		mouseUp[i] = false;
		mouseDown[i] = false;
	}
}

Input::~Input()
{

}

void Input::updateInput(GLFWwindow* w)
{
	window = w;

	glfwPollEvents();

	int i;
	for(i=32; i<97;i++) {
		handleKey(i);
	}
	// Func + arrows + esc, etc
	for(i=255; i<GLFW_KEY_LAST;i++) {
		handleKey(i);
	}

	glfwGetCursorPos(window, &mouseX, &mouseY);

	// mouse buttons
	for(i=0; i<GLFW_MOUSE_BUTTON_LAST;i++) {
		handleMouse(i);
	}
}

void Input::handleMouse(int button)
{
	if (glfwGetMouseButton( window, button ) == GLFW_PRESS) {
		if (mouse[button] == false) {
			mouse[button] = true;
			mouseDown[button] = true;
		} else {
			mouseDown[button] = false;
		}
	}
	if (glfwGetMouseButton( window, button ) == GLFW_RELEASE) {
		if (mouse[button] == true) {
			mouse[button] = false;
			mouseUp[button] = true;
		} else {
			mouseUp[button] = false;
		}
	}
}

void Input::handleKey(int key)
{
	if (glfwGetKey( window, key ) == GLFW_PRESS) {
		if (keys[key] == false) {
			keys[key] = true;
			keysDown[key] = true;
		} else {
			keysDown[key] = false;
		}
	}
	if (glfwGetKey( window, key ) == GLFW_RELEASE) {
		if (keys[key] == true) { // still pressed
			keys[key] = false;
			keysUp[key] = true;
		} else {
			keysUp[key] = false;
		}
	}
}
