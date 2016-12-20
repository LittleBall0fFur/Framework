#include <common/renderer.h>
#include <common/scene.h>

#include <stdio.h>

int main( void )
{
	Renderer* renderer = new Renderer();
	Scene* Myscene = new Scene();
	Entity* block = new Entity();
	Vector2* vector;
	block->addSprite("assets/default.tga");
	Myscene->addChild(block);

	Entity* block2 = new Entity();
	block2->addSprite("assets/pencils.tga");
	block->addChild(block2);
	block->position = Vector2(100, 300);
	block2->position = Vector2(150,200);
	block2->scale = Vector2(0.5f, 0.5f);


	do {
		//block->rotation += 0.5f * renderer->getDeltaTime();
		block2->rotation += 3.0f * renderer->getDeltaTime();
		//block2->position += vector->addForce(Vector2(0.0f, 0.9f)) * renderer->getDeltaTime();
		std::cout<<block2->position.y<<std::endl;
		if(block2->position.y >= 800)block2->position.y = 0;
		block2->position -= vector->moveTowards(block2->position, Vector2(700, 200), 50.0f) * renderer->getDeltaTime();

		renderer->renderScene(Myscene);
	}
	while(!renderer->quit());

	delete renderer;
	delete block;
	delete block2;

	return 0;
}
