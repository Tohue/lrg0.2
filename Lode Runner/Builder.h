#ifndef BUILDER_H
#define BUILDER_H
#include <iostream>
#include "SDL.h"
#include "Graphics.h"
#include "Character.h"
#include "Object.h"
#include <list>

class Object;
class Runner;

class Builder
{
private:
	//this things are for recieving arrays frm lvlmanager and building the level thru 4loop
	const int GRID_SIZE = 32;
	char grid[20][15];

	int i;

public:
	Runner* runner;
	void Build(char LevelStruct[]);

	Object* object;

	std::list<Object*> ObjectList;


};


#endif