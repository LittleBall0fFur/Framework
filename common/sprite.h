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
	void setupSpriteForSpriteSheet(const std::string& _filePath, float _uvWidth, float _uvHeight, int _filter, int _wrap);
	void setSpriteScale(Vector2 _scale);
	void setTextureSize(Vector2 _size);
	void setUvSize(Vector2 _size);
	void setUvOffset(Vector2 _offset);

	Vector2 getSpriteScale(){return scale;};
	Vector2 getUvOffset(){return uvOffset;};
	Vector2 getUvDim(){return uvdim;};

	Texture* getTexture(){return texture;};
	std::string getTextureName(){return texturename;}

private:
	Vector2 scale;
	Vector2 uvOffset;
	Vector2 textureSize;
	std::string texturename;
	Texture* texture;

	Vector2 uvdim;

	int wrap;
	int filter;
};

#endif
