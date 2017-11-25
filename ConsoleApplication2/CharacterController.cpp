#include "stdafx.h"
#include "CharacterController.h"







states CharacterController::UpdateCharacterState(Runner* runner, Input* input)
{
	if (LadderCollision)
	{
		if (state != Climbing && IsStanding)
			return Running;

		else if (state == Climbing) return Climbing;

	}
	if (IsStanding)
	return Running;
	
	return Falling;


}

void CharacterController::UpdateCoords(Runner * runner, Input* input, Collider* collider)
{
	//mb remove this switch, it's ugly

	switch (state = UpdateCharacterState(runner, input))
	{
	case Climbing:
		RunningUpdate(runner, input);
		//ClimbingUpdate(runner, input, collider);
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


		if (!LeftCol)
		{
			runner->MoveLeft(5);
			runner->setdir(Left);
		}
		else
			runner->MoveRight(0);

		


	}
	if (input->KeyDown(SDL_SCANCODE_RIGHT))
	{
		if (!RightCol)
		{
			runner->MoveRight(5);
			runner->setdir(Right);
		}
		else
			runner->MoveLeft(0);

	}

	if (input->KeyDown(SDL_SCANCODE_UP))
	{
		if (LadderCollision)
		{
			
				runner->x = LadderCol->getx();
				runner->ClimbUp(5);
				runner->setdir(Up);
		}
		else
			state = Running;		

	}
	if (input->KeyDown(SDL_SCANCODE_DOWN))
	{
		if (LadderCollision)
		{

			if (((LadderCol != NULL) && (LadderCol->gety() == runner->gety() + 32)) || ((runner->gety() <= LadderCol->gety()) && !(LadderCol->IsBottom())))

			{
				runner->x = LadderCol->getx();
				runner->ClimbDown(5);
				runner->setdir(Up);
			}

		}
		else
			state = Running;

	}
}

void CharacterController::FallingUpdate(Runner * runner)
{
	if (IsStanding)
	{
		runner->setdir(Left);
		state = Running;
	}
		
	else
	{
		runner->ClimbDown(9);
		runner->setdir(Down);
	}
		
		
}

void CharacterController::UpdateRobotCoords(Robot * robot, Input * input)
{
}

