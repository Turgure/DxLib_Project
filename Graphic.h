#pragma once

#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <memory>
#include "Component.h"
#include "Vector2.h"

typedef int graphic_handle;

/* 
 * グラフィック登録クラス
 * プログラム起動時に登録
 */
class UniqueGraphic : public Component{
public:
	UniqueGraphic(graphic_handle handle, int Zindex);
	UniqueGraphic(){}
	virtual ~UniqueGraphic(){}

	int getId(){ return id; }
	graphic_handle getHandle(){ return handle; }
	int getZindex(){ return Zindex; }
	virtual const std::string getKeyString() const {
		static std::string key = "Graphic";
		return key;
	}
protected:
	int id;
	graphic_handle handle;
	int Zindex;
};

/*
 * グラフィック管理クラス
 * グラフィック一覧を配列で管理
 */
class Object;
class UniqueGraphicManager{
public:
	static UniqueGraphicManager& getInstance(){
		static UniqueGraphicManager instance;
		return instance;
	}

	enum GraphicType{
		BACKGROUND,
		CHARA1,
		CHARA2,
		BULLET,
	};

	int getMaxZindex();

	UniqueGraphic getUniqueGraphic(GraphicType type){ return uniqueGraphics[type]; }

	/*
	int getId(int type);
	int getHandle(int id);
	int getZindex(int id);
	*/

private:
	UniqueGraphicManager();
	~UniqueGraphicManager();

	void push(std::string address, int Zindex);

	std::vector<UniqueGraphic> uniqueGraphics;
};

/*
 * グラフィッククラス
 * UniqueGraphicと同じ機能
 */
//class Graphic : public UniqueGraphic{};

/*
 * 画像管理クラス
 * 複数の同一画像も扱う
 * 更新、描写を行う
 */
class GraphicManager{
public:
	static GraphicManager& getInstance(){
		static GraphicManager instance;
		return instance;
	}

	void resister(std::shared_ptr<Object> obj);
	void update();
	void draw();

private:
	GraphicManager(){}

	//list<map<int id, Vector2 pos>>
	std::list<std::shared_ptr<Object>> graphics;
};

typedef UniqueGraphic Graphic;
