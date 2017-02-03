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
	bool collidedWithPoint(Vector2 _mousePos, Vector2 _entityPos, Vector2 _textureSize);

private:

};

#endif
