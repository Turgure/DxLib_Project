#pragma once
#include <memory>
#include <vector>

class Transform;
class Object;

class Map{
public:
	Map();
	void update(Transform& center);
	static int mapdata[40][40];

private:
	std::vector<std::shared_ptr<Object>> map;
};
