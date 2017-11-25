#ifndef COLLIDER_H
#define COLLIDER_H
#include "character.h"
#include "input.h"



class Collider

{
private:
	int Last_standing_X;
public:


	bool CollisionCheck(Character* character, Object* obj, Builder* builder);
	bool CheckStanding(Runner* runner, Object* obj);

};




#endif