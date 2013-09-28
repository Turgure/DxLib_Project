#pragma once
#include <list>
#include "Object.h"

class Mover{
public:
	static Mover& getInstance(){
		static Mover instance;
		return instance;
	}

	void update();
	void add(std::shared_ptr<Object> obj);
	void remove(std::shared_ptr<Object> obj);
	void clear();

private:
	Mover(){}

	std::list<std::shared_ptr<Object>> movers;
};
