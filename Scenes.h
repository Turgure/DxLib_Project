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

	std::shared_ptr<CharaA> createCharaA(double x, double y);	//enemy	//‚·‚Ä[‚¶‚µ[‚ñ‚Ö‚Á‚¾[‚ÉÚ×‚ ‚è
	std::shared_ptr<CharaB> createCharaB(double x, double y);	//bullet
};

class SceneB : public BaseScene{
private:
	void start() override;
	void update() override;
	void terminate() override;
};
