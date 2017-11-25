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
