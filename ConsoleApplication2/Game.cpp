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
	int i;


	//THE MAIN CYCLE STARTS HERE
	while (IsOn) 
	{
		input->Update();

		//COLLISIONCHECK BLOCK
		std::list<Object*>::iterator it = builder->ObjectList.begin();
		while ((++it != builder->ObjectList.end()) && (!charcont->CollisionCheckResult))
		{
			//First off we need to check if there is any block under the legs thru the gridding method
			charcont->IsStanding = (collider->CheckStanding(builder->runner, *it));
			//If the collision happens
			if (collider->CollisionCheck(builder->runner, *it, builder))
			//We tell charcont if there are some ladders to climb
				if ((*it)->Climbable)
				{
					charcont->LadderCol = (*it);
					charcont->LadderCollision = true;
					
				}
			//Finally we'll try avoid the blocks we don't want to get into
				else
				charcont->CollisionCheckResult = true;
		}
		charcont->CollisionCheckResult = false;

		for (std::list<Object*>::iterator it = builder->ObjectList.begin(); it != builder->ObjectList.end(); ++it)
			drawer->UpdateSprite(*it, graph);

		charcont->UpdateCoords(builder->runner, input, collider);
		drawer->UpdateSprite(builder->runner, GetGraphics(), GetInput());
	


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

