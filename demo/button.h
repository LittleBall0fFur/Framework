#ifndef BUTTON_H
#define BUTTON_H

#include <common/entity.h>
#include <common/vector2.h>

class Button: public Entity
{
public:
	Button();
	virtual ~Button();

	void update(float _deltaTime);

	void mouseOver(Vector2 _mousePos, float _deltaTime);
	bool getMouseOver(){return flag;}

private:
	bool flag;

};

#endif
