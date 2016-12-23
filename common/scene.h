#ifndef SCENE_H
#define SCENE_H

#include <common/entity.h>
#include <common/camera.h>
//#include <common/input.h>

class Scene: public Entity
{
public:
	Scene();
	virtual ~Scene();

	void updateScene(float deltaTime);

	Camera* getCamera() { return camera; };

	Camera* camera;

private:
	void updateEntity(Entity* entity, float deltaTime);
};

#endif
