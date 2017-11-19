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

	if ((floor((double)(topB / 32))) == floor((double)(bottomA / 32 + 1)))
		return false;
	return true;
}


bool Collider::CheckStanding(Runner* runner, Object* obj)
{
	double ax, ay;
	ax = floor((double)(runner->getx() / 32));
	ay = floor((double)(runner->gety() / 32));
	//(ay + 1)to check the block from the next row
	ay = (ay + 1) * 32;
	ax *= 32;
	if ((((runner->getx() + 32) >= (int)ax)|| (runner->getx() <= ((int)ax + 32))) && (obj->gety() == (int)ay))
	{
		//if (((runner->getx() - obj->getx()) <= 32) || ((obj->getx() - runner->getx()) >= 32))
			return true;
	}
	else
		//ZACHEM TI PRIGNUL BRAT SKAZHI ZACHEM
		//ESLI BI MI ZNALI MIB TEBYA POYMALI
		//NO MI NE SMOGLI TEBE POMOCH'
		return false;
}
