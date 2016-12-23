#ifndef CORE_H
#define CORE_H

#include <common/renderer.h>
#include <common/entity.h>
#include <common/scene.h>

#include <glfw3.h>

class Core
{
public:
	Core();
	virtual ~Core();

	void showFps();
  float getDeltaTime(){return deltaTime;};
	void run(Scene* scene);

private:
	double calculateDeltaTime();

	Renderer renderer;

	float fpsCounter;
  int fps;
  double deltaTime;
};

#endif
