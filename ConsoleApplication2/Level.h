#ifndef LEVEL_H
#define LEVEL_H
#include "Object.h"

class Teleporter;

/*!
\brief This class contains some temporary variables used only on current level
*/
class Level
{
private:
	int ScoreToFinish;
	int CurrentScore;
	int LevelNumber;
public:
	Teleporter* teleport;
	/*!
	\brief The setter of the current level number
	\param[in] number - the number of level
	*/
	void SetLevelNumber(int number);
	/*!
	\brief The getter of the current level number
	*/
	int GetLevelNumber();
	/*!
	\brief Sets how many coins should runner take for level to end
	\param[in] score
	*/
	void SetScoreToFinish(int score);
	/*!
	\brief Constructor sets the current score to zero
	*/
	Level();
	/*!
	\brief Increments the current score
	\return 1 if it is the needed number
	*/
	int UpdateValues();
	/*!
	\brief The getter of the current level score
	*/
	int GetCurrentScore();

};


#endif