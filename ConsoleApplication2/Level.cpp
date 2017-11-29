#include "stdafx.h"
#include "Level.h"

void Level::SetLevelNumber(int number)
{
	LevelNumber = number;

}

int Level::GetLevelNumber()
{
	return LevelNumber;
}

void Level::SetScoreToFinish(int score)
{
	ScoreToFinish = score;
}


int Level::GetCurrentScore()
{
	return CurrentScore;
}


Level::Level()
{
	CurrentScore = 0;
}

int Level::UpdateValues()
{
	CurrentScore++;
	if (CurrentScore == ScoreToFinish)
		return 1;
	else return 0;


}

