#include "mainscene.h"

MainScene::MainScene(): Scene(){
  //Audio
  Audio::init();
	this->loadSounds();
	sounds[0]->play();

  //Layers
  topLayer = 0;
  setTopLayer(1);
  addLayers();

  spritesheet = new Ai();
  spritesheet->addSpriteAsSpriteSheet("assets/Hamster_Loop.tga",64, 64, 4 ,2);
  layers[0]->addChild(spritesheet);
  spritesheet->position.y = 540;
  addCanvas();
}

void MainScene::update(float _deltaTime){
  moveHamster(_deltaTime);
  canvas->getCursorPos(Vector2(this->getCamera()->getCursor().x, this->getCamera()->getCursor().y));
}

void MainScene::addCanvas(){
  std::cout<<this->getCamera()->getCursor().x<<std::endl;
  canvas = new Canvas();
  canvas->setInput(this->getInput());
  layers[1]->addChild(canvas);
}

void MainScene::moveHamster(float _deltaTime){
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

void MainScene::addLayers(){
  for (unsigned int i = 0; i <= topLayer; i++) {
		Ai* layer = new Ai();
		layers.push_back(layer);
		this->addChild(layer);
    std::cout<< "Scene contains: " << layers.size()<<" layers"<<std::endl;
	}
}

void MainScene::setTopLayer(int _i){
  topLayer = _i;
}

void MainScene::loadSounds(){
	Sound* a = new Sound("assets/sound/grieves.wav");
	a->loop(true);
	a->gain(0.5f);
	sounds.push_back(a);

  Sound* b = new Sound("assets/sound/explosion.wav");
	b->loop(true);
	b->gain(0.5f);
	sounds.push_back(b);
}

MainScene::~MainScene(){
  //Sounds
	size_t s = sounds.size();
	for (size_t i = 0; i < s; i++) {
		delete sounds[i];
	}
	sounds.clear();

  //Layers
  int ls = layers.size();
	for (int i=0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = NULL;
	}
	layers.clear();

  delete canvas;
}
