#pragma once
#include "DxLib.h"
//#include "Debug.h"
//#include "Graphics.h"
#include "Sound.h"
#include "BaseScene.h"
//#include "Input.h"
//#include "GV.h"

bool BaseScene::running;

BaseScene::BaseScene():next_scene(0), looping(false), callbackState(NONE){}

BaseScene* BaseScene::main() {
	// 1度に実行できるシーンは1つ
	if(running){
		return nullptr;
	}
/*#ifdef AA_DEBUG
	DebugPrint( typeid(*this).name() );
	DebugPrint(" シーン開始。\n");
#endif*/
	callbackState = NONE;
	running = true;
	isWaitingTransition = false;
	next_scene = nullptr;
	// ループ前処理
	start();
	looping = true;
	// メインループ
	while(looping){
		//Graphics->update();
		//Input::update();
		Sound::update();
		if( ProcessMessage() == 0 ){
			if(Graphics->isTransFinished() && callbackState == READY){
				try{
					callbackState = CALLED;
					onTransComplete();
				}catch(std::bad_function_call&){
				}
			}
			update();
		}else{
			// エラー時中断
			running = false;
			terminate();
			next_scene = nullptr;
#ifdef AA_DEBUG
			DebugPrint( typeid(*this).name() );
			DebugPrint(" でシーンが中断されました。\n");
#endif
			return nullptr;
		}
	}
	// ループ後処理
	terminate();
	running = false;
/*#ifdef AA_DEBUG
	DebugPrint( typeid(*this).name() );
	DebugPrint(" 正常終了。\n");
#endif*/
	return next_scene;
}

bool BaseScene::isRunning() const {
	return looping;
}

void BaseScene::setTransition(int start, int end, int delay, bool waitflag){
	if(waitflag) isWaitingTransition = true;
	Graphics->setTransition(start, end, delay);
}

void BaseScene::setTransComplete(std::function<void(void)> callback){
	onTransComplete = callback;
	callbackState = READY;
}

void BaseScene::setNextScene(BaseScene* scene){
	next_scene = scene;
	looping = false;
}

bool SceneManager::running = false;
BaseScene* SceneManager::current;

void SceneManager::run(BaseScene *starter){
	if(running || !starter) return;
	running = true;
	// グラフィックモジュールを作成
	Graphics = new Module_Graphics;
	//Graphics->show_fps = true;
	// 開始シーンをセット
	BaseScene* next = nullptr;
	current = starter;
	// メインループ開始
	do{
		next = current->main();
		delete current;
	}while(current = next);

	delete Graphics;
	running = false;
}
