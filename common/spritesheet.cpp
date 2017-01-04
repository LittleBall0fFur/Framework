#include "spritesheet.h"

Spritesheet::Spritesheet(){
  animateCounter = 0;
	startFrame = 0;
	endFrame = 0;
	spritesPerRow = 0;
	rows = 0;
	curSpriteId = 0;
	loop = true;
}

Spritesheet::~Spritesheet(){
  if(sprite != NULL)delete sprite; //segmentation fault on delete
}

void Spritesheet::setUpSpriteSheet(std::string _path, int _width, int _height, int _spritesPerRow, int _rows)
{
  if(sprite != NULL){
    sprite = new Sprite();
  	sprite->setSpriteScale(Vector2(_width, _height));
  	Vector2 uvSize = Vector2();
  	uvSize.x = 1.0f / (float)_spritesPerRow;
  	uvSize.y = 1.0f / (float)_rows;

  	sprite->setUvSize(uvSize);

  	spritesPerRow = _spritesPerRow;
  	rows = _rows;

    sprite->setupSprite(_path);
  }
}

void Spritesheet::animate(float _deltaTime, float _step)
{
	if(playing) {
		animateCounter += _deltaTime;
		if(animateCounter >= _step)
		{
			animateCounter = fmod(animateCounter, _step);
			curFrame++;
			if(curFrame > endFrame) curFrame = startFrame;
			if(curSpriteId != curFrame)
			{
				setSprite(curFrame);
        animateCounter = 0;
			}
		}
		if(!loop)
		{
			if(curFrame == endFrame){
        stop();
      }
		}
    else{
      if(curFrame == endFrame){
        curFrame = startFrame;
      }
    }
	}
}

void Spritesheet::play(){
  stop();
	playing = true;
	animateCounter = 0.0f;
	curFrame = startFrame;
	setSprite(startFrame);
}

void Spritesheet::stop(){
  playing = false;
  setSprite(endFrame);
}

void Spritesheet::setSprite(int _spriteId)
{
	if (_spriteId == curSpriteId) {
		return;
	}
	Vector2 offset = Vector2();
	if (_spriteId <= 0)
	{
		curSpriteId = 0;
		sprite->setUvOffset(offset);
		return;
	}

	int totalSprites = spritesPerRow * rows;
	if (_spriteId > totalSprites) {
		_spriteId = totalSprites;
	}

	int row = floor((float)_spriteId / (float)spritesPerRow);
	int placeInRow = (_spriteId % spritesPerRow);
	offset = Vector2(placeInRow * (1.0f / (float)spritesPerRow), row * (1.0f / (float)rows));

	sprite->setUvOffset(offset);
	curSpriteId = _spriteId;
	curFrame = _spriteId;
  std::cout<<&totalSprites<<std::endl;
}

void Spritesheet::setAnimateFrames(int _startFrame, int _endFrame)
{
	this->startFrame = _startFrame;
	this->endFrame = _endFrame;
	curFrame = _startFrame;
}
