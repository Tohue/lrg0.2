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

	if ((bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB))
	{
		return false;

	}

	return true;
}


Object* Collider::CheckStanding(Runner* runner, Object* obj)
{
	float ax, ax1, ax2, ay;
	ax = floor((double)(runner->getx() / 32));
	ay = floor((double)(runner->gety() / 32));
	ay = (ay + 1) * 32;
	ax *= 32;
	if ((obj->getx() == (int)ax) && (obj->gety() == (int)ay))  // || (obj->getx() >= (int)ax - 32) || (obj->getx() <= (int)ax + 32))
	{
		if (((runner->getx() - obj->getx()) <= 32) || ((obj->getx() - runner->getx()) >= 32))
			return obj;
		else
			return NULL;
	}
}
