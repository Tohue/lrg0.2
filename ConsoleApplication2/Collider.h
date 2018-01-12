#ifndef COLLIDER_H
#define COLLIDER_H
#include "character.h"
#include "input.h"
#include "charactercontroller.h"
#include "levelmanager.h"
#include "Sound.h"
#include "Object.h"
#include <list>

class Object;
class SoundManager;
class Character;
class Runner;
class LevelManager;
class Robot;
class PathFinder;
class CharacterController;


/*!
\brief This contains information about a point where robots should start fall

*/

class Point
{
protected:
	int x;
	int y;

public:
	/*!
	\brief The Constructor sets the x and y
	\param[in] X - sets the x
	\param[in] Y - sets the y
	*/
	Point(int X, int Y);
	/*!
	\brief The getter of X

	*/
	int getx();
	/*!
	\brief The getter of Y

	*/
	int gety();
};


/*!
\brief the controller to check collisions
This is the class with the most ugly functions. This controller tracks the states of characters, check if they collide any objects or each other,
whether it is standing or not.

*/
class Collider

{
private:
	int Last_standing_X;
	int Last_Standing_Y;
	
	bool LadderChecker = false;
	bool StandChecker = true;
	bool TubeChecker = false;
public:
	std::list<Point*> FallPoints; ///< A list of every point where the robots should start falling
	/*!
	\brief The collision check between the runner and specified object
	\param[in] runner 
	\param[in] object
	*/
	bool CollisionCheck(Character* character, Object* obj, Builder* builder);
	/*!
	\brief The collision check between the runner and secified robot
	\param[in] runner
	\param[in] robot
	*/
	bool CollisionCheck(Character * character, Robot* robot, Builder* builder);
	/*!
	\brief Check if the runner is standing on some object
	\param[in] runner
	\param[in] obj
	*/
	bool CheckStanding(Runner* runner, Object* obj);
	/*!
	\brief Update all the collision interactions between runner and every object on the map
	\param[in] builder
	\param[in] charcont
	\param[in] input
	\param[in] lvlman
	\param[in] soundman - SoundManager object
	\param[in] pathf - PathFinder object
	\param[in] collider
	*/
	void UpdateCollisions(Builder* builder, CharacterController* charcont, Input* input, LevelManager* lvlman, SoundManager * soundman, PathFinder* pathf, Collider* collider);
	/*!
	\brief Finds what block will be the next under the runner's legs
		\param[in] builder
		\param[in] list - list of all objects
	*/

	Object* FindPreviousBlock(Object * obj, std::list<Object*> list);

	/*!
	\brief Finds what block was the previous one under the runner's legs
	\param[in] builder
	\param[in] list - list of all objects
	*/

	Object* FindNextBlock(Object * obj, std::list<Object*> list);


};




#endif