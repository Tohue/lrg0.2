#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "SDL.h"
#include <string>
#include <fstream>

class LevelManager
{
	//TODO: Import levels from file, then write their structs inside the array and send it to the level class,
	//and then to Builder->build();
	//Game should ask lvl what level is on, and when it is finished, there should be a var for this
	//Like this:
	//	if (CurrentLevel.state = finished)
	//		{
	//			CurrentLevel.OrdinaryLevelEndSequence();
	//			lvlman.LoadLevel(lvlman.getlevel() + 1);
	//			Builder->Build(lvlman.nextlevel());
	//		}

private:
	int CurrentLevel = 0;

public:
	int getlevel();
	char LevelStruct[500];
	void LoadLevel(char LevelNumber);



};






#endif