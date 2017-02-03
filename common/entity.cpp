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
	spritesheet = NULL;
}

Entity::~Entity(){
	delete sprite;
	delete spritesheet;
	//deleteSpritebatch();
	//deleteLine();
}

void Entity::setGlobals(Vector2 pos, Vector2 scal, float rot)
{
	this->globalPosition = pos;
	this->globalScale = scal;
	this->globalRotation = rot;
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

/*void Entity::addLine(const std::string& _filename)
{
//	if(line != NULL)deleteLine();
	line = new Line(_filename);
}

void Entity::addLine(Line* _line)
{
	std::cout<<4<<std::endl;
	//if(line != NULL)deleteLine();
	std::cout<<5<<std::endl;
	line = new Line();
	std::cout<<6<<std::endl;
	*line = *_line;
	std::cout<<7<<std::endl;
}*/

void Entity::addSprite(std::string _path)
{
	if (sprite != NULL)
	{
		delete sprite;
	}
	sprite = new Sprite();
	sprite->setupSprite(_path);
}

void Entity::addSpriteAsSpriteSheet(std::string _path, int _spriteWidth, int _spriteHeight, int _cols, int _rows)
{
	//addSprite(_path);
	spritesheet = new Spritesheet();
	spritesheet->setUpSpriteSheet(_path, _spriteWidth, _spriteHeight, _cols, _rows);
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

bool Entity::hitTestPoint(Vector2 _mousePos, Vector2 _entityWorldPos, Vector2 _textureSize){
	return collider.collidedWithPoint(_mousePos, _entityWorldPos, _textureSize);
}

void Entity::addGrid(const std::string& _filePath, int _u, int _v, int _collums, int _rows, int _cellSizeX, int _cellSizeY){
	deleteSpritebatch();
	for (int y = 0; y < _rows; y++) {
		for (int x = 0; x < _collums; x++) {
			Sprite* s = new Sprite();
			//s->useCulling(1); implement culling after grid is succesfull
			s->spritePosition.x = x * _cellSizeX;
			s->spritePosition.y = y * _cellSizeY;
			float uvwidth = 1.0f / _u;
			float uvheight = 1.0f / _v;
			s->setupSpriteForSpriteSheet(_filePath, uvwidth, uvheight, 3, 1); // this could cause a problem see: rt2d sprite class
			spritebatch.push_back(s);
		}
	}
	std::cout << "grid added: " << spritebatch.size() << " sprites." << std::endl;
}

void Entity::deleteSpritebatch() {
	int s = spritebatch.size();
	for (int i = 0; i < s; i++) {
		delete spritebatch[i];
	}
	spritebatch.clear();
};
