#include "stdafx.h"
#include "CharacterController.h"







states CharacterController::UpdateCharacterState(Runner* runner, Input* input)
{
	if ((LadderCollision) && ((input->KeyDown(SDL_SCANCODE_DOWN) || input->KeyDown(SDL_SCANCODE_UP))))
	{

		runner->x = LadderCol->getx();
		runner->y = LadderCol->gety();
		return Climbing;
	}

	if (IsStanding)
		return Running;
	else
		return Falling;


}

void CharacterController::UpdateCoords(Runner * runner, Input* input, Collider* collider)
{


	switch (state = UpdateCharacterState(runner, input))
	{
	case Climbing:
		ClimbingUpdate(runner, input, collider);
		break;
	case Running:
		RunningUpdate(runner, input);
		break;
	case Falling:
		FallingUpdate(runner);
		break;

	}

}


void CharacterController::ClimbingUpdate(Runner * runner, Input * input, Collider* collider)
{



}

void CharacterController::RunningUpdate(Runner * runner, Input * input)
{
	if (input->KeyDown(SDL_SCANCODE_LCTRL))
	{
		runner->Speed = runner->Speed + 1;
	}

	if (input->KeyDown(SDL_SCANCODE_LEFT))
	{


		if (!CollisionCheckResult)
		{

			runner->MoveLeft();
			runner->setdir(Left);
		}
		else
		{
			if (IsStanding)

			runner->MoveRight();
			CollisionCheckResult = false;
		}
		


	}
	if (input->KeyDown(SDL_SCANCODE_RIGHT))
	{
		if (!CollisionCheckResult)
		{
			runner->MoveRight();
			runner->setdir(Right);
		}
		else
		{
			if (IsStanding)
			runner->MoveLeft();
			CollisionCheckResult = false;
		}  

	}

	//THE FOLLOWINGS ARE TO MAKE SURE THE PLAYER SURELY MAKES HIS WAY OUT OF COL POINT
	/*

	if (input->KeyUp(SDL_SCANCODE_LEFT))
	{
		if ((runner->getdir() == Left) && (CollisionCheckResult))
		{
			runner->MoveRight();
			CollisionCheckResult = false;
		}
	}

	if (input->KeyUp(SDL_SCANCODE_RIGHT))
	{
		if ((runner->getdir() == Right) && (CollisionCheckResult))
		{
			runner->MoveLeft();
			CollisionCheckResult = false;
		}
	}
	if (input->KeyUp(SDL_SCANCODE_UP))
	{
		if ((runner->getdir() == Up) && (CollisionCheckResult))
		{
			runner->ClimbDown();
			CollisionCheckResult = false;
		}
	}
	if (input->KeyUp(SDL_SCANCODE_DOWN))
	{
		if ((runner->getdir() == Down) && (CollisionCheckResult))
		{

			runner->ClimbUp();
			CollisionCheckResult = false;

		}
	}
	*/
}

void CharacterController::FallingUpdate(Runner * runner)
{
	if (IsStanding)
	{
		state = Running;
	}
		
	else
		runner->ClimbDown();
}

void CharacterController::UpdateRobotCoords(Robot * robot, Input * input)
{
}

