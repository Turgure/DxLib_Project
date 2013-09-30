#pragma once
#include <memory>
#include <vector>

class Object;

class Map{
public:
	Map();
private:
	static int mapdata[2][15][20];

	std::vector<std::shared_ptr<Object>> map;
};
