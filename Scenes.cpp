#include "DxLib.h"
#include "Scenes.h"
#include "Graphic.h"
#include "Transform.h"
using namespace std;

void SceneA::start(){
	for(int i = 0; i < 10; ++i){
		auto obj = make_shared<Object>();
		auto transform = make_shared<Transform>();
		auto sprite = Sprite::create();
		
		transform->set(i*20, i*5);
		if(i < 5){
			sprite->set(GraphicManager::getInstance().getGraphic("data/image/youmu.jpg"), 1);
		} else {
			sprite->set(GraphicManager::getInstance().getGraphic("data/image/eirin.jpg"), 2);
		}

		obj->addComponent(transform);
		obj->addComponent(sprite);

		objects.push_back(obj);
	}
	
}
void SceneA::update(){
	for(auto& obj : objects){
		obj->update();
	}
}
void SceneA::terminate(){}


//TODO: ƒV[ƒ“‘JˆÚ
void SceneB::start(){}
void SceneB::update(){}
void SceneB::terminate(){}
