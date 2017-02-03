#include "collision.h"

Collision::Collision(){

}

Collision::~Collision(){

}
//Box Colliders
bool Collision::collided(Vector2 aPos, Texture* aTexture, Vector2 bPos, Texture* bTexture){

  float aLeft = aPos.x - (aTexture->getWidth() / 2);
  float aRight = aPos.x + (aTexture->getWidth() / 2);
  float aTop = aPos.y - (aTexture->getWidth() / 2);
  float aBot = aPos.y + (aTexture->getWidth() / 2);

  float bLeft = bPos.x - (bTexture->getWidth() / 2);
  float bRight = bPos.x + (bTexture->getWidth() / 2);
  float bTop = bPos.y - (bTexture->getWidth() / 2);
  float bBot = bPos.y + (bTexture->getWidth() / 2);

  if(aLeft >= bLeft && aLeft <= bRight && aTop >= bTop && aBot <= bBot && aRight >= aLeft) return true;
  return false;
}
  //button collider
bool Collision::collidedWithPoint(Vector2 _mousePos, Vector2 _entityWorldPos, Vector2 _textureSize){
  float left = _entityWorldPos.x - (_textureSize.x / 2);
  float right = _entityWorldPos.x + (_textureSize.x / 2);
  float top = _entityWorldPos.y - (_textureSize.y / 2);
  float bot = _entityWorldPos.y + (_textureSize.y / 2);

  if(_mousePos.x < right && _mousePos.x > left && _mousePos.y > top && _mousePos.y < bot)return true;
  return false;
}
