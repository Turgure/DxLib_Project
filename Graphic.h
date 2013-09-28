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
 * �O���t�B�b�N�o�^�N���X
 * �v���O�����N�����ɓo�^
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
 * �O���t�B�b�N�Ǘ��N���X
 * �O���t�B�b�N�ꗗ��z��ŊǗ�
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
 * �O���t�B�b�N�N���X
 * UniqueGraphic�Ɠ����@�\
 */
//class Graphic : public UniqueGraphic{};

/*
 * �摜�Ǘ��N���X
 * �����̓���摜������
 * �X�V�A�`�ʂ��s��
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
