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
	str = "../assets/Background1.bmp";
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

	str = "../assets/Teleporter.bmp";
	TestAsset[12] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/pipe.bmp";
	TestAsset[13] = graph->NewSprite(&str, 255, 0, 255);

	str = "../assets/Runner_Tubing.bmp";
	TestAsset[14] = graph->NewSprite(&str, 255, 0, 255);

}

void Drawer::DrawBackgrounds(Graphics* graph)
{
	if (BackgroundFrame > 20) BackgroundFrame == 0;

	graph->DrawSprite(TestAsset[6], 0, 0);

	graph->DrawSprite(TestAsset[7], 0, 162, 150);
	graph->DrawSprite(TestAsset[7], 320, 162, 150);
	graph->DrawSprite(TestAsset[8], 0 + BackgroundFrame, 162, 100);
	graph->DrawSprite(TestAsset[9], 300 - BackgroundFrame, 162, 120);

	BackgroundFrame++;
}


void Drawer::UpdateSprite(Runner * runner, Graphics * graph, Input* input)
{
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


void Drawer::UpdateSprite(Object* object, Graphics* graph, Builder * builder)
{
	if (object == builder->CurrentLevel->teleport)
	{
		if (builder->CurrentLevel->teleport->IsOn)
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