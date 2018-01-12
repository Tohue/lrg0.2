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
#include "Collider.h"
#include "Sound.h"

class Graphics;



/*!
\brief The main class of the whole game

This class is a "bones" of the project. It starts the whole game process, it loops all the events every tick,
and when everything is done, it shuts the program.



*/

class Game
{


private:
	bool IsOn; ///< variable telling if the game still running
	//Main engine classes
	Graphics* graph;
	Input* input;

	//other classes
	Builder* builder;
	Drawer* drawer;
	CharacterController* charcont;
	LevelManager* lvlman;
	Collider* collider;
	SoundManager* soundman;
	PathFinder* pathf;

public:
	Game* game;

	/*!
	\brief The getter of the games mounted graphics
	*/
	Graphics* GetGraphics();
	/*!
	\brief The getter of the games mounted input
	*/
	Input* GetInput();
	/*!
	\brief Games constructor; makes IsOn boolean true and creates all needed game objects
	*/
	Game();
	/*!
	\brief The main function of the game

	This function contains some pre-launch definitions and the most important thing - the game loop.
	Here in the loop all the controller classes check game objects states and updating them, if it is needed.

	\param[in] x - The X value of the screen size
	\param[in] y - The Y value of the screen size
	*/
	int Run(int x, int y);
	/*!
	\brief The function called when the game is shutting down.
	*/
	void Exit();
};

#endif
