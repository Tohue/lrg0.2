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


/*!

\brief The class that creates every visible game objects on the game field (and the level itself)

This class contains methods to build visible game objects, such as runner, robots, blocks etc.
Also it controls the current level states and variables, and is able to destroy entire level and build new one, if needed.

*/

class Builder
{
private:
	//this things are for recieving arrays frm lvlmanager and building the level thru 4loop
	const int GRID_SIZE = 32;
	char grid[20][15];

	int i;

public:
	Runner* runner;
	/*!
	\brief When the level is finished, the runner and all the lists and are being vanished by this method. 
	*/
	void Destroy();
	/*!
	\brief  This method transforms a symbol structure into an actual level.
	\param[in] LevelStruct[] - the array containing symbols from the specific file.
	*/
	void Build(char LevelStruct[]);
	/*!
	\brief A method to create everything on the title screen.
	*/
	void BuildMenu();
	Level* CurrentLevel;///< A current level object
	Menu* menu;///< this menu object will be in use when the gamestate is in menu.
	Object* object; ///< a temporary object to create stuff.

	std::list<Object*> ObjectList;///< The list of terrain objects (blocks, ladders..)
	std::list<Path*> PathList; ///< A bunch of invisible objects to declare which blocks can be visited by robots
	std::list<Robot*> EnemyList; ///< A list of every robot on the screen

};


#endif