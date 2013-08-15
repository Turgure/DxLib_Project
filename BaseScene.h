#pragma once
#include <functional>

class SceneManager;
class BaseScene{
	friend class SceneManager;
private:
	BaseScene(const BaseScene&);
	BaseScene operator=(const BaseScene&);
	static bool running;
	BaseScene* main(); ///< シーン実行
	std::function<void(void)> onTransComplete;
	enum CallBackState{NONE, READY, CALLED} callbackState;
	BaseScene* next_scene; ///< @brief 次のシーン
	bool looping; ///< @brief ループ中フラグ @detail ループ中フラグ。falseの状態でupdate()を抜けるとシーンが終了する。
protected:
	bool isWaitingTransition;
	bool isRunning() const;
	void setTransition(int start, int end, int delay, bool waitflag = false);
	void setTransComplete(std::function<void(void)> callback);
	virtual void update(){}    ///< @brief フレーム更新
	virtual void start(){}     ///< @brief 起動処理
	virtual void terminate(){} ///< @brief 終了処理
	void setNextScene(BaseScene* scene);
public:
	BaseScene();
	virtual ~BaseScene(){}
};

class SceneManager {
	static bool running; ///< 実行中フラグ　
	static BaseScene* current;
public:
	/**
	*  @brief シーン実行開始
	*  @param starter 開始シーン（タイトル画面など）
	*
	*  開始シーンから始めて、遷移可能な限りシーンを実行し続ける。
	*/
	static void run(BaseScene* starter = 0);
	template<class T>
	static bool currentSceneIs(){
		return typeid(&current) == typeid(T)
	}
};
