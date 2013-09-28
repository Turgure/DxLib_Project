#pragma once
#include <memory>
#include "Graphic.h"

/* 
 * �V�[�����N���X
 * �S�V�[���N���X�̊��N���X�B���̃N���X��main()���N�����邱�Ƃŏ�ʂ��؂�ւ��B
 */
class SceneManager;
class BaseScene{
	friend class SceneManager;
public:
	BaseScene();
	virtual ~BaseScene(){}
	
protected:
	virtual void start(){}     ///< @brief �N������
	virtual void update(){}    ///< @brief �t���[���X�V
	virtual void terminate(){} ///< @brief �I������
	void setNextScene(std::shared_ptr<BaseScene> scene);

private:
	BaseScene(const BaseScene&);
	BaseScene operator=(const BaseScene&);
	std::shared_ptr<BaseScene> main(); ///< �V�[�����s
	bool processLoop();

	static bool running;
	bool looping; ///< @brief ���[�v���t���O @detail ���[�v���t���O�Bfalse�̏�Ԃ�update()�𔲂���ƃV�[�����I������B
	std::shared_ptr<BaseScene> next_scene;
};


/* 
 * �V�[���Ǘ��N���X
 * �V�[���̑J�ڂƎ��s���Ǘ�����N���X
 */
class SceneManager{
public:
	static void run(std::shared_ptr<BaseScene> starter);

private:
	static bool running; ///< ���s���t���O�@
	static std::shared_ptr<BaseScene> current;
};
