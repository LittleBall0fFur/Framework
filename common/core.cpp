#include "core.h"

Core::Core(){
  deltaTime = 0;

  fpsCounter = 0.0f;
  fps = 0;
}

Core::~Core(){

}

void Core::run(Scene* _scene){
  do{
    // update our _deltaTime
    calculateDeltaTime();
    // Update camera instance in Scene
    _scene->getCamera()->updateCamera((float)deltaTime);
    //Update the input instance in the Scene
    _scene->getInput()->updateInput(renderer.getWindow());
    // Update Scene (and recursively all children)
    _scene->updateScene((float)deltaTime);
    // Render Scene
    renderer.renderScene(_scene);
  }
  while(!renderer.quit());
}

double Core::calculateDeltaTime(){
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	deltaTime = startTime - lastTime;
	lastTime = startTime;

	return deltaTime;
}

void Core::showFps() {
  calculateDeltaTime();
	fpsCounter += deltaTime;
	fps++;
	if (fpsCounter >= 1.0f) {
		fpsCounter = fmod(fpsCounter, deltaTime);
		std::cout << "FPS: " << fps << std::endl;
		fps = 0;
	}
}
