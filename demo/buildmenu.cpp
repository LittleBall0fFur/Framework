#include "buildmenu.h"

BuildMenu::BuildMenu(): HudElement(){
 setupButtons();
}

void BuildMenu::update(float _deltaTime){
  muffinButton->mouseOver(mousePos,_deltaTime);
  onClick();
}

void BuildMenu::setupButtons(){
  muffinButton = new Button();
  muffinButton->addSprite("assets/the_muffin_button.tga");
  muffinButton->setScale(Vector2(0.2, 0.2));
  this->addChild(muffinButton);
  this->buttons.push_back(muffinButton);
}

void BuildMenu::updateMousePos(Vector2 _mousePos){
  mousePos = _mousePos;
}

void BuildMenu::onClick(){
  if(muffinButton->getMouseOver()){
    if(input->getMouseDown(0)){
      std::cout<<"click"<<std::endl;
      Ai* muffin = new Ai();
      muffin->addSprite("assets/muffin.tga");
      muffin->position = Vector2(rand()%1920,rand()%1080);
      Vector2 scale = Vector2(rand()%100, rand()%100);
      if(scale.x <= 10)scale.x = 100;
      muffin->setScale(Vector2(scale.x/100, scale.x/100));
      this->getParent()->getParent()->addChild(muffin);
      this->muffins.push_back(muffin);
    }
  }
}

BuildMenu::~BuildMenu(){
  	int b = buttons.size();
  	for (int i = 0; i < b; i++) {
  		delete buttons[i];
  	}
  	buttons.clear();

    int m = muffins.size();
  	for (int i = 0; i < m; i++) {
  		delete muffins[i];
  	}
  	muffins.clear();
}
