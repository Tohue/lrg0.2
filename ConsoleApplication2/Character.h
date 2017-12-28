#ifndef CHARACTER_H
#define CHARACTER_H
#include "SDL.h"
#include "Builder.h"

//The nice little thing that helps us with sprites and inputs
enum direction {Up, Down, Left, Right, ClimbLeft, ClimbRight, DigLeft, DigRight};

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
	void MoveLeft(int spd);
	void MoveRight(int spd);
	void ClimbUp(int spd);
	void ClimbDown(int spd);


	//FOR TESTS:
	bool GodMode = false;
};

class Runner : public Character
{

public:
	Runner();
};



class Robot : public Character
{
private:
	bool IsReady = true;
	int PrevCoords[2];

public:
	bool GetReady();
	void SetReady(bool ready);
	int GetPrevX();
	int GetPrevY();
	void SetPrevCoords(int x, int y);
};
#endif