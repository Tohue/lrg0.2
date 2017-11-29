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

enum states { Running, Digging, Falling, Climbing, Tubing };

class CharacterController
{

private:
	int DiggingTimer = 0;
	int CoinsCaptured;
	bool IsStanding = true;
	bool CollisionCheckResult = false;
	bool LadderCollision = false;
	bool TubeCollision = false;
	bool LeftCol = false;
	bool RightCol = false;
	Object* LadderCol;
	Object *LeftDel;
	Object *RightDel;
	Object *BottomBlock;
public:
	friend class Collider;
	states state = Running;

	bool IsClimbing();
	bool IsTubing();

	states UpdateCharacterState(Runner* runner, Input* input);
	void UpdateCoords(Runner * runner, Input* input);
	void RunningUpdate(Runner * runner, Input* input);
	void FallingUpdate(Runner * runner);
	void DiggingUpdate(Runner* runner);
	void UpdateRobotCoords(Robot* robot, Input* input);
};

#endif

