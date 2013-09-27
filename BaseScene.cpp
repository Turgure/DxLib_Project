#include "DxLib.h"
#include "BaseScene.h"
//#include "Graphics.h"
#include "Input.h"
#include "Sound.h"

bool BaseScene::running = false;

BaseScene::BaseScene():next_scene(0), looping(false){}

BaseScene* BaseScene::main() {
	// 1�x�Ɏ��s�ł���V�[����1��
	if(running) return nullptr;
	running = true;
	next_scene = nullptr;

	// ���[�v�O����
	start();
	looping = true;

	// ���C�����[�v
	while(looping){
		//GraphicManager::getInstance().update();	//TODO: graphic��uppdate�Ƃ�
		Input::getInstance().update();
		Sound::getInstance().update();

		if(processLoop()){
			update();
			GraphicManager::getInstance().draw();
		}else{
			// �G���[�����f
			terminate();
			running = false;
			return next_scene = nullptr;
		}
	}

	// ���[�v�㏈��
	terminate();
	running = false;

	return next_scene;
}

void BaseScene::setNextScene(BaseScene* scene){
	next_scene = scene;
	looping = false;
}

bool BaseScene::processLoop(){
	if(ProcessMessage() != 0)  return false;	//�v���Z�X�������G���[�̂Ƃ�
	if(ClearDrawScreen() != 0) return false;	//��ʃN���A�������G���[�̂Ƃ�
	clsDx();

	if(CheckHitKey(KEY_INPUT_ESCAPE)) return false;	//ESC�L�[����������I��

	return true;
}



bool SceneManager::running = false;
BaseScene* SceneManager::current;

void SceneManager::run(BaseScene *starter){
	if(running || !starter) return;
	running = true;

	// �J�n�V�[�����Z�b�g
	BaseScene* next = nullptr;
	current = starter;

	// ���C�����[�v�J�n
	do{
		next = current->main();
		delete current;
	}while(current = next);

	running = false;
}
