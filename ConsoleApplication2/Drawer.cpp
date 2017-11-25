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
	str = "../assets/test_ladder.bmp";
	TestAsset[5] = graph->NewSprite(&str);
	str = "../assets/Background1.bmp";
	TestAsset[6] = graph->NewSprite(&str);

}

void Drawer::DrawBackgrounds(Graphics* graph)
{
	graph->DrawSprite(TestAsset[6], 0, 0);
}


void Drawer::UpdateSprite(Runner * runner, Graphics * graph, Input* input)
{

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


void Drawer::UpdateSprite(Object* object, Graphics* graph)
{


	if (object->Climbable == true)
	graph->DrawSprite(TestAsset[5], object->getx(), object->gety());
	else
	graph->DrawSprite(TestAsset[0], object->getx(), object->gety());

}