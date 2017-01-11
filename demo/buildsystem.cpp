#include "buildsystem.h"

BuildSystem::BuildSystem(){
 click = 0;
}

void BuildSystem::isClicked(Building* _building){
	if(factory.getInstance()->getWallet() < factory.getInstance()->getKost(_building->getKost())){
		click = 1;
	}
	if(factory.getInstance()->getWallet() >= factory.getInstance()->getKost(_building->getKost())){
		factory.getInstance()->getKost(_building->getKost());
		factory.getInstance()->payKost();
		factory.getInstance()->setObject(_building);
		factory.getInstance()->mapInstance()->addChild(_building);
		factory.getInstance()->addBuilding(_building);
	}
}

void BuildSystem::building(){
	if (factory.getInstance()->getObject() != NULL) {
		//factory.getInstance()->getObject()->position.x = factory.getInstance()->mapInstance()->parent->getCamera()->getMousePosition().x + 20;
	//	factory.getInstance()->getObject()->position.y = factory.getInstance()->mapInstance()->parent->getCamera()->getMousePosition().y - 20;
	}
}

void BuildSystem::setInt(int _i){
	click = _i;
}

BuildSystem::~BuildSystem(){

}
