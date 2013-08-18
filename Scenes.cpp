#include "DxLib.h"
#include "Scenes.h"
#include "Graphic.h"
#include "Object.h"
using namespace std;

void SceneA::start(){
	for(int i = 0; i < 5; ++i){
		shared_ptr<CharaA> ca( new CharaA( Vector2(i*20,  0), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA1) ) );
		cas.push_back(ca);
		GraphicManager::getInstance().resister(ca);	//TODO: ˆêŠ‡‚Å‚Ü‚Æ‚ß‚é

		shared_ptr<CharaB> cb( new CharaB(Vector2(i*20, 20), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA2) ) );
		cbs.push_back(cb);
		GraphicManager::getInstance().resister(cb);
	}

	//enemies.push_back(cas);
	//enemies.push_back(cbs);
}
void SceneA::update(){
	cas[2]->update();
	cbs[3]->update();
}
void SceneA::terminate(){}

//TODO: ƒV[ƒ“‘JˆÚ
void SceneB::start(){}
void SceneB::update(){}
void SceneB::terminate(){}
