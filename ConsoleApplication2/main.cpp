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
	

};

int main(int argc, char* argv[])
{
	Game game;
	return game.Run(640,480);
}