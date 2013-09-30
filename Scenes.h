#pragma once
#include <vector>
#include "BaseScene.h"
#include "Object.h"
#include "Map.h"

class SceneA : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;

	void createPlayer();
	void createObjects();

	std::vector<std::shared_ptr<Object>> objects;
	Object player;
	Map map;
};

class SceneB : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;
};
