#include "stdafx.h"
#include "Drawer.h"
#include <String>

Drawer::Drawer(Graphics* graph)
{
	std::string str = "../assets/test_brick.bmp";
	TestAsset[0] = graph->NewSprite(&str);
	str = "../assets/test_left.bmp";
	TestAsset[1] = graph->NewSprite(&str);
	str = "../assets/test_right.bmp";
	TestAsset[2] = graph->NewSprite(&str);
	str = "../assets/test_up.bmp";
	TestAsset[3] = graph->NewSprite(&str);
	str = "../assets/test_down.bmp";
	TestAsset[4] = graph->NewSprite(&str);
	str = "../assets/test_ladder.bmp";
	TestAsset[5] = graph->NewSprite(&str);

}

void Drawer::UpdateSprite(Runner * runner, Graphics * graph, Input* input)
{

	if (runner->getdir() == Left)
	{

		if (input->KeyDown(SDL_SCANCODE_LEFT))
			switch (LeftFrame)
			{
			case 1:
				graph->DrawSprite(TestAsset[1], runner->getx(), runner->gety(), 0, 0, 32, 32);
				LeftFrame++;
				break;
			case 2:
				graph->DrawSprite(TestAsset[1], runner->getx(), runner->gety(), 32, 0, 32, 32);
				LeftFrame++;
			case 3:
				graph->DrawSprite(TestAsset[1], runner->getx(), runner->gety(), 64, 0, 32, 32);
				LeftFrame = 1;
				break;
			}
		else
			graph->DrawSprite(TestAsset[1], runner->getx(), runner->gety(), 0, 0, 32, 32);
	}

	if (runner->getdir() == Right)
	{
		if (input->KeyDown(SDL_SCANCODE_RIGHT))
			switch (RightFrame)
			{
			case 1:
				graph->DrawSprite(TestAsset[2], runner->getx(), runner->gety(), 0, 0, 32, 32);
				RightFrame++;
				break;
			case 2:
				graph->DrawSprite(TestAsset[2], runner->getx(), runner->gety(), 32, 0, 32, 32);
				RightFrame++;
			case 3:
				graph->DrawSprite(TestAsset[2], runner->getx(), runner->gety(), 64, 0, 32, 32);
				RightFrame = 1;
				break;
			}
		else 
			graph->DrawSprite(TestAsset[2], runner->getx(), runner->gety(), 0, 0, 32, 32);
	}

	if (runner->getdir() == Up)
	{
		graph->DrawSprite(TestAsset[3], runner->getx(), runner->gety());
	}

	if (runner->getdir() == Down)
	{
		graph->DrawSprite(TestAsset[4], runner->getx(), runner->gety());
	}


}


void Drawer::UpdateSprite(Object* object, Graphics* graph)
{
	if (object->Climbable == true)
	graph->DrawSprite(TestAsset[5], object->getx(), object->gety());
	else
	graph->DrawSprite(TestAsset[0], object->getx(), object->gety());

}