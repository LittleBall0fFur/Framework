#include "mainscene.h"

MainScene::MainScene(): Scene(){
  spritesheet = new Ai();
  spritesheet->addSpriteAsSpriteSheet("assets/smurf_sprite.tga",128, 128, 4 ,4);
  this->addChild(spritesheet);
  spritesheet->position.y = 540;

  //Audio
  Audio::init();
	this->loadSounds();
	sounds[0]->play();
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

void MainScene::loadSounds()
{
	Sound* a = new Sound("assets/grieves.wav");
	a->loop(true);
	a->gain(0.5f);
	sounds.push_back(a);

  Sound* b = new Sound("assets/explosion.wav");
	b->loop(true);
	b->gain(0.5f);
	sounds.push_back(b);
}

MainScene::~MainScene(){
  //delete spritesheet;
  //delete hud;
  // sounds
	size_t s = sounds.size();
	for (size_t i = 0; i < s; i++) {
		delete sounds[i];
	}
	sounds.clear();
}
