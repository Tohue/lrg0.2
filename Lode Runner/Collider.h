#ifndef COLLIDER_H
#define COLLIDER_H
#include "character.h"
#include "input.h"



class Collider

{

public:


	bool CollisionCheck(Character* character, Object* obj, Builder* builder);
	Object* CheckStanding(Runner* runner, Object* obj);




};




#endif