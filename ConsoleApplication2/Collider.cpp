#include "stdafx.h"
#include "Collider.h"

bool Collider::CollisionCheck(Character * character, Object* obj, Builder* builder)
{
	Character* A = character;

	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = A->getx();
	rightA = A->getx() + 32;
	topA = A->gety();
	bottomA = A->gety() + 32;

	Object* B = obj;
	leftB = B->getx();
	rightB = B->getx() + 32;
	topB = B->gety();
	bottomB = B->gety() + 32;

	if ((bottomA < topB) || (topA > bottomB) || (rightA < leftB) || (leftA > rightB))
	{
		return false;

	}

	if ((topB / 32) == ((bottomA / 32) + 1))
	{
		printf("%d    %d", (topB / 32), (bottomA / 32 + 1));
		return false;
	}
		
	return true;
}


bool Collider::CheckStanding(Runner* runner, Object* obj)
{
	float ax, ay;
	ax = float(runner->getx());
	ay = float(runner->gety());
	ax = (floor(ax / 32)) * 32;
	ay = ((floor(ay / 32)) + 1) * 32;
	
	if ((obj->getx() == (int)ax) && (obj->gety() == (int)ay))
	{
		if ((floor(Last_standing_X / 32)) != floor(runner->getx() / 32)) Last_standing_X = obj->getx();
		if (((runner->getx() + 32) >= (int)ax) || (runner->getx() <= ((int)ax + 32)))
			return true;
	}
	else if ((runner->getx() + 32 >= Last_standing_X) && (runner->getx() + 32 <= Last_standing_X + 32))
		return true;
	return false;
}
