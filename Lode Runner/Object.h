#ifndef OBJECT_H
#define OBJECT_H
#include "SDL.h"
#include "Builder.h"

class Object
{
protected:
	int x, y;

public:
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
public:
	Ladder();
	


};


#endif