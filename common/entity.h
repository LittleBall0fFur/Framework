#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <glm/glm.hpp>
#include <common/vector2.h>

#include <common/texture.h>
#include <common/sprite.h>
#include <common/collision.h>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	Vector2 position;
	float rotation;
	Vector2 scale;

	void addChild(Entity* _child);
	void removeChild(Entity* _child);

	void addSprite(std::string path);

	void setPosition(Vector2 newPos);
	Vector2 getPosition(){return position;};
	Vector2 getScale(){return scale;};
	float getRotation(){return rotation;};

	const std::vector<Entity*>& getChildren() { return children; };

	Entity* getParent() { return parent; };
	Sprite* getSprite() { return sprite; };

	void setScale(Vector2 _scale);

	bool hitTestObject(Entity* entity);

	virtual void update(float deltaTime) = 0;

private:
	int guid;
	int nextGuid;

	Entity* parent;
	Sprite* sprite;
	std::vector<Entity*> children;
	Collision collider;
};

#endif
