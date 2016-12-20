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

Vector2 Vector2::addForce(Vector2 force){
  Vector2 acceleration = acceleration + force;
  Vector2 velocity = velocity + acceleration;
  return velocity;
}

Vector2 Vector2::moveTowards(Vector2 _start, Vector2 _target, float speed){
		float _x = _start.x - _target.x;
		float _y = _start.y - _target.y;
		float c = this->distancePoints(_start, _target);
		return Vector2(speed * _x / c, speed * _y / c);
}

float Vector2::distancePoints(Vector2 _a, Vector2 _b){
		float _x = _a.x - _b.x;
		float _y = _a.y - _b.y;
		return sqrt((_x * _x) + (_y * _y));
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
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
