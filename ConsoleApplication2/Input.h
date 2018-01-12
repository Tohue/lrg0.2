#ifndef INPUT_H
#define INPUT_H
#include "stdafx.h"
#include "SDL.h"

/*!
\brief The class that detects any inputs from the player

This class works with keyboard, detects what buttons are pressed and released

*/


class Input {
private:
	SDL_Event InputEvent;

public:
	/*!
	\brief Polling the input event to check if something is pressed
	*/
	void Update();
	/*!
	\brief Check if the key is down
	\param[in] key - what keycode should be checked
	\return true if the key is pressed
	*/
	bool KeyDown(SDL_Scancode key);
	/*!
	\brief Check if the key is down
	\param[in] key - what SDL_Scancode should be checked
	\return true if the key is pressed
	*/
	bool KeyDown(SDL_Keycode key);
	/*!
	\brief Check if the key is just released
	\param[in] key - what SDL_Scancode should be checked
	\return true if the key is just released
	*/
	bool KeyUp(SDL_Scancode key);
	/*!
	\brief Check what key is recently pressed
	\return key which was pressed the most recently
	*/
	SDL_Scancode PressedKey();
};
#endif
