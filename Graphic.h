#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "DxLib.h"
#include "Component.h"

typedef int DxGraphicHandle;

/*
 * Unique(�B��)�̉摜���Ǘ�����N���X
 */
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
	std::shared_ptr<Graphic> getGraphic(const std::string& name){ return graphics[name]; }
private:
	GraphicManager();
	void push(const std::string& path){
		graphics[path] = std::make_shared<Graphic>(LoadGraph(path.c_str()));
	}
	std::unordered_map<std::string, std::shared_ptr<Graphic>> graphics;
};

/*
 * �摜�Ǘ��N���X
 * �����̓���摜������
 * �X�V�A�`�ʂ��s��
 */
class Sprite;
class SpriteManager {
public:
	static SpriteManager& getInstance(){
		static SpriteManager instance;
		return instance;
	}
	void addSprite(std::shared_ptr<Sprite>& sprite){
		sprites.push_back(sprite);
	}
	void update();
	void draw();
private:
	SpriteManager(){}
	~SpriteManager(){}
	std::vector<std::weak_ptr<Sprite>> sprites;
};

/*
 * �O���t�B�b�N�N���X�̃R���|�[�l���g
 * �Q�[���I�u�W�F�N�g�����L����
 */
class Sprite : public Component{
public:
	virtual const std::string& getKeyString() const override {
		static std::string key = "Graphic";
		return key;
	}
	void set(std::shared_ptr<Graphic> graph, int zIndex = -1){
		this->graph = graph;
		this->zIndex = zIndex;
	}

	static std::shared_ptr<Sprite> create(){
		auto sprite = std::make_shared<Sprite>();
		SpriteManager::getInstance().addSprite(sprite);
		return sprite;
	}
	/*
	void setZIndex(int zIndex){ this->zIndex = zIndex; }
	void setGraph(std::shared_ptr<Graphic> graph){ this->graph = graph; }
	*/
	std::shared_ptr<Graphic> getGraph(){ return graph; }
	int getZIndex() const{ return zIndex; }
private:
	std::shared_ptr<Graphic> graph;
	int zIndex;	//�l���傫���قǎ�O�ɕ\�������
};
