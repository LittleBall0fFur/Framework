#include <common/renderer.h>
#include <common/scene.h>

#include <stdio.h>

int main( void )
{
	Renderer* renderer = new Renderer();
	Scene* Myscene = new Scene();
	Entity* block = new Entity();
	block->addSprite("assets/default.tga");
	Myscene->addChild(block);

	Entity* block2 = new Entity();
	block2->addSprite("assets/pencils.tga");
	block->addChild(block2);

	do {
		block->rotation += 0.5f * renderer->getDeltaTime();
		block->position = Vector2(100, 300);
		block2->position = Vector2(150,200);
		block2->rotation += 2.0f * renderer->getDeltaTime();
		block2->scale = Vector2(0.5f, 0.5f);

		renderer->renderScene(Myscene);
	}
	while(!renderer->quit());

	delete renderer;
	delete block;
	delete block2;

	return 0;
}
