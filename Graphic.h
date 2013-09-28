#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Component.h"

typedef int DxGraphicHandle;

class Graphic{
public:
	Graphic(DxGraphicHandle handle);
	Graphic();
	virtual ~Graphic();
	DxGraphicHandle getHandle(){ return handle; }
protected:
	DxGraphicHandle handle;
};

/*
 * �O���t�B�b�N�Ǘ��N���X
 * �O���t�B�b�N�ꗗ��z��ŊǗ�
 */
class GraphicManager{
public:
	static GraphicManager& getInstance(){
		static GraphicManager instance;
		return instance;
	}
	std::shared_ptr<Graphic> getGraphic(const std::string& name){ return Graphics[name]; }
private:
	GraphicManager();
	void push(const std::string& path);
	std::unordered_map<std::string, std::shared_ptr<Graphic>> Graphics;
};

class Sprite : public Component {
public:
	void setZIndex(int zIndex){ this->zIndex = zIndex; }
	int getZIndex() const{ return zIndex; }
	virtual const std::string& getKeyString() const override {
		static std::string key = "Graphic";
		return key;
	}
	void setGraph(std::shared_ptr<Graphic> graph){ this->graph = graph; }
	std::shared_ptr<Graphic> getGraph(){ return graph; }
private:
	std::shared_ptr<Graphic> graph;
	int zIndex;
};

/*
 * �摜�Ǘ��N���X
 * �����̓���摜������
 * �X�V�A�`�ʂ��s��
 */
class SpriteManager {
public:
	static SpriteManager& getInstance(){
		static SpriteManager instance;
		return instance;
	}
	void addSprite(std::shared_ptr<Sprite> sprite){
		sprites.push_back(sprite);
	}
	void update();
	void draw();
private:
	SpriteManager(){}
	std::vector<std::shared_ptr<Sprite>> sprites;
};
