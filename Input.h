#pragma once

class Input{
public:
	static Input getInstance(){
		static Input ins;
		return ins;
	}

	void initialize();
	int update();

	bool pushed(int keyID, bool judge_once = true);
	bool pushing(int keyID);
	bool released(int keyID);
	
	bool pushingUntil(int keyID, int frame);
	bool pushingPer(int keyID, int frame);
	
	int getFrame(int keyID);

private:
	Input(){}

	int key[256];
	int prevkey[256];
};
