#ifndef COLLISION_H
#define COLLISION_H

#include <common/vector2.h>
#include <common/texture.h>

class Collision
{
public:
	Collision();
	virtual ~Collision();

	bool collided(Vector2 aPos, Texture* aScale, Vector2 bPos, Texture* bScale);

private:

};

#endif
