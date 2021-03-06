#ifndef GAME_H
#define GAME_H
#include "stdafx.h"
#include "SDL.h"
#include "Graphics.h"
#include "Game.h"
#include "Sprite.h"
#include "CharacterController.h"
#include "Builder.h"
#include "Drawer.h"
#include "Levelmanager.h"

class Graphics;
//this input dec mb not needed, just for test r/n
class Input;

class Game
{


private:
	bool IsOn;
	//Main engine classes (CHADS)
	Graphics* graph;
	Input* input;

	//virgin edgy classes
	Builder* builder;
	Drawer* drawer;
	CharacterController* charcont;
	LevelManager* lvlman;

	//4test delet pls
	Sprite* test;
public:
	Game* game;


	Graphics* GetGraphics();
	Input* GetInput();
	
	Game();
	int Run(int x, int y);
	void Exit();
};

#endif
