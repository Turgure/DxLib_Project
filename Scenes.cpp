#include "DxLib.h"
#include "Scenes.h"
#include "Graphic.h"
#include "Transform.h"
#include "Object.h"
using namespace std;

void SceneA::start(){
	Object player;
	auto transform = make_shared<Transform>();
	transform->set(20, 0);
	player.addComponent(transform);

	auto sprite = make_shared<Sprite>();
	player.addComponent(sprite);
}
void SceneA::update(){
}
void SceneA::terminate(){}


//TODO: ƒV[ƒ“‘JˆÚ
void SceneB::start(){}
void SceneB::update(){}
void SceneB::terminate(){}
