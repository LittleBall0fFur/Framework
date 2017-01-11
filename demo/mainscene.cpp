#include "mainscene.h"

MainScene::MainScene(): Scene(){
  //addMap();
  spritesheet = new Ai();
  spritesheet->addSpriteAsSpriteSheet("assets/spritesheet.tga",128, 128, 4 ,4);
  this->addChild(spritesheet);
}

void MainScene::update(float _deltaTime){
  buildSystem.building();
  spritesheet->getSpriteSheet()->animate(_deltaTime, 1);
}

void MainScene::addMap(){
  //Factory::getInstance()->mapInstance().alpha = 0;
  this->addChild(factory.getInstance()->mapInstance());
}

MainScene::~MainScene(){
}
