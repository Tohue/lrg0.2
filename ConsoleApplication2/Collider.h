#ifndef COLLIDER_H
#define COLLIDER_H
#include "character.h"
#include "input.h"
#include "charactercontroller.h"
#include "levelmanager.h"
#include "Sound.h"
#include "Object.h"

class Object;
class SoundManager;
class Character;
class Runner;
class LevelManager;
class Robot;
class PathFinder;
class CharacterController;

class Collider

{
private:
	int Last_standing_X;
	int Last_Standing_Y;
	bool LadderChecker = false;
	bool StandChecker = true;
	bool TubeChecker = false;
public:


	bool CollisionCheck(Character* character, Object* obj, Builder* builder);
	bool CollisionCheck(Character * character, Robot* robot, Builder* builder);
	bool CheckStanding(Runner* runner, Object* obj);
	void UpdateCollisions(Builder* builder, CharacterController* charcont, Input* input, LevelManager* lvlman, SoundManager * soundman, PathFinder* pathf);

	Object* FindPreviousBlock(Object * obj, std::list<Object*> list);

	Object* FindNextBlock(Object * obj, std::list<Object*> list);


};




#endif