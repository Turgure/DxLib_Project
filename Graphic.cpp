#include "DxLib.h"
#include "Graphic.h"
#include "Object.h"
using namespace std;

UniqueGraphic::UniqueGraphic(graphic_handle handle, int Zbuffer):handle(handle), Zbuffer(Zbuffer){
	static int i;
	id = ++i;
}



UniqueGraphicManager::UniqueGraphicManager(){
	push("image/eirin.jpg", 0);
	push("image/eirin.jpg", 1);
	push("image/youmu.jpg", 2);
}

UniqueGraphicManager::~UniqueGraphicManager(){
	for(auto& g : uniqueGraphics){
		DeleteGraph(g.getHandle());
	}
}

void UniqueGraphicManager::push(string address, int Zbuffer){
	graphic_handle handle = LoadGraph(address.c_str());
	uniqueGraphics.push_back( UniqueGraphic(handle, Zbuffer) );
}

int UniqueGraphicManager::getMaxZbuffer(){
	int maxZbuffer = 0;
	for(auto& g : uniqueGraphics){
		if(maxZbuffer < g.getZbuffer()) maxZbuffer = g.getZbuffer();
	}
	return maxZbuffer;
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
	int maxZbuffer = UniqueGraphicManager::getInstance().getMaxZbuffer();
	for(int i = maxZbuffer; i >= 0; --i){
		for(auto& obj : graphics){
			if(obj->graphic.getZbuffer() == i){
				DrawGraph(obj->position.getX(), obj->position.getY(), obj->graphic.getHandle(), true);
				DrawFormatString(obj->position.getX(), obj->position.getY()+10, GetColor(0,0,0), "%d", obj->graphic.getZbuffer()); 
			}
		}
	}
}
