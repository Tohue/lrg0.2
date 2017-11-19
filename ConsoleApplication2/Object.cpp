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

bool Ladder::IsTop()
{

	return Top;

}

bool Ladder::IsBottom()
{

	return Bottom;

}


Ladder::Ladder(bool istop, bool isbottom)
{
	Climbable = true;
	if (istop)
		Top = true;
	if (isbottom)
		Bottom = true;
}
