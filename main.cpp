#include <iostream>
#include "DxLib.h"
#include "Graphic.h"
#include "Object.h"
using namespace std;

class Scene{
public:
	Scene();
	void update();
	void draw();
	void lateUpdate();
private:
	GraphicManager graphicManager;

	//vector<vector<shared_ptr<Object>>> enemies;
	vector<shared_ptr<CharaA>> cas;
	vector<shared_ptr<CharaB>> cbs;
};

Scene::Scene(){
	for(int i = 0; i < 5; ++i){
		shared_ptr<CharaA> ca( new CharaA( Vector2(i*20,  0), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA1) ) );
		cas.push_back(ca);
		graphicManager.resister(ca);

		shared_ptr<CharaB> cb( new CharaB(Vector2(i*20, 20), UniqueGraphicManager::getInstance().getUniqueGraphic(UniqueGraphicManager::getInstance().CHARA2) ) );
		cbs.push_back(cb);
		graphicManager.resister(cb);
	}

	//enemies.push_back(cas);
	//enemies.push_back(cbs);
}

void Scene::update(){
	cas[2]->update();
	cbs[3]->update();
}

void Scene::draw(){
	graphicManager.draw();
}

void Scene::lateUpdate(){
	//graphicManager.update();	//graphicのupdateとは
}

bool processLoop(){
	if(ProcessMessage() != 0)  return false;	//プロセス処理がエラーのとき
	if(ClearDrawScreen() != 0) return false;	//画面クリア処理がエラーのとき
	clsDx();
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	ChangeWindowMode(true);
	SetMainWindowText("GraphicManager test");
	SetGraphMode(640, 480, 32);

	if(DxLib_Init() == -1) return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	Scene scene;

	while(processLoop() && !CheckHitKey(KEY_INPUT_ESCAPE)){
		scene.update();
		scene.draw();

		ScreenFlip();

		scene.lateUpdate();
	}

	DxLib_End();
	return 0;
}