#ifndef INPUT_H
#define INPUT_H
#include "stdafx.h"
#include "SDL.h"


class Input {
private:
	SDL_Event InputEvent;

public:
	void Update();
	bool KeyDown(SDL_Scancode key);
	bool KeyUp(SDL_Scancode key);
	SDL_Scancode PressedKey();
};
#endif
