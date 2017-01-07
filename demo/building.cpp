#include "building.h"

Building::Building(): Entity(){
  healthSystem = new HealthSystem();
  kost = 0;
}

void Building::update(float _deltaTime){

}

Building::~Building(){
  delete healthSystem;
}

void Building::setKost(int _i){
  kost = _i;
}
