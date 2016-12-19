#include "vector2.h"

Vector2::Vector2(float _x, float _y){
  x = _x;
  y = _y;
}

Vector2::Vector2(){
  x = 0;
  y = 0;
}

Vector2::~Vector2(){

}

/**void Vector2::addForce(Vector2 force, Entity* entity){
  acceleration += force;
  velocity += acceleration;
  entity->position += velocity;
}*/
