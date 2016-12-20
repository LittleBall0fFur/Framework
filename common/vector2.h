#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	Vector2(float _x, float _y);
	Vector2();
//void Vector2::addForce(Vector2 force, Entity* entity);

	virtual ~Vector2();

	Vector2 moveTowards(Vector2 from, Vector2 to);
	Vector2 addForce(Vector2 force);

	float x;
	float y;

	Vector2& operator+=(const Vector2& rhs);
	Vector2 operator+(const Vector2& rhs) const;
	Vector2 operator*(const float rhs) const;

private:

};

#endif
