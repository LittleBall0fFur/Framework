#include "scene.h"

Scene::Scene(): Entity(){
  std::cout << "################ new Scene ################" << std::endl;
  camera = new Camera();
}

Scene::~Scene(){
  delete camera;
}

void Scene::updateScene(float deltaTime)
{
	this->updateEntity(this, deltaTime);
}


void Scene::updateEntity(Entity* entity, float deltaTime)
{
	// call update() for this entity
	entity->update(deltaTime);

	// update() all Children (recursively)
	std::vector<Entity*> children = entity->getChildren();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->updateEntity(*child, deltaTime);
	}
}
