#ifndef LEVEL_H
#define LEVEL_H
#include "Object.h"

class Teleporter;

class Level
{
private:
	int ScoreToFinish;
	int CurrentScore;
	int LevelNumber;
public:
	Teleporter* teleport;
	void SetLevelNumber(int number);
	int GetLevelNumber();
	void SetScoreToFinish(int score);
	Level();
	int UpdateValues();
	int GetCurrentScore();

};


#endif