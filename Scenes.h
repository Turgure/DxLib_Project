#pragma once
#include <vector>
#include <memory>
#include "BaseScene.h"
#include "Object.h"

class SceneA : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;

	ObjectFactory obj_factory;
};

class SceneB : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;
};
