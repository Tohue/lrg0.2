#ifndef SPRITE_H
#define SPRITE_H

#include "Graphics.h"

class Sprite
{
private:
	SDL_Surface* surface;

public:
	friend class Graphics;



	int GetWidth();
	int GetHeight();
};

#endif