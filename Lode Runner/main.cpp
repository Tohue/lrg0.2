#include "stdafx.h"
#include "SDL.h"
#include "Graphics.h"
#include "Game.h"
#include "Input.h"
#include "CharacterController.h"

class CharacterController;


class Main
{
public:
	
	//Here must be GetGrph and GetInput from the game object
	//It seems like there is no other way to the game object tho

};

int main(int argc, char* argv[])
{
	Game game;
	return game.Run(640,480);
}