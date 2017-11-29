#include "Object.h"


bool Object::IsTop()
{
	return Top; 
}

bool Object::IsBottom()
{
	return Bottom;
}

bool Object::IsSolid()
{
	return Solid;
}

void Object::SetSolid(bool set)
{
	Solid = set;
}

int Object::getx()
{
	return x;
}

int Object::gety()
{
	return y;
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

Coin::Coin()
{
	Collectable = true;

}

Tube::Tube()
{
	IsTube = true;
}

Block::Block()
{
	Solid = true;
}
