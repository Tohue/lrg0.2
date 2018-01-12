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
	soundman = new SoundManager();
	drawer = new Drawer(graph);
	lvlman = new LevelManager();
	pathf = new PathFinder();


	lvlman->GoToMenu(builder);
	builder->BuildMenu();

	//THE MAIN CYCLE STARTS HERE
	while (IsOn) 
	{
		input->Update();
		drawer->DrawBackgrounds(graph, lvlman);

		if (lvlman->st != InMenu)
		{
			soundman->UpdateSounds(builder, charcont, input);
			collider->UpdateCollisions(builder, charcont, GetInput(), lvlman, soundman, pathf, collider);
			for (std::list<Object*>::iterator it = builder->ObjectList.begin(); it != builder->ObjectList.end(); ++it)
				drawer->UpdateSprite(*it, graph, builder);
			for (std::list<Robot*>::iterator it1 = builder->EnemyList.begin(); it1 != builder->EnemyList.end(); ++it1)
			{

				charcont->UpdateRobotCoords((*it1), input, builder->runner, pathf, collider->FallPoints);
				drawer->UpdateSprite(*it1, graph);
			}
				
			drawer->UpdateSprite(builder->runner, GetGraphics(), GetInput());
			drawer->UpdateScoreSprite(graph, builder);
		}
		else
		{
			drawer->UpdateSprite(builder, graph);
			builder->menu->UpdateMenu(input, builder,lvlman, pathf);
		}
		
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

