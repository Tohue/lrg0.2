#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "stdafx.h"
#include "SDL.h"
#include "Sprite.h"
#include <String>

class Sprite;

class Graphics {
private:

	SDL_Surface* Screen;
	SDL_Window* Window;
	SDL_Renderer* Renderer;

public:


	Sprite* test;


	Graphics(int x, int y);
	void UpdateGraphics();
	void ShutDownGraphics();


	//TODO: Implement some functions like following to make the window updates fancier
	//Maybe need a controller for such a thing
	int ToggleFullScreen();

	Sprite* NewSprite(std::string* file);
	Sprite* NewSprite(std::string* file, int r, int g, int b);
	bool DrawSprite(Sprite* img, int x, int y);
	bool DrawSprite(Sprite * img, int x, int y, int alpha);
	bool DrawSprite(Sprite* img, int x, int y, int startX, int startY, int endX, int endY);

};

#endif