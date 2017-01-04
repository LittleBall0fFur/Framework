#ifndef BUILDING_H
#define BUILDING_H

#include "healthsystem.h"

class Building: public Entity
{
public:
	Building();
	virtual ~Building();

private:
	Healthsystem* healthsystem;
};

#endif
