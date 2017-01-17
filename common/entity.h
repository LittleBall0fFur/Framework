#ifndef ENTITY_H
#define ENTITY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//#include <glm/glm.hpp>

#include <common/texture.h>
#include <common/sprite.h>
#include <common/spritesheet.h>
#include <common/collision.h>
#include <common/vector2.h>

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
	void addSpriteAsSpriteSheet(std::string _path, int _spriteWidth, int _spriteHeight, int _spritesPerRow, int _rows);

	void setPosition(Vector2 _newPos);
	Vector2 getPosition(){return position;}
	Vector2 getScale(){return scale;}
	float getRotation(){return rotation;}
	Spritesheet* getSpriteSheet(){return spritesheet;}
	const std::vector<Entity*>& getChildren(){return children;}

	Entity* getParent() { return parent; };
	Sprite* getSprite() { return sprite; };

	void setScale(Vector2 _scale);

	bool hitTestObject(Entity* _entity);

	virtual void update(float _deltaTime) = 0;

	int guid;
private:
	int nextGuid;

	Entity* parent;
	Sprite* sprite;
	Spritesheet* spritesheet;

	std::vector<Entity*> children;
	Collision collider;
};

#endif
