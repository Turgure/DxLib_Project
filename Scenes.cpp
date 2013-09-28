#include "DxLib.h"
#include "Scenes.h"
#include "Graphic.h"
#include "Mover.h"
using namespace std;

void SceneA::start(){
	/*shared_ptr<CharaA> ca = */createCharaA(20, 0);
	//Mover::getInstance().add(ca);
	//GraphicManager::getInstance().resister(ca);

	/*shared_ptr<CharaB> cb = */createCharaB(60, 0);
	//Mover::getInstance().add(cb);
	//GraphicManager::getInstance().resister(cb);

	/*
	shared_ptr<CharaB> cb( new CharaB(Vector2(40, 20), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA2), Charactor::status) );
	GraphicManager::getInstance().resister(cb);
	Mover::getInstance().add(cb);
	*/
}
void SceneA::update(){
	Mover::getInstance().update();
}
void SceneA::terminate(){}

shared_ptr<CharaA> SceneA::createCharaA(double x, double y){
	//shared_ptr<CharaA> ca( new CharaA() );
	auto ca = make_shared<CharaA>();
	ca->position.set(x, y);
	Graphic sprite = UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA1);
	ca->graphic = sprite;
		
	Mover::getInstance().add(ca);
	GraphicManager::getInstance().resister(ca);
		
	return ca;
}
shared_ptr<CharaB> SceneA::createCharaB(double x, double y){
	shared_ptr<CharaB> cb( new CharaB() );
	if(cb){
		cb->position.set(x, y);
		Graphic sprite = UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA2);
		cb->graphic = sprite;
		
		Mover::getInstance().add(cb);
		GraphicManager::getInstance().resister(cb);

		return cb;
	}

	return nullptr;
}

//TODO: ÉVÅ[ÉìëJà⁄
void SceneB::start(){}
void SceneB::update(){}
void SceneB::terminate(){}
