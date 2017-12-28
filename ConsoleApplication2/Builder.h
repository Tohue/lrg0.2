#ifndef BUILDER_H
#define BUILDER_H
#include <iostream>
#include "SDL.h"
#include "Graphics.h"
#include "Character.h"
#include "Object.h"
#include <list>
#include "level.h"
#include "Menu.h"
#include "PathFinder.h"



class Object;
class Path;
class Level;
class Runner;
class Menu;
class Robot;

class Builder
{
private:
	//this things are for recieving arrays frm lvlmanager and building the level thru 4loop
	const int GRID_SIZE = 32;
	char grid[20][15];

	int i;

public:
	Runner* runner;
	void Destroy();
	void Build(char LevelStruct[]);
	void BuildMenu();
	Level* CurrentLevel;
	Menu* menu;
	Object* object;

	std::list<Object*> ObjectList;
	std::list<Path*> PathList;
	std::list<Robot*> EnemyList;

};


#endif