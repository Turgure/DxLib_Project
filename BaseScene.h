#pragma once
#include <functional>

class SceneManager;
class BaseScene{
	friend class SceneManager;
private:
	BaseScene(const BaseScene&);
	BaseScene operator=(const BaseScene&);
	static bool running;
	BaseScene* main(); ///< �V�[�����s
	std::function<void(void)> onTransComplete;
	enum CallBackState{NONE, READY, CALLED} callbackState;
	BaseScene* next_scene; ///< @brief ���̃V�[��
	bool looping; ///< @brief ���[�v���t���O @detail ���[�v���t���O�Bfalse�̏�Ԃ�update()�𔲂���ƃV�[�����I������B
protected:
	bool isWaitingTransition;
	bool isRunning() const;
	void setTransition(int start, int end, int delay, bool waitflag = false);
	void setTransComplete(std::function<void(void)> callback);
	virtual void update(){}    ///< @brief �t���[���X�V
	virtual void start(){}     ///< @brief �N������
	virtual void terminate(){} ///< @brief �I������
	void setNextScene(BaseScene* scene);
public:
	BaseScene();
	virtual ~BaseScene(){}
};

class SceneManager {
	static bool running; ///< ���s���t���O�@
	static BaseScene* current;
public:
	/**
	*  @brief �V�[�����s�J�n
	*  @param starter �J�n�V�[���i�^�C�g����ʂȂǁj
	*
	*  �J�n�V�[������n�߂āA�J�ډ\�Ȍ���V�[�������s��������B
	*/
	static void run(BaseScene* starter = 0);
	template<class T>
	static bool currentSceneIs(){
		return typeid(&current) == typeid(T)
	}
};
