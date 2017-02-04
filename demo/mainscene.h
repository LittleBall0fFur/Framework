#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <common/scene.h>
#include <common/vector2.h>

#include <common/audio.h>
#include <common/sound.h>

#include "ai.h"
#include "factory.h"
#include "canvas.h"

class MainScene: public Scene
{
public:
	MainScene();
	virtual ~MainScene();

	void update(float _deltaTime);
	void addMap();

	void addLayers();
	void setTopLayer(int _i);
private:
	Ai* spritesheet;

	Factory factory;

	unsigned int topLayer;
	std::vector<Ai*> layers;

	std::vector<Sound*> sounds;

	void loadSounds();
	void moveHamster(float _deltaTime);
	void addCanvas();
	void moveCamera(float _deltaTime);

	Canvas* canvas;
};

#endif
