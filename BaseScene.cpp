#include "DxLib.h"
#include "BaseScene.h"
//#include "Graphics.h"
#include "Input.h"
#include "Sound.h"

bool BaseScene::running = false;

BaseScene::BaseScene():next_scene(0), looping(false){}

BaseScene* BaseScene::main() {
	// 1度に実行できるシーンは1つ
	if(running) return nullptr;
	running = true;
	next_scene = nullptr;

	// ループ前処理
	start();
	looping = true;

	// メインループ
	while(looping){
		//GraphicManager::getInstance().update();	//TODO: graphicのuppdateとは
		Input::getInstance().update();
		Sound::getInstance().update();

		if(processLoop()){
			update();
			GraphicManager::getInstance().draw();
		}else{
			// エラー時中断
			terminate();
			running = false;
			return next_scene = nullptr;
		}
	}

	// ループ後処理
	terminate();
	running = false;

	return next_scene;
}

void BaseScene::setNextScene(BaseScene* scene){
	next_scene = scene;
	looping = false;
}

bool BaseScene::processLoop(){
	if(ProcessMessage() != 0)  return false;	//プロセス処理がエラーのとき
	if(ClearDrawScreen() != 0) return false;	//画面クリア処理がエラーのとき
	clsDx();

	if(CheckHitKey(KEY_INPUT_ESCAPE)) return false;	//ESCキーを押したら終了

	return true;
}



bool SceneManager::running = false;
BaseScene* SceneManager::current;

void SceneManager::run(BaseScene *starter){
	if(running || !starter) return;
	running = true;

	// 開始シーンをセット
	BaseScene* next = nullptr;
	current = starter;

	// メインループ開始
	do{
		next = current->main();
		delete current;
	}while(current = next);

	running = false;
}
