#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <common/scene.h>

#include "factory.h"
#include "buildsystem.h"

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
	Ai* spritesheet;
};

#endif
