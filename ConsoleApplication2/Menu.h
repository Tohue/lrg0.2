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

/*!
\brief enum to check if the button should glow now or not
*/
enum state { Active, Passive };

/*!
\brief The button for menu
*/
class Button
{
private:
	int x, y;
	int number;

public:
	friend class Menu;
	state state = Passive;
	int GetNumber(); //! Gets number
	int Getx(); //! Gets x
	int Gety(); //! Gets y
};

/*!
\brief A menu class, just like the 'level' one
*/
class Menu
{
private:


public:
	std::list<Button*> ButtonList; ///< List of every button on the screen
	Menu(); //! Constructor; sets everything
	/*!
	\brief Updates menu every tick, just like every other updater
	\param input - to check input for buttons
	\param builder - to build somethis, if we need
	\param lvlman - LevelManager to help managing the levels
	\param pathf - pathfinder to make some new routes
	*/
	void UpdateMenu(Input* input, Builder* builder, LevelManager* lvlman, PathFinder * pathf);
};









#endif