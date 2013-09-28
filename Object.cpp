#include "Object.h"
#include "Mover.h"
using namespace std;

void Charactor::update(){
	if(status.hp <= 0) is_exist = false;
}


CharaA::CharaA(){
	status.hp = 1;
	//graphicId = UniqueGraphicManager::getInstance().getId(UniqueGraphicManager::CHARA1);
}

void CharaA::update(){
	Charactor::update();
	position += Vector2(1, 0);
}


CharaB::CharaB(){
	status.hp = 1;
	//graphicId = UniqueGraphicManager::getInstance().getId(UniqueGraphicManager::CHARA2);
}

void CharaB::update(){
	Charactor::update();
	position += Vector2(0, 1);
}
