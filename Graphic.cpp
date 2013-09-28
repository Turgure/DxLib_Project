#include <algorithm>
#include "DxLib.h"
#include "Transform.h"
#include "Graphic.h"
#include "Object.h"
using namespace std;

Graphic::Graphic(DxGraphicHandle handle):handle(handle){
}

Graphic::Graphic():handle(0){
}

Graphic::~Graphic(){
	DeleteGraph(handle);
}

GraphicManager::GraphicManager(){
	push("data/image/eirin.jpg");	//TODO: csvで管理。ファイル名、Zindex、ハッシュの登録
	push("data/image/eirin.jpg");
	push("data/image/youmu.jpg");
}

void GraphicManager::push(const string& path){
	Graphics[path] = make_shared<Graphic>(LoadGraph(path.c_str()));
}

void SpriteManager::update(){
}

void SpriteManager::draw(){
	typedef std::shared_ptr<Sprite> Spr;
	std::stable_sort(begin(sprites), end(sprites), [](const Spr& s1, const Spr& s2){ return s1->getZIndex() < s2->getZIndex(); });
	for(auto& sprite : sprites){
		// FIXME Vector2 is not component.
		auto position = sprite->getObject()->getComponentAs<Transform>("Transform");
		if(position){
			DrawGraph((int)position->getX(), (int)position->getY(), sprite->getGraph()->getHandle(), true);
			DrawFormatString((int)position->getX(), (int)position->getY()+10, GetColor(0,0,0), "%d", sprite->getZIndex()); 
		}
	}
	ScreenFlip();
}
