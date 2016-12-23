#ifndef AI_H
#define AI_H

#include <common/entity.h>

class Ai: public Entity
{
public:
	Ai();
	virtual ~Ai();
	virtual void update(float deltaTime);

private:

};

#endif
