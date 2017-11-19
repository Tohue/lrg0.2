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
		
		charcont->IsStanding = false;
		charcont->LadderCollision = false;
		charcont->CollisionCheckResult = false;
		std::list<Object*>::iterator it = builder->ObjectList.begin();
		while ((++it != builder->ObjectList.end()) && (!charcont->CollisionCheckResult))
		{
			//First off we need to check if there is any block under the legs thru the gridding method
			charcont->CheckStanding(builder->runner, *it);
			//Then we check if there are some ladders to climb
			if ((*it)->Climbable)
			{
				if (charcont->LadderCollisionCheck(builder->runner, *it, builder, input))
					charcont->LadderCollision = true;
			}
			else
				//Finally we check the blocks we don't want to get into
				if (charcont->CollisionCheck(builder->runner, *it, builder))
					charcont->CollisionCheckResult = true;
		}
		if (charcont->IsStanding == false)
		{
			//std::cout << "zemlya te puxom\n";
			charcont->state = Falling;
		}
			


		for (std::list<Object*>::iterator it = builder->ObjectList.begin(); it != builder->ObjectList.end(); ++it)
			drawer->UpdateSprite(*it, graph);

		charcont->UpdateCoords(builder->runner, input);
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

