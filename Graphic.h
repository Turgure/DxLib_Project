#pragma once

#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <memory>
#include "Vector2.h"

typedef int graphic_handle;

class UniqueGraphic{
public:
	UniqueGraphic(graphic_handle handle, int Zbuffer);
	UniqueGraphic(){}
	virtual ~UniqueGraphic(){}

	int getId(){ return id; }
	graphic_handle getHandle(){ return handle; }
	int getZbuffer(){ return Zbuffer; }

protected:
	int id;
	graphic_handle handle;
	int Zbuffer;
};

class Object;
class UniqueGraphicManager{
public:
	static UniqueGraphicManager& getInstance(){
		static UniqueGraphicManager g_mng;
		return g_mng;
	}

	enum GraphicType{
		BACKGROUND,
		CHARA1,
		CHARA2,
		BULLET,
	};

	int getMaxZbuffer();

	UniqueGraphic getUniqueGraphic(GraphicType type){ return uniqueGraphics[type]; }

	/*
	int getId(int type);
	int getHandle(int id);
	int getZbuffer(int id);
	*/

private:
	UniqueGraphicManager();
	~UniqueGraphicManager();

	void push(std::string address, int Zbuffer);

	std::vector<UniqueGraphic> uniqueGraphics;
};

//class Graphic : public UniqueGraphic{};

class GraphicManager{
public:
	void resister(std::shared_ptr<Object> obj);
	void update();
	void draw();

private:
	//list<map<int id, Vector2 pos>>
	std::list<std::shared_ptr<Object>> graphics;
};

typedef UniqueGraphic Graphic;
