#ifndef CHARACTER_H
#define CHARACTER_H
#include "SDL.h"
#include "Builder.h"

//The nice little thing that helps us with sprites and inputs
enum direction {Up, Down, Left, Right};

//

class Character
{
	
	
protected:
	direction dir = Left;
	int x, y;
	int Speed;
	direction setdir(direction newdir);
	
public:
	direction getdir();
	
	int getx();
	int gety();
	friend class Builder;
	friend class CharacterController;
	void MoveLeft();
	void MoveRight();
	void ClimbUp();
	void ClimbDown();
};

//NEED TO DECIDE SHOULD I KEEP SO MANY METHODS IN 'PUBLIC'

class Runner : public Character
{

public:
	Runner();
};



class Robot : public Character
{




};
#endif