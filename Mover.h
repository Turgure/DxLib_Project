#pragma once
#include <list>
#include "Object.h"

class Mover{
public:
	void update();
	void add(std::shared_ptr<Object> obj);
	void remove(std::shared_ptr<Object> obj);
	void clear();
private:
	std::list<std::shared_ptr<Object>> movers;
};
