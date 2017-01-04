#include "mainscene.h"

MainScene::MainScene(): Scene(){
  this->position = Vector2(480, 280);
  this->addSprite("assets/level.tga");

}

void MainScene::update(float _deltaTime){

}

MainScene::~MainScene(){

}
