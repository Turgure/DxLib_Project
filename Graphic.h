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
 * グラフィック管理クラス
 * グラフィック一覧を配列で管理
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
 * 画像管理クラス
 * 複数の同一画像も扱う
 * 更新、描写を行う
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
