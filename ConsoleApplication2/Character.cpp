#include "Character.h"

void Character::MoveLeft(int spd)
{
	x -= spd;
}

void Character::MoveRight(int spd)
{
	x += spd;
}

void Character::ClimbUp(int spd)
{
	y -= spd;
}

void Character::ClimbDown(int spd)
{
	y += spd;
}


direction Character::getdir()
{
	return dir;
}

direction Character::setdir(direction newdir)
{
	dir = newdir;
	return dir;
}

int Character::getx()
{

	return x;

}

int Character::gety()
{

	return y;

}

Runner::Runner()
{
	Speed = 5;
}

bool Robot::GetReady()
{
	return IsReady;
}

void Robot::SetReady(bool ready)
{
	IsReady = ready;
}

int Robot::GetPrevX()
{
	return PrevCoords[0];
}

int Robot::GetPrevY()
{
	return PrevCoords[1];
}

void Robot::SetPrevCoords(int x, int y)
{
	PrevCoords[0] = x;
	PrevCoords[1] = y;
}
