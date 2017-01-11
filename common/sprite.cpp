#include "sprite.h"

Sprite::Sprite(){
  scale = Vector2(1.0f,1.0f);
  uvdim = Vector2(1, 1);
  uvOffset = Vector2();
  textureSize = Vector2();
  this->texture = NULL;
}

Sprite::~Sprite(){
}

GLuint Sprite::setupSprite(const std::string& _filename)
{
	texturename = _filename;
  Texture* texture = new Texture();
  this->texture = texture;
  this->texture->loadTGA(texturename);
  return this->texture->getTextureBuffer();
}

void Sprite::setupSpriteForSpriteSheet(const std::string& _filePath, float _uvWidth, float _uvHeight, int _filter, int _wrap)
{
	texturename = _filePath;

	filter = _filter;
	wrap = _wrap;

	// 1.00000 = 1x1 spritesheet (basic sprite)
	// 0.50000 = 2x2 spritesheet
	// 0.25000 = 4x4 spritesheet
	// 0.12500 = 8x8 spritesheet
	// 0.06250 = 16x16 spritesheet
	// 0.03125 = 32x32 spritesheet
	uvdim.x = _uvWidth;
	uvdim.y = _uvHeight;
}

void Sprite::setSpriteScale(Vector2 _scale){
  scale = _scale;
}

void Sprite::setTextureSize(Vector2 _size)
{
	textureSize = _size;
}

void Sprite::setUvSize(Vector2 _size){
  uvdim = _size;
}

void Sprite::setUvOffset(Vector2 _offset){
  uvOffset = _offset;
}
