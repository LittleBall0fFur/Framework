#include "mainscene.h"

MainScene::MainScene(): Scene(){
  spritesheet = new Ai();
  spritesheet->addSpriteAsSpriteSheet("assets/smurf_sprite.tga",128, 128, 4 ,4);
  this->addChild(spritesheet);
  spritesheet->position.y = 540;
}

void MainScene::update(float _deltaTime){
  buildSystem.building();
  if (this->getInput()->getKey(263)) {
		spritesheet->position.x -= 80.0f * _deltaTime;
    spritesheet->setScale(Vector2(-1, 1));
    spritesheet->getSpriteSheet()->animate(_deltaTime, 0.05f);
  }
  if (this->getInput()->getKey(262)) {
		spritesheet->position.x += 80.0f * _deltaTime;
    spritesheet->setScale(Vector2(1, 1));
    spritesheet->getSpriteSheet()->animate(_deltaTime, 0.05f);
  }
}

void MainScene::addMap(){
  this->addChild(factory.getInstance()->mapInstance());
}

MainScene::~MainScene(){
  //delete spritesheet;
  //delete hud;
}
