#include "entity.h"

Entity::Entity(){
	nextGuid = 0;
	guid = nextGuid;
	nextGuid++;

	sprite = NULL;

  position =  Vector2(0.0f, 0.0f);
	rotation = 0.0f;
	scale = Vector2(1.0f, 1.0f);

	parent = NULL;
	spritesheet = new Spritesheet();
}

Entity::~Entity(){
	delete sprite;
	delete spritesheet;
}

void Entity::addChild(Entity* _child){
	if(_child->parent != NULL) {
		_child->parent->removeChild(_child);
	}
	_child->parent = this;
	this->children.push_back(_child);
}

void Entity::removeChild(Entity* _child)
{
	std::vector< Entity* >::iterator it = children.begin();
	while (it != children.end()) {
		if ((*it)->guid == _child->guid) {
			it = children.erase(it);
		} else {
			++it;
		}
	}
	//child->parent = this;
}

void Entity::addSprite(std::string _path)
{
	if (sprite != NULL)
	{
		delete sprite;
	}
	sprite = new Sprite();
	sprite->setupSprite(_path);
}

void Entity::addSpriteAsSpriteSheet(std::string _path, int _spriteWidth, int _spriteHeight, int _spritesPerRow, int _rows)
{
	spritesheet->setUpSpriteSheet(_path, _spriteWidth, _spriteHeight, _spritesPerRow, _rows);
	this->sprite = spritesheet->getSprite();
}

void Entity::setScale(Vector2 _scale){
	scale = _scale;
}

void Entity::setPosition(Vector2 _newPos){
	position = _newPos;
}

bool Entity::hitTestObject(Entity* _entity){
	return collider.collided(_entity->position, _entity->getSprite()->getTexture(), this->position, this->getSprite()->getTexture());
}
