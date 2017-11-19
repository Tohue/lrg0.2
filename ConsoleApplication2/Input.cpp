#include "stdafx.h"
#include "Input.h"


void Input::Update()
{

	while (SDL_PollEvent(&InputEvent));

}

bool Input::KeyDown(SDL_Scancode key)
{

	return (InputEvent.type == SDL_KEYDOWN && InputEvent.key.keysym.scancode == key);

}


bool Input::KeyUp(SDL_Scancode key)
{

	return (InputEvent.type == SDL_KEYUP && InputEvent.key.keysym.scancode == key);

}

SDL_Scancode Input::PressedKey()

{

	return (InputEvent.key.keysym.scancode);

}
