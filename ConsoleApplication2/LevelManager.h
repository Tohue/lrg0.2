#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "SDL.h"
#include "builder.h"
#include <string>
#include <fstream>

class LevelManager
{

private:
	int CurrentLevel = 0;

public:
	int getlevel();
	char LevelStruct[500];
	void LoadLevel(char LevelNumber);
	void EndLevel(Builder * builder);
};






#endif