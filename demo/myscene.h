#ifndef MYSCENE_H
#define MYSCENE_H

#include <common/entity.h>
#include <common/scene.h>
#include <common/vector2.h>

#include "ai.h"

class Myscene: public Scene
{
public:
	Myscene();
	virtual ~Myscene();
	void update(float _deltaTime);

private:
	Entity* block;
	Entity* block2;
	Vector2 vector;
};

#endif
