#ifndef OBJECT_H
#define OBJECT_H
#include "SDL.h"
#include "Builder.h"

class Object
{
protected:
	bool Top = false;
	bool Bottom = false; 
	int x, y;
	bool Solid = true;
public:
	bool Climbable = false;
	bool Collectable = false;
	bool IsTube = false;
	bool IsTop();
	bool IsBottom();

	bool IsSolid();
	void SetSolid(bool set);

	friend class Builder;
	int getx();
	int gety();

};

class Block : public Object
{
public:
	Block();
};

class Tube : public Object
{
public:
	Tube();
};

class Ladder : public Object
{
protected:
	bool Top;
	bool Bottom;
public:
	bool IsTop();
	bool IsBottom();
	Ladder(bool istop, bool isbottom);
};

class Coin : public Object
{
public:
	Coin();
};

class Path : public Object
{


};

class Teleporter : public Object
{
public:
	bool IsOn = false;
};
#endif