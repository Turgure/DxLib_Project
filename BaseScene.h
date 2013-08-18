#pragma once

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
	virtual void update(){}    ///< @brief �t���[���X�V
	virtual void start(){}     ///< @brief �N������
	virtual void terminate(){} ///< @brief �I������
	void setNextScene(BaseScene* scene);

private:
	BaseScene(const BaseScene&);
	BaseScene operator=(const BaseScene&);
	BaseScene* main(); ///< �V�[�����s
	bool processLoop();

	static bool running;
	bool looping; ///< @brief ���[�v���t���O @detail ���[�v���t���O�Bfalse�̏�Ԃ�update()�𔲂���ƃV�[�����I������B
	BaseScene* next_scene;
};


/* 
 * �V�[���Ǘ��N���X
 * �V�[���̑J�ڂƎ��s���Ǘ�����N���X
 */
class SceneManager {
public:
	static void run(BaseScene* starter = nullptr);

private:
	static bool running; ///< ���s���t���O�@
	static BaseScene* current;
};
