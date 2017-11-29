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
	
	if (((obj->getx() == (int)ax) && (obj->gety() == (int)ay)) && obj->IsSolid())
	{
		if ((floor(Last_standing_X / 32)) != floor(runner->getx() / 32)) Last_standing_X = obj->getx();
		if (((runner->getx() + 32) >= (int)ax) || (runner->getx() <= ((int)ax + 32)))
			return true;
	}
	else if ((runner->getx() + 32 >= Last_standing_X) && (runner->getx() + 32 <= Last_standing_X + 32))
		return true;
	return false;
}



void Collider::UpdateCollisions(Builder* builder, CharacterController* charcont, Input* input, LevelManager * lvlman)
{
	bool CheckClear = false;
	Object* ToRemove = NULL;
	std::list<Object*>::iterator it = builder->ObjectList.begin();
	while (++it != builder->ObjectList.end())
	{
		//First off we need to check if there is any block under the legs thru the gridding method
		if (((CheckStanding(builder->runner, *it)) || (charcont->state == Climbing)))
		{
			StandChecker = true;
			if (charcont->state == Digging)
			{
				charcont->BottomBlock = (*it);
				charcont->LeftDel = FindPreviousBlock((*it), builder->ObjectList);
				charcont->RightDel = FindNextBlock((*it), builder->ObjectList);
			}

		}

		//If the collision happens
		if (CollisionCheck(builder->runner, *it, builder))
			//We tell charcont if there are some ladders to climb
			if ((*it)->Climbable)
			{
				if (charcont->LadderCol != (*it)) charcont->LadderCol = (*it);
				LadderChecker = true;
			}

			//Then we will change our level values if the collision happened with the coin

			else if ((*it)->Collectable)
			{  

				ToRemove = (*it);
				if (builder->CurrentLevel->UpdateValues() == 1)
					builder->CurrentLevel->teleport->IsOn = true;
			}

			else if ((*it)->IsTube)
			{
				TubeChecker = true;

			}

			
			
			else if ((*it) == builder->CurrentLevel->teleport)
			{
				if (builder->CurrentLevel->teleport->IsOn)
				{
					CheckClear = true;
				}

			}


		//Finally we'll try avoid the blocks we don't want to get into
			
			else //if ((*it)->IsSolid())
			{
				if ((builder->runner->getx() + 32 >= (*it)->getx()) && (builder->runner->getx() + 32 <= (*it)->getx() + 32))
				{
					if ((builder->runner->gety() >= (*it)->gety()) && (builder->runner->gety() <= (*it)->gety() + 32))
						charcont->RightCol = true;
					if ((builder->runner->gety() < (*it)->gety()) && (builder->runner->gety() + 32 >= (*it)->gety() + 10))
						charcont->RightCol = true;
				}

				if ((builder->runner->getx() <= (*it)->getx() + 32) && (builder->runner->getx() >= (*it)->getx()))
				{
					if ((builder->runner->gety() >= (*it)->gety()) && (builder->runner->gety() <= (*it)->gety() + 32))
						charcont->LeftCol = true;

					if ((builder->runner->gety() < (*it)->gety()) && (builder->runner->gety() + 32 >= (*it)->gety() + 10))
						charcont->LeftCol = true;
				}
			}

	}
	if (ToRemove != NULL)
		delete(ToRemove);
	if (LadderChecker)
		charcont->LadderCollision = true;

	else	
		charcont->LadderCollision = false;

	charcont->IsStanding = StandChecker;
	if (TubeChecker)
		charcont->TubeCollision = true;
	else
		charcont->TubeCollision = false;

		


	charcont->UpdateCoords(builder->runner, input);

	if (CheckClear)
	{
		SDL_Delay(1000);
		//show level changing sequence or smth like that
		lvlman->EndLevel(builder);
	}

	StandChecker = false;
	LadderChecker = false;
	TubeChecker = false;
	charcont->LeftCol = false;
	charcont->RightCol = false;
}


Object* Collider::FindPreviousBlock(Object* obj, std::list<Object*> list)
{
	for (std::list<Object*>::iterator it = list.begin(); it != list.end(); ++it)
		if (((*it)->getx() == obj->getx() - 32) && ((*it)->gety() == obj->gety()))
			return (*it);

	return NULL;
}

Object* Collider::FindNextBlock(Object* obj, std::list<Object*> list)
{
	for (std::list<Object*>::iterator it = list.begin(); it != list.end(); ++it)
		if (((*it)->getx() == obj->getx() + 32) && ((*it)->gety() == obj->gety()))
			return (*it);

	return NULL;
}