#pragma once
#include "Vector2.h"
#include "Graphic.h"

class Object{
public:
	Object(Vector2 position, Graphic graphic):position(position), graphic(graphic){
		is_exist = true;
	}
	virtual ~Object(){}
	virtual void update(){}

	bool isExist(){ return is_exist; }

	//int getGraphicId(){ return graphicId; }

	Vector2 position;
	Graphic graphic;
protected:
	bool is_exist;

	int graphicId;
};

class ObjectFactory{
public:
	template<class T>
	void add(Vector2 position, Graphic graphic);
};

class Charactor : public Object{
public:
	Charactor(Vector2 position, Graphic graphic):Object(position, graphic){}
	virtual void update() override;

protected:
	int hp;
};

class CharaA : public Charactor{
public:
	CharaA(Vector2 position, Graphic graphic, int hp);
	void initialize();
	void update() override;
};

class CharaB : public Charactor{
public:
	CharaB(Vector2 position, Graphic graphic, int hp);
	void initialize(int pattern);
	void update() override;

private:
	int pattern;
};
