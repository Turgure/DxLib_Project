#include "DxLib.h"
#include "Scenes.h"
#include "Graphic.h"
#include "Mover.h"
using namespace std;

void SceneA::start(){
	obj_factory.add<CharaA>( Vector2(20, 0), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA1), 1 );

	shared_ptr<CharaB> cb( new CharaB(Vector2(40, 20), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA2), 1) );
	GraphicManager::getInstance().resister(cb);
	Mover::getInstance().add(cb);
}
void SceneA::update(){
	Mover::getInstance().update();
}
void SceneA::terminate(){}

//TODO: ÉVÅ[ÉìëJà⁄
void SceneB::start(){}
void SceneB::update(){}
void SceneB::terminate(){}
