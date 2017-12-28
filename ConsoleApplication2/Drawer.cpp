#include "stdafx.h"
#include "Drawer.h"
#include <String>

Drawer::Drawer(Graphics* graph)
{
	std::string str = "../assets/Block1.bmp";
	TestAsset[0] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/Runner_Run_Left.bmp";
	TestAsset[1] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/Runner_Run_Right.bmp";
	TestAsset[2] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/Runner_Climb.bmp";
	TestAsset[3] = graph->NewSprite(&str, 255, 0 , 255);
	str = "../assets/Runner_Falling.bmp";
	TestAsset[4] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/ladder.bmp";
	TestAsset[5] = graph->NewSprite(&str, 255, 0, 255);

	//Background 
	str = "../assets/background/Background1.bmp";
	TestAsset[6] = graph->NewSprite(&str);

	str = "../assets/smoke_back.bmp";
	TestAsset[7] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/smoke_front.bmp";
	TestAsset[8] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/smoke_front1.bmp";
	TestAsset[9] = graph->NewSprite(&str, 255, 0, 255);
	str = "../assets/numbers.bmp";
	TestAsset[10] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Chip.bmp";
	TestAsset[11] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Teleporter_Broken.bmp";
	TestAsset[12] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/pipe.bmp";
	TestAsset[13] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Runner_Tubing.bmp";
	TestAsset[14] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Runner_Dig_Left.bmp";
	TestAsset[15] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Runner_Dig_Right.bmp";
	TestAsset[16] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Teleporter_Working.bmp";
	TestAsset[17] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/effects/Teleport_Light.bmp";
	FXAsset[0] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/background/Menu_Background.bmp";
	TestAsset[18] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/background/Menu_Character.bmp";
	TestAsset[19] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/background/Menu_Title.bmp";
	TestAsset[20] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/background/Button_Play.bmp";
	TestAsset[21] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/background/Button_Play_Active.bmp";
	TestAsset[22] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Robot_Run_Left.bmp";
	TestAsset[23] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Robot_Run_Right.bmp";
	TestAsset[24] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Robot_Climb.bmp";
	TestAsset[25] = graph->NewSprite(&str, 255, 0, 255);

}

void Drawer::DrawBackgrounds(Graphics* graph, LevelManager* lvlman)
{
	if (lvlman->st == InMenu)
	{

		graph->DrawSprite(TestAsset[18], 0, 0);
		graph->DrawSprite(TestAsset[19], 0, 0);
		graph->DrawSprite(TestAsset[20], 0, 0);
	}
	else
	{
		if (BackgroundFrame > 20) BackgroundFrame = 0;

		graph->DrawSprite(TestAsset[6], 0, 0);

		graph->DrawSprite(TestAsset[7], 0, 162, 150);
		graph->DrawSprite(TestAsset[7], 320, 162, 150);
		graph->DrawSprite(TestAsset[8], 0 + BackgroundFrame, 162, 100);
		graph->DrawSprite(TestAsset[9], 300 - BackgroundFrame, 162, 120);

		BackgroundFrame++;
	}

}


void Drawer::UpdateSprite(Runner * runner, Graphics * graph, Input* input)
{

	if (runner->getdir() == DigLeft)
	{
		if (LeftDigFrame > 4) LeftDigFrame = 0;
		graph->DrawSprite(TestAsset[15], runner->getx(), runner->gety(), LeftDigFrame * 32, 0, 32, 32);
		LeftDigFrame++;
	}

	if (runner->getdir() == DigRight)
	{
		if (RightDigFrame > 4) RightDigFrame = 0;
		graph->DrawSprite(TestAsset[16], runner->getx(), runner->gety(), RightDigFrame * 32, 0, 32, 32);
		RightDigFrame++;
	}

	if (runner->getdir() == ClimbLeft)
	{
		if (input->KeyDown(SDL_SCANCODE_LEFT))
		{
			if (TubingFrame > 1) TubingFrame = 0;
			graph->DrawSprite(TestAsset[14], runner->getx(), runner->gety(), TubingFrame * 32, 0, 32, 32);
			TubingFrame++;
		}
		else
			graph->DrawSprite(TestAsset[14], runner->getx(), runner->gety(), 0, 0, 32, 32);

	}
		
	if (runner->getdir() == ClimbRight)
	{
		if (input->KeyDown(SDL_SCANCODE_RIGHT))
		{
			if (TubingFrame > 1) TubingFrame = 0;
			graph->DrawSprite(TestAsset[14], runner->getx(), runner->gety(), TubingFrame * 32, 0, 32, 32);
			TubingFrame++;
		}
		else
			graph->DrawSprite(TestAsset[14], runner->getx(), runner->gety(), 0, 0, 32, 32);

	}

	if (runner->getdir() == Left)
	{

		if (input->KeyDown(SDL_SCANCODE_LEFT))

		{
			if (LeftFrame > 7) LeftFrame = 0;

			graph->DrawSprite(TestAsset[1], runner->getx(), runner->gety(), LeftFrame * 32, 0, 32, 32);
			LeftFrame++;
		}
		else
			graph->DrawSprite(TestAsset[1], runner->getx(), runner->gety(), 0, 0, 32, 32);
	}

	if (runner->getdir() == Right)
	{
		if (input->KeyDown(SDL_SCANCODE_RIGHT))

			{
			if (RightFrame > 7) RightFrame = 0;

			graph->DrawSprite(TestAsset[2], runner->getx(), runner->gety(), RightFrame * 32, 0, 32, 32);
			RightFrame++;
			}
		else 
			graph->DrawSprite(TestAsset[2], runner->getx(), runner->gety(), 0, 0, 32, 32);
	}

	if (runner->getdir() == Up)
	{
		if (input->KeyDown(SDL_SCANCODE_UP) || input->KeyDown(SDL_SCANCODE_DOWN))

		{
			if (ClimbFrame > 2) ClimbFrame = 0;

			graph->DrawSprite(TestAsset[3], runner->getx(), runner->gety(), ClimbFrame * 32, 0, 32, 32);
			ClimbFrame++;
		}
		else
			graph->DrawSprite(TestAsset[3], runner->getx(), runner->gety(), 0, 0, 32, 32);
	}


	if (runner->getdir() == Down)
	{
			graph->DrawSprite(TestAsset[4], runner->getx(), runner->gety(), 0, 0, 32, 32);
	}


}

void Drawer::UpdateSprite(Builder * builder, Graphics* graph)
{

	if (builder->menu != NULL)
		for (std::list<Button*>::iterator it = builder->menu->ButtonList.begin(); it != builder->menu->ButtonList.end(); ++it)
			if ((*it)->state == Passive)
			{
				if ((*it)->GetNumber() == 0) graph->DrawSprite(TestAsset[21], (*it)->Getx(), (*it)->Gety());
				if ((*it)->GetNumber() == 1) graph->DrawSprite(TestAsset[21], (*it)->Getx(), (*it)->Gety());
				if ((*it)->GetNumber() == 2) graph->DrawSprite(TestAsset[21], (*it)->Getx(), (*it)->Gety());
			}
			else
				{
					if ((*it)->GetNumber() == 0) graph->DrawSprite(TestAsset[22], (*it)->Getx(), (*it)->Gety());
					if ((*it)->GetNumber() == 1) graph->DrawSprite(TestAsset[22], (*it)->Getx(), (*it)->Gety());
					if ((*it)->GetNumber() == 2) graph->DrawSprite(TestAsset[22], (*it)->Getx(), (*it)->Gety());
				}
			

}


void Drawer::UpdateSprite(Object* object, Graphics* graph, Builder * builder)
{
	if (object == builder->CurrentLevel->teleport)
	{
		if (builder->CurrentLevel->teleport->IsOn)
		{
			graph->DrawSprite(TestAsset[17], object->getx(), object->gety());
			if (LightFrame > 2) LightFrame = 0;
			graph->DrawSprite(FXAsset[0], object->getx() - 32, object->gety() - 32, LightFrame * 96, 0, 96, 96, 100);
			LightFrame++;
		}

		else
			graph->DrawSprite(TestAsset[12], object->getx(), object->gety());
	}
	else if (object->IsTube)
	graph->DrawSprite(TestAsset[13], object->getx(), object->gety());

	else if (object->Climbable == true)
	graph->DrawSprite(TestAsset[5], object->getx(), object->gety());
	else if (object->Collectable == true)
		graph->DrawSprite(TestAsset[11], object->getx(), object->gety());
	else if (object->IsSolid())
	graph->DrawSprite(TestAsset[0], object->getx(), object->gety());


}

void Drawer::UpdateSprite(Robot * robot, Graphics * graph)
{
	if (robot->getdir() == Left)
	{
			if (rLeftFrame > 2) rLeftFrame = 0;

			graph->DrawSprite(TestAsset[23], robot->getx(), robot->gety(), rLeftFrame * 32, 0, 32, 32);
			rLeftFrame++;
	}

	if (robot->getdir() == Right)
	{
			if (rRightFrame > 2) rRightFrame = 0;

			graph->DrawSprite(TestAsset[24], robot->getx(), robot->gety(), rRightFrame * 32, 0, 32, 32);
			rRightFrame++;
	}

	if (robot->getdir() == Up)
	{

			graph->DrawSprite(TestAsset[25], robot->getx(), robot->gety());

	}


	if (robot->getdir() == Down)
	{
		graph->DrawSprite(TestAsset[25], robot->getx(), robot->gety(), 0, 0, 32, 32);
	}
}

void Drawer::UpdateScoreSprite(Graphics* graph, Builder * builder)
{
	int Score;
	float mod1, mod2, mod3;
	Score = (builder->CurrentLevel->GetCurrentScore() * 100);
	mod1 = (Score / 100);
	mod2 = (Score % 100) / 10;
	mod3 = (Score % 10);
	if (mod1 == 0)
		graph->DrawSprite(TestAsset[10], 0, 16, 144, 0, 16, 16);
	else
		graph->DrawSprite(TestAsset[10], 0, 16, mod1 * 16 - 16, 0, 16, 16);
	if (mod2 == 0)
		graph->DrawSprite(TestAsset[10], 16, 16, 144, 0, 16, 16);
	else
		graph->DrawSprite(TestAsset[10], 16, 16, mod2 * 16 - 16, 0, 16, 16);
	if (mod3 == 0)
		graph->DrawSprite(TestAsset[10], 32, 16, 144, 0, 16, 16);
	else
		graph->DrawSprite(TestAsset[10], 32, 16, mod3 * 16 - 16, 0, 16, 16);

}