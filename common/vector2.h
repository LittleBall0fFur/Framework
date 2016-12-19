#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	Vector2(float _x, float _y);
	Vector2();
//void Vector2::addForce(Vector2 force, Entity* entity);

	virtual ~Vector2();

	float x;
	float y;

private:

};

#endif
