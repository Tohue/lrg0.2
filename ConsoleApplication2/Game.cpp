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
	lvlman->LoadLevel('1');
	builder->Build(lvlman->LevelStruct);

	//THE MAIN CYCLE STARTS HERE
	while (IsOn) 
	{
		input->Update();
		drawer->DrawBackgrounds(graph);
		collider->UpdateCollisions(builder, charcont, GetInput(), lvlman);
		soundman->UpdateSounds(builder, charcont, input);
		for (std::list<Object*>::iterator it = builder->ObjectList.begin(); it != builder->ObjectList.end(); ++it)
			drawer->UpdateSprite(*it, graph, builder);
		drawer->UpdateSprite(builder->runner, GetGraphics(), GetInput());
		drawer->UpdateScoreSprite(graph, builder);
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

