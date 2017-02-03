#include "canvas.h"

Canvas::Canvas(): Entity(){
  buildMenu = new BuildMenu();
  buildMenu->position.x = 1920/2;
  buildMenu->position.y = 1080/2;
  this->addChild(buildMenu);

}

void Canvas::update(float _deltaTime){
  buildMenu->updateMousePos(mousePos);
}

void Canvas::getCursorPos(Vector2 _mousePos){
  mousePos = _mousePos;
}

void Canvas::setInput(Input* _input){
  buildMenu->input = _input;
}

Canvas::~Canvas(){

}
