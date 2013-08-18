#pragma once
#include <vector>
#include <memory>
#include "BaseScene.h"
#include "Object.h"

class SceneA : public BaseScene{
	void start() override;
	void update() override;
	void terminate() override;

	//vector<vector<shared_ptr<Object>>> enemies;
	std::vector<std::shared_ptr<CharaA>> cas;
	std::vector<std::shared_ptr<CharaB>> cbs;
};

class SceneB : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;
};