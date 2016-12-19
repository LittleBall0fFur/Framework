#include "scene.h"

Scene::Scene(): Entity(){
  std::cout << "################ new Scene ################" << std::endl;
  camera = new Camera();
}

Scene::~Scene(){
  delete camera;
}

void Scene::update(float deltaTime){

}
