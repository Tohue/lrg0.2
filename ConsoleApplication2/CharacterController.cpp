#include "stdafx.h"
#include "CharacterController.h"





bool CharacterController::IsClimbing()
{
	return LadderCollision;
}

bool CharacterController::IsTubing()
{
	return TubeCollision;
}

states CharacterController::UpdateCharacterState(Runner* runner, Input* input)
{

		if (state == Digging) return Digging;

		if (LadderCollision)
		{
			if (state != Climbing && IsStanding)
				return Running;

			else if (state == Climbing) return Climbing;
		}


		if (IsStanding)
			return Running;

		if (TubeCollision)
		{
			return Tubing;
		}

		return Falling;
}

void CharacterController::UpdateCoords(Runner * runner, Input* input)
{

	switch (state = UpdateCharacterState(runner, input))
	{
	case Digging:
	{
		DiggingUpdate(runner);
	}

		break;
	case Climbing:
		{	
		RunningUpdate(runner, input);
		runner->setdir(ClimbLeft);
		break;

		}
		
	case Tubing:
		RunningUpdate(runner, input);
		break;
	case Running:
		RunningUpdate(runner, input);
		break;
	case Falling:
		FallingUpdate(runner);
		break;

	}

}



void CharacterController::RunningUpdate(Runner * runner, Input * input)
{

	if (input->KeyDown(SDL_SCANCODE_LSHIFT))
	{
		if (runner->GodMode == true) runner->GodMode = false;
		if (runner->GodMode == false) runner->GodMode = true;
	}


	if (input->KeyDown(SDL_SCANCODE_LCTRL))
	{
		state = Digging;
		//runner->x = BottomBlock->getx();
		//runner->y = BottomBlock->gety() - 32;
	}


	if (input->KeyDown(SDL_SCANCODE_LEFT))
	{
		if (!LeftCol)
		{
			runner->MoveLeft(5);
			if (TubeCollision)
				runner->setdir(ClimbLeft);
			else
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
			if (TubeCollision)
			runner->setdir(ClimbRight);
			else
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
		else if (TubeCollision)
		{
			runner->ClimbDown(5);
			TubeCollision = false;
			state = Running;
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
		runner->ClimbDown(5);
		runner->setdir(Down);
	}
		
		
}


void CharacterController::DiggingUpdate(Runner* runner)
{
	if (DiggingTimer < 10)
	{
		if (DiggingTimer == 1)
		{
			if (runner->dir == Left) runner->dir = DigLeft;
			if (runner->dir == Right) runner->dir = DigRight;
			runner->x = BottomBlock->getx();
			runner->y = BottomBlock->gety() - 30;
		}
		if (DiggingTimer == 8)
		{
			if (runner->dir == DigLeft && LeftDel != NULL && !LeftDel->Climbable)
				LeftDel->SetSolid(false);
			else if (runner->dir == DigRight && RightDel != NULL && !RightDel->Climbable)
				RightDel->SetSolid(false);
		}
		DiggingTimer++;
	}
	else
	{
		if (runner->dir == DigLeft) runner->dir = Left;
		if (runner->dir == DigRight) runner->dir = Right;
		DiggingTimer = 0;
		state = Running;
	}
		
		




}


void CharacterController::UpdateRobotCoords(Robot* robot, Input* input, Runner* runner, PathFinder* pathf)
{
	int i = 0;

	if (robot->GetReady())
	{
		if (pathf->FindPath(robot->getx(), robot->gety(), runner->getx(), runner->gety()))
		{
			robot->SetReady(false);
			while (i < 5 && !robot->GetReady())
			{
				robot->SetPrevCoords(pathf->GetNextPathX(), pathf->GetNextPathY());
				MoveRobot(robot, pathf->GetNextPathX(),pathf->GetNextPathY());
				i++;
			}
		}

	}
	else
	{


		while (i < 5 && !robot->GetReady())
		{
			robot->SetReady(false);
			MoveRobot(robot, robot->GetPrevX(), robot->GetPrevY());
			i++;
		}


	}

}

void CharacterController::MoveRobot(Robot * robot,int x,int y)
{

	if (robot->gety() == y * 32)
	{
		if (robot->getx() < x * 32)
		{
			robot->dir = Right;
			robot->MoveRight(1);
			robot->SetReady(false);
		}

		else if (robot->getx() > x * 32)
		{
			robot->MoveLeft(1);
			robot->dir = Left;
			robot->SetReady(false);
		}
		else robot->SetReady(true);
	}
	else
	{
		if (robot->gety() > y * 32)
		{
			if (robot->getx() == x * 32)
			{
				robot->ClimbUp(1);
				robot->dir = Up;

			}
			else if (robot->getx() > x * 32)
			{
				robot->MoveLeft(1);
				robot->dir = Left;

			}
			else
			{
				robot->dir = Right;
				robot->MoveRight(1);
			}

			robot->SetReady(false);

		}

		else
		{
			if (robot->getx() == x * 32)
			{
				robot->ClimbDown(1);
				robot->dir = Down;
			}
			else if (robot->getx() > x * 32)
			{
				robot->MoveLeft(1);
				robot->dir = Left;

			}
			else
			{
				robot->dir = Right;
				robot->MoveRight(1);
			}

			robot->SetReady(false);
		}

	}

}

