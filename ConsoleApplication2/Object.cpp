#include "stdafx.h"
#include "Object.h"


int Object::getx()
{
	return x;
}

int Object::gety()
{
	return y;
}



bool Block::IsSolid()
{
	return Solid;
}

Ladder::Ladder()
{
	Climbable = true;
}
