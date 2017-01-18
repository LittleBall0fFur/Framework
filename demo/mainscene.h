#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <common/scene.h>
#include <common/vector2.h>

#include <common/audio.h>
#include <common/sound.h>

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

	Ai* spritesheet;

	Vector2 vector;

	std::vector<Sound*> sounds;

	void loadSounds();
};

#endif
