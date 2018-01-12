#ifndef SPRITE_H
#define SPRITE_H

#include "Graphics.h"

/*!
\brief Contains information about a bitmap image
Contains information about a bitmap image and is used by Graphics to draw it
*/

class Sprite
{
private:
	SDL_Surface* surface;

public:
	friend class Graphics;


	/*!
	\brief Getter of image's width
	*/
	int GetWidth();
	/*!
	\brief Getter of image's height
	*/
	int GetHeight();
};

#endif