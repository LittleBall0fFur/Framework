#include "collision.h"

Collision::Collision(){

}

Collision::~Collision(){

}

bool Collision::collided(Vector2 aPos, Texture* aTexture, Vector2 bPos, Texture* bTexture){

  float aLeft = aPos.x - (aTexture->getWidth() / 2);
  float aRight = aPos.x + (aTexture->getWidth() / 2);
  float aTop = aPos.y - (aTexture->getWidth() / 2);
  float aBot = aPos.y + (aTexture->getWidth() / 2);

  float bLeft = bPos.x - (bTexture->getWidth() / 2);
  float bRight = bPos.x + (bTexture->getWidth() / 2);
  float bTop = bPos.y - (bTexture->getWidth() / 2);
  float bBot = bPos.y + (bTexture->getWidth() / 2);

  if(aLeft >= bLeft && aLeft <= bRight && aTop >= bTop && aBot <= bBot) return true;
  return false;
}
