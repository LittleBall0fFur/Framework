#include "spritesheet.h"

Spritesheet::Spritesheet(){
  animateCounter = 0;
	spritesPerRow = 0;
	rows = 0;
	loop = true;
  sprite = NULL;
  f = 0;
  uvOffset = Vector2(0,0);
}

Spritesheet::~Spritesheet(){
  if(sprite != NULL) delete sprite; //segmentation fault on delete
}

void Spritesheet::setUpSpriteSheet(std::string _path, int _width, int _height, int _spritesPerRow, int _rows)
{
  if(sprite == NULL){
    sprite = new Sprite();
    sprite->setupSprite(_path);
  	sprite->setSpriteScale(Vector2(_width, _height));
    sprite->setUvSize(Vector2(_spritesPerRow, _rows));
  	spritesPerRow = _spritesPerRow;
  	rows = _rows;
    sprite->setupSpriteForSpriteSheet(_path, 1/sprite->getUvDim().x, 1/sprite->getUvDim().y, 3, 1);
  }
}

void Spritesheet::animate(float _deltaTime, float _step){
  animateCounter += _deltaTime;
	if (animateCounter >= _step) {
    this->setFrame(frame);
		frame++;
    animateCounter = 0;
	}
}

int Spritesheet::setFrame(int _f)
{
	int width = 1.0f / sprite->getUvDim().x;
	int height = 1.0f / sprite->getUvDim().y;

	if (_f >= width*height) {
		frame = 0;
    animateCounter = 0;
		uvOffset.x = 0;
		uvOffset.y = 0;

		return frame;
	}

	int ypos = _f/width;
	int xpos = _f%width;

	uvOffset.y = ypos * sprite->getUvDim().y;
  uvOffset.x = xpos * sprite->getUvDim().x;

	frame = _f;

	return frame;
}
