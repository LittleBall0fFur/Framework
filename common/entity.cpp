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
}

Entity::~Entity(){
	delete sprite;
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

void Entity::setScale(Vector2 _scale){
	scale = _scale;
}

void Entity::setPosition(Vector2 newPos){
	position = newPos;
}

bool Entity::hitTestObject(Entity* entity){
	return collider.collided(entity->position, entity->getSprite()->getTexture(), this->position, this->getSprite()->getTexture());
}
