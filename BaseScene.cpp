#include "DxLib.h"
#include "BaseScene.h"
//#include "Graphics.h"
#include "Input.h"
#include "Sound.h"

bool BaseScene::running = false;

BaseScene::BaseScene():next_scene(0), looping(false){}

std::shared_ptr<BaseScene> BaseScene::main() {
	// 1�x�Ɏ��s�ł���V�[����1��
	if(running) return std::shared_ptr<BaseScene>();
	running = true;
	next_scene;

	// ���[�v�O����
	start();
	looping = true;

	// ���C�����[�v
	while(looping){
		//SpriteManager::getInstance().update();	//TODO: graphic��uppdate�Ƃ�
		Input::getInstance().update();
		Sound::getInstance().update();

		if(processLoop()){
			update();
			SpriteManager::getInstance().draw();
		}else{
			// �G���[�����f
			terminate();
			running = false;
			return std::shared_ptr<BaseScene>();
		}
	}

	// ���[�v�㏈��
	terminate();
	running = false;

	return next_scene;
}

void BaseScene::setNextScene(std::shared_ptr<BaseScene> scene){
	next_scene = scene;
	looping = false;
}

bool BaseScene::processLoop(){
	if(ProcessMessage() != 0)  return false;	//�v���Z�X�������G���[�̂Ƃ�
	if(ClearDrawScreen() != 0) return false;	//��ʃN���A�������G���[�̂Ƃ�
	clsDx();

	if(Input::getInstance().pushed(KEY_INPUT_ESCAPE)) return false;	//ESC�L�[����������I��

	return true;
}



bool SceneManager::running = false;
std::shared_ptr<BaseScene> SceneManager::current;

void SceneManager::run(std::shared_ptr<BaseScene> starter){
	if(running || !starter) return;
	running = true;

	// �J�n�V�[�����Z�b�g
	std::shared_ptr<BaseScene> next;
	current = starter;

	// ���C�����[�v�J�n
	do{
		next = current->main();
	}while(current = next);

	running = false;
}
