#pragma once
#include <unordered_map>
#include "Component.h"
#include "Vector2.h"
#include "Graphic.h"

class Object{
public:
	Object(){
		//is_exist = true;
	}
	virtual ~Object(){}
	void update(){
		for(auto& i : components){
			i.second->update();
		}
	}

	//bool isExist(){ return is_exist; }

	void addComponent(std::shared_ptr<Component>& component){
		components[component->getKeyString()] = component;
	}
	bool hasComponent(std::string key){
		return components.find(key) != components.end();
	}
	std::shared_ptr<Component> getComponent(std::string key){
		auto com = components.find(key);
		return com != components.end() ? com->second : std::shared_ptr<Component>(nullptr);
	}
	template<class T>
	std::shared_ptr<T> getComponentAs(std::string key){
		auto com = getComponent(key);
		return std::dynamic_pointer_cast<T> com;
	}
protected:
	//bool is_exist;
	std::unordered_map<std::string, std::shared_ptr<Component>> components;
};

class Charactor : public Object{
protected:
	struct Status{
		int hp;
		int str;
		int def;

		Status getData(){}
	} status;

public:
	Charactor(){}
	void update() override;
};

class CharaA : public Charactor{
public:
	CharaA();
	void initialize();
	void update() override;
};

class CharaB : public Charactor{
public:
	CharaB();
	void initialize(int pattern);
	void update() override;

private:
	int pattern;
};
