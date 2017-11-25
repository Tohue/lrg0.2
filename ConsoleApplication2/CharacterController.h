#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "SDL.h"
#include "Character.h"
#include "Graphics.h"
#include "Input.h"
#include "Builder.h"
#include "Object.h"
#include "Collider.h"


//Enum for checing what's going on with main character

enum states { Running, Digging, Falling, Climbing };

class CharacterController
{

private:
	bool IsStanding = true;
	bool CollisionCheckResult = false;
	bool LadderCollision = false;
	bool LeftCol = false;
	bool RightCol = false;
public:

	friend class Game;

	states state = Running;
	Object* LadderCol;

	states UpdateCharacterState(Runner* runner, Input* input);
	void UpdateCoords(Runner * runner, Input* input, Collider* collider);
	void RunningUpdate(Runner * runner, Input* input);
	void FallingUpdate(Runner * runner);
	void ClimbingUpdate(Runner * runner, Input * input, Collider* collider);
	void UpdateRobotCoords(Robot* robot, Input* input);
};

#endif

