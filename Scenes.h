#pragma once
#include <vector>
#include "BaseScene.h"

class SceneA : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;
};

class SceneB : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;
};
