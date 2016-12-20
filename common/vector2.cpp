#include "vector2.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

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

Vector2 Vector2::addForce(Vector2 force){
  Vector2 acceleration = Vector2(0,0);
  Vector2 velocity = Vector2(0,0);

  acceleration += force;
  velocity += acceleration;
  std::cout<< force.y << std::endl;
  return velocity;
}

Vector2 Vector2::moveTowards(Vector2 from, Vector2 to){
  float newX = to.x - from.x;
  float newY = to.y - from.y;
  Vector2 newPos = Vector2(newX, newY);
  return newPos;
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return Vector2(x+rhs.x, y+rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const
{
	return Vector2(x*rhs, y*rhs);
}
