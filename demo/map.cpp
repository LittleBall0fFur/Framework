#include "map.h"

Map::Map(): Entity(){
  this->addSprite("assets/level.tga");
  this->position = Vector2(900, 560);
}

void Map::update(float _deltaTime){

}

Map::~Map(){

}
