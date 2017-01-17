#include "headsupdisplay.h"

HeadsUpDisplay::HeadsUpDisplay(): Entity(){
  std::cout << "################ new HUD ################" << std::endl;
//  this->addSprite("assets/default.tga");

}

HeadsUpDisplay::~HeadsUpDisplay(){

}

void HeadsUpDisplay::update(float _deltaTime){
  
}

void HeadsUpDisplay::setScreenOverlay(bool _overlay){
  overlay = _overlay;
}

//TO-DO implement ancherpoints, layers
