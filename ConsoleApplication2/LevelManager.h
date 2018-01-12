#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "SDL.h"
#include "builder.h"
#include <string>
#include <fstream>
#include "Pathfinder.h"
#include "Sound.h"


class PathFinder;
class SoundManager;

/*!
\brief enum to check if the game is in menu or on some level 
*/
enum CurrState {InMenu, Playing};

/*!
\brief Loads the level, controlls it
This boi loads the level and gives its structure to builder, who actually builds it
*/
class LevelManager
{

private:
	int CurrentLevel = 0;

public:
	CurrState st = Playing;
	/*!
	\brief gets int CurrentLevel
	*/
	int getlevel();
	/*!
	\brief Starts the sequence to go to main menu with deleting what must be deleted
	\param[in] builder - to give an order to build a menu
	*/
	void GoToMenu(Builder * builder); 
	char LevelStruct[500]; ///< This array loads the level structure 
	/*!
	\brief loads level structure into LevelStruct[]
	\param LevelNumber - what level we need
	*/
	void LoadLevel(char LevelNumber);
	/*!
	\brief Starts the ending of corrent level, deleting all trash
	\param builder - to delete some of it objects
	*/
	void EndLevel(Builder * builder);
	/*!
	\brief Goes to next level
	\param builder - to make everything up again
	\param pathf - to build up new fancy route for robots
	*/
	void NextLevel(Builder * builder, PathFinder * pathf);
};






#endif