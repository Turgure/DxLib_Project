#pragma once
#include <string>
#include <vector>
#include <unordered_map>
//#include "Fader.h"

class Sound{
public:
	struct BGMData{
		std::string filename;
		std::string title;
		std::string dataname;
		int loopPos;
		BGMData():loopPos(0){}
	};
	struct SEData{
		int handle;
		int volume;
		bool playflag;
	};

private:
	static std::vector<BGMData> BGMTable;
	static std::vector<SEData> seTable;
	static std::tr1::unordered_map<unsigned int, int> BGMNameTable;
	static std::tr1::unordered_map<unsigned int, int> SENameTable;
	static int H_PlayingMusic;
	static int playingBGM;
	//static RDM::SingleFader<double> tempBGMVolume;

	static void loadBGMTable();
	static void loadSETable();
	static void loadAllSound();
	static void setVolumeToSoundInPercent(int vol, int sound);

public:
	static void initialize();
	static int BGM_volume;
	static int SE_volume;
	static void updateVolume();
	static void update();

	static void playMusicByNumber(int num);
	static void playMusic(unsigned int name);
	static void playMusic(const char* name);
	static bool musicIs(unsigned int name);
	static bool musicIs(const char* name);
	static void stopMusic();
	static void rePlayMusic();
	static void playSEByNumber(int num);
	static bool playSE(unsigned int name);
	static bool playSE(const char* name);
	static void fadeMusic(int start, int end, int delay);
	static void fadeMusic(int end, int delay);

	static bool isPlaying(int num);
	static int getPlayingBGMNumber();
	static const std::vector<BGMData>& getBGMTable();
	static std::string getBGMTitle(char num = -1);
};
