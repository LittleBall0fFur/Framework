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
/*
#define 	GLFW_KEY_UNKNOWN   -1
#define 	GLFW_KEY_SPACE   32
#define 	GLFW_KEY_APOSTROPHE   39 // '
#define 	GLFW_KEY_COMMA   44 // ,
#define 	GLFW_KEY_MINUS   45 // -
#define 	GLFW_KEY_PERIOD   46 // .
#define 	GLFW_KEY_SLASH   47 // /
#define 	GLFW_KEY_0   48
...
#define 	GLFW_KEY_9   57
#define 	GLFW_KEY_SEMICOLON   59 // ;
#define 	GLFW_KEY_EQUAL   61 // =
#define 	GLFW_KEY_A   65
#define 	GLFW_KEY_B   66
#define 	GLFW_KEY_C   67
...
#define 	GLFW_KEY_Z   90
#define 	GLFW_KEY_LEFT_BRACKET   91 // [
#define 	GLFW_KEY_BACKSLASH   92 // \
#define 	GLFW_KEY_RIGHT_BRACKET   93 // ]
#define 	GLFW_KEY_GRAVE_ACCENT   96 // `
#define 	GLFW_KEY_WORLD_1   161 // non-US #1
#define 	GLFW_KEY_WORLD_2   162 // non-US #2
#define 	GLFW_KEY_ESCAPE   256
#define 	GLFW_KEY_ENTER   257
#define 	GLFW_KEY_TAB   258
#define 	GLFW_KEY_BACKSPACE   259
#define 	GLFW_KEY_INSERT   260
#define 	GLFW_KEY_DELETE   261
#define 	GLFW_KEY_RIGHT   262
#define 	GLFW_KEY_LEFT   263
#define 	GLFW_KEY_DOWN   264
#define 	GLFW_KEY_UP   265
#define 	GLFW_KEY_PAGE_UP   266
#define 	GLFW_KEY_PAGE_DOWN   267
#define 	GLFW_KEY_HOME   268
#define 	GLFW_KEY_END   269
#define 	GLFW_KEY_CAPS_LOCK   280
#define 	GLFW_KEY_SCROLL_LOCK   281
#define 	GLFW_KEY_NUM_LOCK   282
#define 	GLFW_KEY_PRINT_SCREEN   283
#define 	GLFW_KEY_PAUSE   284
#define 	GLFW_KEY_F1   290
...
#define 	GLFW_KEY_F25   314
#define 	GLFW_KEY_KP_0   320
...
#define 	GLFW_KEY_KP_9   329
#define 	GLFW_KEY_KP_DECIMAL   330
#define 	GLFW_KEY_KP_DIVIDE   331
#define 	GLFW_KEY_KP_MULTIPLY   332
#define 	GLFW_KEY_KP_SUBTRACT   333
#define 	GLFW_KEY_KP_ADD   334
#define 	GLFW_KEY_KP_ENTER   335
#define 	GLFW_KEY_KP_EQUAL   336
#define 	GLFW_KEY_LEFT_SHIFT   340
#define 	GLFW_KEY_LEFT_CONTROL   341
#define 	GLFW_KEY_LEFT_ALT   342
#define 	GLFW_KEY_LEFT_SUPER   343
#define 	GLFW_KEY_RIGHT_SHIFT   344
#define 	GLFW_KEY_RIGHT_CONTROL   345
#define 	GLFW_KEY_RIGHT_ALT   346
#define 	GLFW_KEY_RIGHT_SUPER   347
#define 	GLFW_KEY_MENU   348
#define 	GLFW_KEY_LAST   GLFW_KEY_MENU
*/

/*
#define 	GLFW_MOUSE_BUTTON_1   0
#define 	GLFW_MOUSE_BUTTON_2   1
#define 	GLFW_MOUSE_BUTTON_3   2
#define 	GLFW_MOUSE_BUTTON_4   3
#define 	GLFW_MOUSE_BUTTON_5   4
#define 	GLFW_MOUSE_BUTTON_6   5
#define 	GLFW_MOUSE_BUTTON_7   6
#define 	GLFW_MOUSE_BUTTON_8   7
#define 	GLFW_MOUSE_BUTTON_LAST   GLFW_MOUSE_BUTTON_8
#define 	GLFW_MOUSE_BUTTON_LEFT   GLFW_MOUSE_BUTTON_1
#define 	GLFW_MOUSE_BUTTON_RIGHT   GLFW_MOUSE_BUTTON_2
#define 	GLFW_MOUSE_BUTTON_MIDDLE   GLFW_MOUSE_BUTTON_3
*/

#endif
