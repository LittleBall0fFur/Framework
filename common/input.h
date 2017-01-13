#ifndef INPUT_H
#define INPUT_H

// Include GLFW
#include <glfw3.h>

class Input
{
public:
	Input();
	virtual ~Input();

	void updateInput(GLFWwindow* _w);
	bool getKey(int _key) { return keys[_key]; }
	bool getKey(char _key) { return getKey((int) _key); }
	bool getMouse(int _button) { return mouse[_button]; }
	bool getKeyDown(int _key) { return keysDown[_key]; }
	bool getKeyDown(char _key) { return getKeyDown((int) _key); }
	bool getMouseDown(int _button) { return mouseDown[_button]; }
	bool getKeyUp(int _key) { return keysUp[_key]; }
	bool getKeyUp(char _key) { return getKeyUp((int) _key); }
	bool getMouseUp(int _button) { return mouseUp[_button]; }
	double getMouseX() { return mouseX; }
	double getMouseY() { return mouseY; }
	void setMouse(double _x, double _y) { glfwSetCursorPos(window, _x, _y); }

private:
	GLFWwindow* window;
	void handleKey(int _key);
	void handleMouse(int _key);

	bool keys[GLFW_KEY_LAST];
	bool keysUp[GLFW_KEY_LAST];
	bool keysDown[GLFW_KEY_LAST];

	bool mouse[GLFW_MOUSE_BUTTON_LAST];
	bool mouseUp[GLFW_MOUSE_BUTTON_LAST];
	bool mouseDown[GLFW_MOUSE_BUTTON_LAST];

	double mouseX;
	double mouseY;
};

#endif
