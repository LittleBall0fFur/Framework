#ifndef CANVAS_H
#define CANVAS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <common/entity.h>
#include <common/input.h>

#include "buildmenu.h"

class Canvas: public Entity
{
public:
	Canvas();
	virtual ~Canvas();

	void update(float _deltaTime);
	void getCursorPos(Vector2 _mousePos);
	void setInput(Input* _input);

private:
	BuildMenu* buildMenu;
	Vector2 mousePos;

};

#endif
