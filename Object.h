#pragma once
#include "Vector2.h"
#include "Graphic.h"

class Object{
public:
	Object(Vector2 pos, Graphic g):position(pos), graphic(g){}
	virtual ~Object(){}
	virtual void update(){}
	//int getGraphicId(){ return graphicId; }

	Vector2 position;
	Graphic graphic;
protected:
	int graphicId;
};

class CharaA : public Object{
public:
	CharaA(Vector2 pos, Graphic g);

	void update() override;
};

class CharaB : public Object{
public:
	CharaB(Vector2 pos, Graphic g);

	void update() override;
};
