#ifndef BUILDMENU_H
#define BUILDMENU_H

#include <common/entity.h>
#include <common/vector2.h>
#include <common/input.h>

#include "button.h"
#include "hudelement.h"
#include "ai.h"

class BuildMenu: public HudElement
{
public:
	BuildMenu();
	void update(float _deltaTime);
	virtual ~BuildMenu();
	void onClickEventListener(Vector2 _mousePos, float _deltaTime);
	void updateMousePos(Vector2 _mousePos);

	void onClick();

		Input* input;

private:
	void setupButtons();

	Button* muffinButton;
	std::vector<Button*> buttons;
	std::vector<Ai*> muffins;

	Vector2 mousePos;
};

#endif
