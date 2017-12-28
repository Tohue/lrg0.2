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

enum CurrState {InMenu, Playing};


class LevelManager
{

private:
	int CurrentLevel = 0;

public:
	CurrState st = Playing;
	int getlevel();
	void GoToMenu(Builder * builder);
	char LevelStruct[500];
	void LoadLevel(char LevelNumber);
	void EndLevel(Builder * builder);
	void NextLevel(Builder * builder, PathFinder * pathf);
};






#endif