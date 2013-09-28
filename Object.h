#pragma once
#include "Vector2.h"
#include "Graphic.h"

class Object{
public:
	Object(){
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

class Charactor : public Object{
//protected:
public:
	struct Status{
		Status(int hp, int str, int def):hp(hp), str(str), def(def){}
		int hp;
		int str;
		int def;
	} status;

public:
	Charactor():status(1,0,0){}
	virtual void update() override;
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
