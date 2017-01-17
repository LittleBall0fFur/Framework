#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <common/scene.h>
#include <common/vector2.h>

#include "factory.h"
#include "buildsystem.h"
#include "base.h"
#include "ai.h"

class MainScene: public Scene
{
public:
	MainScene();
	virtual ~MainScene();

	void update(float _deltaTime);
	void addMap();

private:
	Factory factory;
	BuildSystem buildSystem;

	Building* base;
	Ai* spritesheet;

	Ai* block1;
	Ai* block2;
	Ai* block3;

	Vector2 vector;

};

#endif
