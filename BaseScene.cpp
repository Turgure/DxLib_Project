#pragma once
#include "DxLib.h"
#include "BaseScene.h"
//#include "Debug.h"
//#include "Graphics.h"
#include "Input.h"
#include "Sound.h"
//#include "GV.h"

bool BaseScene::running;

BaseScene::BaseScene():next_scene(0), looping(false), callbackState(NONE){}

BaseScene* BaseScene::main() {
	// 1�x�Ɏ��s�ł���V�[����1��
	if(running){
		return nullptr;
	}
/*#ifdef AA_DEBUG
	DebugPrint( typeid(*this).name() );
	DebugPrint(" �V�[���J�n�B\n");
#endif*/
	callbackState = NONE;
	running = true;
	isWaitingTransition = false;
	next_scene = nullptr;
	// ���[�v�O����
	start();
	looping = true;
	// ���C�����[�v
	while(looping){
		//Graphics->update();
		Input::getInstance().update();
		Sound::getInstance().update();

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
			// �G���[�����f
			running = false;
			terminate();
			next_scene = nullptr;
#ifdef AA_DEBUG
			DebugPrint( typeid(*this).name() );
			DebugPrint(" �ŃV�[�������f����܂����B\n");
#endif
			return nullptr;
		}
	}
	// ���[�v�㏈��
	terminate();
	running = false;
/*#ifdef AA_DEBUG
	DebugPrint( typeid(*this).name() );
	DebugPrint(" ����I���B\n");
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
	// �O���t�B�b�N���W���[�����쐬
	Graphics = new Module_Graphics;
	//Graphics->show_fps = true;
	// �J�n�V�[�����Z�b�g
	BaseScene* next = nullptr;
	current = starter;
	// ���C�����[�v�J�n
	do{
		next = current->main();
		delete current;
	}while(current = next);

	delete Graphics;
	running = false;
}
