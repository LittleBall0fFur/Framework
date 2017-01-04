#include <common/core.h>
#include "mainscene.h"

#include <stdio.h>

int main( void )
{
	//Initialize new variables
	Core* core = new Core();
	Scene* scene = new MainScene();

	core->run(scene);

	delete core;
	delete scene;
	return 0;
}
