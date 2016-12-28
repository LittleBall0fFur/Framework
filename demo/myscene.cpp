#include "myscene.h"

Myscene::Myscene(): Scene(){
  block = new Ai();
 	block2 = new Ai();
 	//AddSprite
 	block->addSprite("assets/default.tga");
 	block2->addSprite("assets/pencils.tga");
 	//addChild
 	this->addChild(block);
 	this->addChild(block2);
 	//Transform of entity's
 	block->position = Vector2(100, 300);
 	block2->position = Vector2(1500,300);
 	block2->scale = Vector2(0.5f, 0.5f);
 	block->scale = Vector2(1,1);
 	//Initialize variables
 	Vector2* vector;
 	bool down = true;
}

void Myscene::update(float _deltaTime){

  //block->rotation += 0.5f * _deltaTime;
  //block2->rotation += 3.0f * _deltaTime;
  //block2->position += vector->addForce(Vector2(0.0f, 0.9f)) * _deltaTime;
  if(block2->position.y >= 800)block2->position.y = 0;
  block2->position -= vector.moveTowards(block2->position, block->position, 100.0f) * _deltaTime;
  if(block->hitTestObject(block2)){
    std::cout<<1<<std::endl;
  }
/**if(block->scale.x >= 0.5f && down){
    block->scale -= Vector2(0.1f, 0.1f) * _deltaTime;
    if(block->scale.x <= 0.5f)down = false;
  }
  if(!down && block->scale.x < 1.5f){
    block->scale += Vector2(0.1f, 0.1f) * _deltaTime;
    if(block->scale.x >= 1.5f)down = true;
  }*/
}

Myscene::~Myscene(){
  delete block;
  delete block2;
}
