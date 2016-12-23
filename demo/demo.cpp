#include <common/core.h>
#include "myscene.h"

#include <stdio.h>

int main( void )
{
	//Initialize new variables
	Core* core = new Core();
	Scene* myscene = new Myscene();

	core->run(myscene);

	delete core;
	delete myscene;
	return 0;
}
