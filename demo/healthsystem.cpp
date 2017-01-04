#include "healthsystem.h"

HealthSystem::HealthSystem(){
 totalHealth = 0;
 curHealth = 0;
 damage = 0;
}

void HealthSystem::setHealth(int _health){
  totalHealth = _health;
  curHealth = totalHealth;
}

void HealthSystem::setDamage(int _damage){
  damage = _damage;
}

void HealthSystem::applyDamage(int _damage){
  curHealth -= _damage;
}

bool HealthSystem::deathCheck(){
  if(curHealth <= 0){
    curHealth = 0;
    return true;
  }
  else{
    return false;
  }
}

HealthSystem::~HealthSystem(){

}
