#ifndef MAP_H
#define MAP_H

#include <common/entity.h>

class Map: public Entity
{
public:
	Map();
	virtual ~Map();
	void update(float _deltaTime);

private:

};

#endif
