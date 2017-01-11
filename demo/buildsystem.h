#ifndef BUILDSYSTEM_H
#define BUILDSYSTEM_H

#include "building.h"
#include "factory.h"

class BuildSystem
{
public:
	BuildSystem();
	virtual ~BuildSystem();

	void isClicked(Building* _building);

	void setInt(int _i);
	int getInt(){return click;};

	void building();

private:
	int click;

	Factory factory;

};

#endif
