#include <common/renderer.h>
#include <common/scene.h>

#include <stdio.h>

int main( void )
{
	//Initialize new variables
	Renderer* renderer = new Renderer();
	Scene* Myscene = new Scene();
	Entity* block = new Entity();
	Entity* block2 = new Entity();
	//AddSprite
	block->addSprite("assets/default.tga");
	block2->addSprite("assets/pencils.tga");
	//addChild
	Myscene->addChild(block);
	block->addChild(block2);
	//Transform of entity's
	block->position = Vector2(100, 300);
	block2->position = Vector2(150,200);
	block2->scale = Vector2(0.5f, 0.5f);
	block->scale = Vector2(1,1);
	//Initialize variables
	Vector2* vector;
	bool down = true;

	do {
		//block->rotation += 0.5f * renderer->getDeltaTime();
		block2->rotation += 3.0f * renderer->getDeltaTime();
		//block2->position += vector->addForce(Vector2(0.0f, 0.9f)) * renderer->getDeltaTime();
		if(block2->position.y >= 800)block2->position.y = 0;
		//block2->position -= vector->moveTowards(block2->position, Vector2(700, 200), 50.0f) * renderer->getDeltaTime();

		if(block->scale.x >= 0.5f && down){
			block->scale -= Vector2(0.1f, 0.1f) * renderer->getDeltaTime();
			if(block->scale.x <= 0.5f)down = false;
		}
		if(!down && block->scale.x < 1.5f){
			block->scale += Vector2(0.1f, 0.1f) * renderer->getDeltaTime();
			if(block->scale.x >= 1.5f)down = true;
		}

		renderer->renderScene(Myscene);
	}
	while(!renderer->quit());

	delete renderer;
	delete block;
	delete block2;

	return 0;
}
