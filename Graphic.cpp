#include "DxLib.h"
#include "Graphic.h"
#include "Object.h"
using namespace std;

UniqueGraphic::UniqueGraphic(graphic_handle handle, int Zindex):handle(handle), Zindex(Zindex){
	static int i;
	id = ++i;
}



UniqueGraphicManager::UniqueGraphicManager(){
	push("data/image/eirin.jpg", 0);	//TODO: csvで管理。ファイル名、zバッファ、ハッシュの登録
	push("data/image/eirin.jpg", 1);
	push("data/image/youmu.jpg", 2);
}

UniqueGraphicManager::~UniqueGraphicManager(){
	for(auto& g : uniqueGraphics){
		DeleteGraph(g.getHandle());
	}
}

void UniqueGraphicManager::push(string address, int Zindex){
	graphic_handle handle = LoadGraph(address.c_str());
	uniqueGraphics.push_back( UniqueGraphic(handle, Zindex) );
}

int UniqueGraphicManager::getMaxZindex(){
	int maxZindex = 0;
	for(auto& g : uniqueGraphics){
		if(maxZindex < g.getZindex()) maxZindex = g.getZindex();
	}
	return maxZindex;
}



void GraphicManager::resister(std::shared_ptr<Object> obj){
	graphics.push_back(obj);
}

void GraphicManager::update(){
	for(auto& obj : graphics){
		obj->update();
	}
}

void GraphicManager::draw(){
	int maxZindex = UniqueGraphicManager::getInstance().getMaxZindex();
	for(int i = maxZindex; i >= 0; --i){
		for(auto& obj : graphics){
			if(obj->graphic.getZindex() == i){
				DrawGraph(obj->position.getX(), obj->position.getY(), obj->graphic.getHandle(), true);
				DrawFormatString(obj->position.getX(), obj->position.getY()+10, GetColor(0,0,0), "%d", obj->graphic.getZindex()); 
			}
		}
	}
	ScreenFlip();
}
