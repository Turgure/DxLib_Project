#pragma once
#include <memory>
#include <vector>

class Object;
class Player;

class Map{
public:
	Map();
	void update(Player& player);
private:
	int current;
	static int mapdata[2][15][20];

	std::vector<std::shared_ptr<Object>> cells;
};
