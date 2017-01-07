#ifndef FACTORY_H
#define FACTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "ai.h"
#include "map.h"
#include "bullet.h"
#include "building.h"

class Factory
{
public:
	Factory();
	virtual ~Factory();

	Factory* getInstance();
	Map* mapInstance();
//	std::vector<Entity*>& getEnemies(){return enemies;};
//	std::vector<Entity*>& getBullets(){return bullets;};
//	std::vector<Entity*>& getBuildings(){return buildings;};

	int getWallet(){return wallet;};
	int getSpawnCounter(){return spawnCounter;};
	int getKillCounter(){return killCounter;};
	int getKost(int _kost);
	Entity* getObject(){return object;};

	void setCounter(int _i);
	void setSpawnCounter(int _i);
	void setObject(Entity* _entity);

	void removeBuilding(Building* _building);
	void removeBullet(Bullet* _bullet);
	void removeEnemy(Ai* _ai);

	void addBuilding(Building* _building);
	void addBullet(Bullet* _bullet);
	void addEnemy(Ai* _ai);

	void payKost();

private:
		Factory* factoryInstance;
		Entity* object;
		Map* map;
	//	private var map:Map;
		std::vector<Ai*>enemies;
		std::vector<Entity*> bullets;
		std::vector<Building*> buildings;
		int killCounter;
		int wallet;
		int kost;
		int spawnCounter;
};

#endif
