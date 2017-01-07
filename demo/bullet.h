#ifndef BULLET_H
#define BULLET_H

#include <common/entity.h>

class Bullet: public Entity
{
public:
	Bullet();
	virtual ~Bullet();

	void update(float _deltaTime);

private:

};

#endif
