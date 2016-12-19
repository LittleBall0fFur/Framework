#include "sprite.h"

Sprite::Sprite(){
  scale = Vector2(1.0f,1.0f);
  uvOffset = Vector2();
  textureSize = Vector2();
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

void Sprite::setSpriteScale(Vector2 _scale){
  scale = _scale;
}

void Sprite::setTextureSize(Vector2 size)
{
	this->textureSize = size;
}
