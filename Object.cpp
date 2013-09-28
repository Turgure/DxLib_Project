#include "Object.h"
#include "Mover.h"
using namespace std;

template<class T>
void ObjectFactory::add(Vector2 position, Graphic graphic){
	shared_ptr<T> obj( new T(position, graphic) );

	//GraphicManager::getInstance().resister(obj);
	//Mover::getInstance().add(obj);
}


void Charactor::update(){
	if(hp <= 0) is_exist = false;
}


CharaA::CharaA(Vector2 position, Graphic graphic, int hp):Charactor(position, graphic){
	this->hp = 1/*hp*/;
	//graphicId = UniqueGraphicManager::getInstance().getId(UniqueGraphicManager::CHARA1);
}

void CharaA::update(){
	Charactor::update();
	position += Vector2(1, 0);
}


CharaB::CharaB(Vector2 position, Graphic graphic, int hp):Charactor(position, graphic){
	this->hp = 1/*hp*/;
	//graphicId = UniqueGraphicManager::getInstance().getId(UniqueGraphicManager::CHARA2);
}

void CharaB::update(){
	Charactor::update();
	position += Vector2(0, 1);
}
