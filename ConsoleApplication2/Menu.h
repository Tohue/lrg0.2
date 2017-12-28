#ifndef MENU_H
#define MENU_H
#include <list>
#include <iterator>
#include "input.h"
#include "builder.h"
#include "Levelmanager.h"
#include "Pathfinder.h"

class LevelManager;
class PathFinder;

enum state { Active, Passive };
class Button
{
private:
	int x, y;
	int number;

public:
	friend class Menu;
	state state = Passive;
	int GetNumber();
	int Getx();
	int Gety();
};


class Menu
{
private:


public:
	std::list<Button*> ButtonList;
	Menu();
	void UpdateMenu(Input* input, Builder* builder, LevelManager* lvlman, PathFinder * pathf);
};









#endif