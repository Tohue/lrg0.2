#include "Character.h"

void Character::MoveLeft()
{
	x -= Speed;
}

void Character::MoveRight()
{
	x += Speed;
}

void Character::ClimbUp()
{
	y -= Speed;
}

void Character::ClimbDown()
{
	y += Speed;
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
	Speed = 2;
}
