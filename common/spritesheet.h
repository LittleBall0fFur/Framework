#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>

#include <common/sprite.h>
#include <common/vector2.h>

class Spritesheet
{
public:
	Spritesheet();
	virtual ~Spritesheet();

	void setUpSpriteSheet(std::string _path, int _width, int _height, int _spritesPerRow, int _rows);
	void setSprite(int _spriteId);
	void setAnimateFrames(int startFrame, int endFrame);
	void animate(float _deltaTime, float _step);

	void play();
	void stop();

	Sprite* getSprite() {return sprite;}

private:
	Sprite* sprite;

	int startFrame;
	int endFrame;
	int curFrame;
	int spritesPerRow;
	int rows;
	int curSpriteId;
	float animateCounter;

	bool playing;
	bool loop;
};

#endif
