#include "factory.h"

Factory::Factory(){
  factoryInstance = NULL;
  object = NULL;
  map = NULL;

  killCounter = 0;
  wallet = 300;
  kost = 0;
  spawnCounter = 0;
}

Factory* Factory::getInstance(){
  if(factoryInstance == NULL){
  	factoryInstance = new Factory();
  }
  return factoryInstance;
}

Map* Factory::mapInstance(){
	if(map == NULL){
		map = new Map();
	}
	return map;
}

void Factory::addEnemy(Ai* _ai){
	enemies.push_back(_ai);
	spawnCounter++;
	mapInstance()->addChild(_ai);
}

void Factory::removeEnemy(Ai* _ai){
/*  std::vector< Entity* >::iterator it = enemies.begin();
  while (it != enemies.end()) {
    if ((*it)->guid == _ai->guid) {
      it = enemies.erase(it);
    } else {
      ++it;
    }
  }*/
	mapInstance()->removeChild(_ai);
	killCounter++;
	wallet += 5;
}

void Factory::addBullet(Bullet* _bullet){
	bullets.push_back(_bullet);
	mapInstance()->addChild(_bullet);
}

void Factory::removeBullet(Bullet* _bullet){
  /*std::vector< Entity* >::iterator it = bullets.begin();
  while (it != bullets.end()) {
    if ((*it)->guid == _bullet->guid) {
      it = bullets.erase(it);
    } else {
      ++it;
    }
  }*/
	mapInstance()->removeChild(_bullet);
}

void Factory::addBuilding(Building* _building){
	mapInstance()->addChild(_building);
	buildings.push_back(_building);
}

void Factory::removeBuilding(Building* _building){
  /*std::vector< Entity* >::iterator it = buildings.begin();
	while (it != buildings.end()) {
		if ((*it)->guid == _building->guid) {
			it = buildings.erase(it);
		} else {
			++it;
		}
	}*/
	mapInstance()->removeChild(_building);
}

void Factory::setObject(Entity* _entity){
	object = _entity;
}

void Factory::setSpawnCounter(int _i){
	spawnCounter = _i;
}

void Factory::setCounter(int _i){
	killCounter = _i;
}

int Factory::getKost(int _tKost){
	kost = _tKost;
	return kost;
}

void Factory::payKost(){
	if(wallet >= kost){
		wallet = wallet - kost;
	}
}

Factory::~Factory(){

}
