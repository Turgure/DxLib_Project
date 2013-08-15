#include "Object.h"

CharaA::CharaA(Vector2 pos, Graphic g):Object(pos, g){
		//graphicId = UniqueGraphicManager::getInstance().getId(UniqueGraphicManager::CHARA1);
}

void CharaA::update(){
	position += Vector2(1, 0);
}

CharaB::CharaB(Vector2 pos, Graphic g):Object(pos, g){
	//graphicId = UniqueGraphicManager::getInstance().getId(UniqueGraphicManager::CHARA2);
}

void CharaB::update(){
	position += Vector2(0, 1);
}
