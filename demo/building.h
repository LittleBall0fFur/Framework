#ifndef BUILDING_H
#define BUILDING_H

#include <common/entity.h>

#include <demo/healthsystem.h>

class Building: public Entity
{
public:
	Building();
	virtual ~Building();

	void update(float _deltaTime);
	void setKost(int _i);
	int getKost(){return kost;};

private:
	HealthSystem* healthSystem;

	int kost;
};

#endif
