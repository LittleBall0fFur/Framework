#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <common/texture.h>
#include <common/vector2.h>

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();

	GLuint setupSprite(const std::string& filename);
	void setSpriteScale(Vector2 _scale);
	void setTextureSize(Vector2 size);

	Vector2 getSpriteScale(){return scale;};
	Vector2 getUvOffset(){return uvOffset;};

	Texture* getTexture(){return texture;};
private:
	Vector2 scale;
	Vector2 uvOffset;
	Vector2 textureSize;
	std::string texturename;
	Texture* texture;
};

#endif
