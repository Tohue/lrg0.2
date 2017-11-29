#ifndef COLLIDER_H
#define COLLIDER_H
#include "character.h"
#include "input.h"
#include "charactercontroller.h"
#include "levelmanager.h"
#include "Sound.h"

class Collider

{
private:
	int Last_standing_X;
	bool LadderChecker = false;
	bool StandChecker = true;
	bool TubeChecker = false;
public:


	bool CollisionCheck(Character* character, Object* obj, Builder* builder);
	bool CheckStanding(Runner* runner, Object* obj);
	void UpdateCollisions(Builder* builder, CharacterController* charcont, Input* input, LevelManager* lvlman);

	Object* FindPreviousBlock(Object * obj, std::list<Object*> list);

	Object* FindNextBlock(Object * obj, std::list<Object*> list);


};




#endif