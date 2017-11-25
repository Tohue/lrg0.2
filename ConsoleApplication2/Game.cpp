#include "SDL.h"
#include "Game.h"
#include <iostream>
#include <list>
#include <iterator>


Game::Game()
{
	IsOn = true;
	
	builder = new Builder();
	charcont = new CharacterController();
	collider = new Collider();
	
}

int Game::Run(int x, int y)
{

	graph = new Graphics(x, y);
	input = new Input();
	drawer = new Drawer(graph);
	lvlman = new LevelManager();
	lvlman->LoadLevel('1');
	builder->Build(lvlman->LevelStruct);
	bool StandChecker = true;
	bool LadderChecker = false;

	//THE MAIN CYCLE STARTS HERE
	while (IsOn) 
	{
		input->Update();
		drawer->DrawBackgrounds(graph);
		//COLLISIONCHECK BLOCK
		//move this to some other class func
		std::list<Object*>::iterator it = builder->ObjectList.begin();
		while (++it != builder->ObjectList.end())
		{
			//First off we need to check if there is any block under the legs thru the gridding method
			if ((collider->CheckStanding(builder->runner, *it))|| (charcont->state == Climbing))
					StandChecker = true;
			//If the collision happens
			if (collider->CollisionCheck(builder->runner, *it, builder))
				//We tell charcont if there are some ladders to climb
				if ((*it)->Climbable)
				{
					if (charcont->LadderCol != (*it)) charcont->LadderCol = (*it);
					LadderChecker = true;
				}
			//Finally we'll try avoid the blocks we don't want to get into
				else
				{
					if ((builder->runner->getx() + 32 >= (*it)->getx()) && (builder->runner->getx() + 32 <= (*it)->getx() + 32))
					{
						if ((builder->runner->gety() >= (*it)->gety()) && (builder->runner->gety() <= (*it)->gety() + 32))
							charcont->RightCol = true;
						if ((builder->runner->gety() < (*it)->gety()) && (builder->runner->gety() + 32 >= (*it)->gety() + 10))
							charcont->RightCol = true;
					}

					if ((builder->runner->getx() <= (*it)->getx() + 32) && (builder->runner->getx() >= (*it)->getx()))
						{
						if ((builder->runner->gety() >= (*it)->gety()) && (builder->runner->gety() <= (*it)->gety() + 32))
								charcont->LeftCol = true;
								
						if ((builder->runner->gety() < (*it)->gety()) && (builder->runner->gety() + 32 >= (*it)->gety() + 10))
								charcont->LeftCol = true;
						}
				}

		}
		if (LadderChecker)
			charcont->LadderCollision = true;
		else
			charcont->LadderCollision = false;
		charcont->IsStanding = StandChecker;

		for (std::list<Object*>::iterator it = builder->ObjectList.begin(); it != builder->ObjectList.end(); ++it)
			drawer->UpdateSprite(*it, graph);

		charcont->UpdateCoords(builder->runner, input, collider);
		drawer->UpdateSprite(builder->runner, GetGraphics(), GetInput());
		StandChecker = false;
		LadderChecker = false;
		charcont->LeftCol = false;
		charcont->RightCol = false;

		if (input->KeyDown(SDL_SCANCODE_F4))
			graph->ToggleFullScreen();

		graph->UpdateGraphics();
	}
	SDL_Quit;
	graph->ShutDownGraphics();
	return 0;
}

Graphics* Game::GetGraphics()
{

	return graph;

}

Input* Game::GetInput()
{

	return input;

}


void Game::Exit()
{
	IsOn = false;

}

