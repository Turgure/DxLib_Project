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
	push("data/image/eirin.jpg");	//TODO: csv�ŊǗ��B�t�@�C�����AZindex�A�n�b�V���̓o�^
	push("data/image/youmu.jpg");
}

void SpriteManager::update(){
}

void SpriteManager::draw(){
	typedef std::weak_ptr<Sprite> Spr;
	//�����ɂȂ����X�v���C�g���폜����B���
	sprites.erase(std::remove_if(begin(sprites), end(sprites), [](const Spr& spr){ return spr.expired(); }), sprites.end());
	//����\�[�g
	std::stable_sort(begin(sprites), end(sprites), [](const Spr& s1, const Spr& s2){ return s1.lock()->getZIndex() < s2.lock()->getZIndex(); });
	for(auto& sprite : sprites){
		auto position = sprite.lock()->getObject()->getComponentAs<Transform>("Transform");
		if(position){
			DrawGraph((int)position->getX(), (int)position->getY(), sprite.lock()->getGraph()->getHandle(), true);
			DrawFormatString((int)position->getX(), (int)position->getY()+10, GetColor(0,0,0), "%d", sprite.lock()->getZIndex()); 
		}
	}
	DxLib::ScreenFlip();
}
