#ifndef SCENE_H
#define SCENE_H

#include <common/entity.h>
#include <common/camera.h>
#include <common/input.h>

class Scene: public Entity
{
public:
	Scene();
	virtual ~Scene();

	void updateScene(float deltaTime);

	Camera* getCamera() { return camera; };
	Input* getInput() { return input; };
private:
	void updateEntity(Entity* entity, float deltaTime);

	Camera* camera;
	Input* input;
};

#endif
