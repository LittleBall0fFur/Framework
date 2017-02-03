#include "button.h"

Button::Button(): Entity(){

}

void Button::update(float _deltaTime){

}

void Button::mouseOver(Vector2 _mousePos, float _deltaTime){
	flag = false;
	Vector2 textureSize;
	if(this->getSprite()->getTexture() != NULL){
		textureSize = Vector2(this->getSprite()->getTexture()->getWidth(), this->getSprite()->getTexture()->getHeight());
	}
	else{
		std::cout<<"setting size"<<std::endl;
		textureSize = Vector2(512, 512);
	}
	if(this->hitTestPoint(_mousePos, this->globalPosition, textureSize)){
		flag = true;
	}
}

Button::~Button(){

}
