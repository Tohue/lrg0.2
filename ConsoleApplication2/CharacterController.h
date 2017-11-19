#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "SDL.h"
#include "Character.h"
#include "Graphics.h"
#include "Input.h"
#include "Builder.h"
#include "Object.h"


//Enum for checing what's going on with main character

enum states { Running, Digging, Falling, Climbing };

class CharacterController
{

private:
	
public:
	states state = Running;
	bool IsStanding = true;
	bool CollisionCheckResult = false;
	bool LadderCollision = false;
	void UpdateCoords(Runner* runner, Input* input);
	void RunningUpdate(Runner* runner, Input* input);
	void FallingUpdate(Runner* runner);
	void UpdateCoords(Robot* robot, Input* input);


};

#endif

