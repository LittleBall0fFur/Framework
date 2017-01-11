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

	int setFrame(int _f);
	void play();
	void stop();

	Sprite* getSprite() {return sprite;}
	int getCels(){return spritesPerRow;}
	int getRows(){return rows;}
	Vector2 getUvOffset(){return uvOffset;}

private:
	Sprite* sprite;

	int spritesPerRow;
	int rows;
	int frame;
	int f;

	bool playing;
	bool loop;

	float animateCounter;

	Vector2 uvOffset;
};

#endif
