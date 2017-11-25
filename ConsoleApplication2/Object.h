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

public:
	bool IsTop();
	bool IsBottom();
	friend class Builder;
	int getx();
	int gety();
	bool Climbable = false;
};


class Block : public Object
{

private: 
	bool Solid;
public:
	bool IsSolid();

};


class Tube : public Object
{

};


class Ladder : public Object
{
protected:
	bool Top;
	bool Bottom;
public:

	//friend class CharacterController;
	bool IsTop();
	bool IsBottom();
	Ladder(bool istop, bool isbottom);
	


};


#endif