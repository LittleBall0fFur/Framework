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
//#include <common/line.h>

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
	void deleteSpritebatch();

	void addSprite(std::string path);
	void addGrid(const std::string& _filePath, int _u, int _v, int _collums, int _rows, int _cellSizeX, int _cellSizeY);
	void addSpriteAsSpriteSheet(std::string _path, int _spriteWidth, int _spriteHeight, int _spritesPerRow, int _rows);
	//void addLine(Line* _line);
	//void addLine(const std::string& _filename);

	void setPosition(Vector2 _newPos);
	void setGlobals(Vector2 pos, Vector2 scal, float rot);
	Vector2 getPosition(){return position;}
	Vector2 getScale(){return scale;}
	float getRotation(){return rotation;}
	Spritesheet* getSpriteSheet(){return spritesheet;}
	const std::vector<Entity*>& getChildren(){return children;}
	std::vector<Sprite*> getSpriteBatch(){return spritebatch;}
	//Line* getLine(){return line;}

	Entity* getParent() { return parent; };
	Sprite* getSprite() { return sprite; };

	void setScale(Vector2 _scale);

	bool hitTestObject(Entity* _entity);
	bool hitTestPoint(Vector2 _mousePos, Vector2 _entityWorldPos, Vector2 _textureSize);

	virtual void update(float _deltaTime) = 0;

	//void drawLine(Vector2 _from, Vector2 _to);

	int guid;

	Vector2 globalScale;
	Vector2 globalPosition;
	float globalRotation;

protected:
std::vector<Sprite*> spritebatch;

private:
	int nextGuid;

	Entity* parent;
	Sprite* sprite;
	Spritesheet* spritesheet;

	std::vector<Entity*> children;
	Collision collider;

	/*Line* line;
	void deleteLine() {
		if (line != NULL) {
			delete line;
			line = NULL;
		}
	};*/
};

#endif
