#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "stdafx.h"
#include "SDL.h"
#include "Sprite.h"
#include <String>

class Sprite;


/*!

\brief This class is controlling all the graphic part of the game.

The Graphics class draws images on screen, updating them every frame by filling the whole window with black color and redrawing
everything again.Though it might seem like a bad, unnesessary idea, that's how every game works.

*/

class Graphics {
private:

	SDL_Surface* Screen;
	SDL_Window* Window;
	SDL_Renderer* Renderer;

public:


	Sprite* test;

	/*!
	\brief Constructor takes the X and Y values from Game->Run() method, and then creates window with this resolution.
	\param[in] x - the X axis of the creating window 
	\param[in] y - the Y axis of the creating window
	*/
	Graphics(int x, int y);

	/*!

	\brief Updates SDL window, turns the whole black to draw everything again next tick. 
	
	*/

	void UpdateGraphics();

	/*!

	\brief Destroys both Window and Renderer objects.

	*/

	void ShutDownGraphics();
	/*!

	\brief This function turns window into fullscreen mode
	\warning It was a test material so it seems not working properly and not needed in the final version

	*/

	int ToggleFullScreen();

	/*!

	\brief Creates a new sprite from specific file path

	*/
	Sprite* NewSprite(std::string* file);
	/*!

	\brief Creates a new sprite from specific file path with adding an alpha-channel to it so the picked color would be transparent
	\param[in] file - the string containing the file path of the sprite
	\param[in] r - Red value of transparent rgb layer
	\param[in] g - Green value of transparent rgb layer
	\param[in] b - Blue value of transparent rgb layer

	*/
	Sprite* NewSprite(std::string* file, int r, int g, int b);

	/*!
	\brief Draws the sprite on the coordinates
	\param[in] img - an image to draw
	\param[in] x - the x coordinate on the screen
	\param[in] y - the y coordinate on the screen 
	*/
	bool DrawSprite(Sprite* img, int x, int y);
	/*!
	\brief Draws the sprite on the coordinates with a specific amount of transparency on the transparent layer
	\param[in] img - an image to draw
	\param[in] x - the x coordinate on the screen
	\param[in] y - the y coordinate on the screen
	\param[in] alpha - amount of transparency
	*/
	bool DrawSprite(Sprite * img, int x, int y, int alpha);
	/*!

	\brief Cuts the sprite from the sheet and then draws it on the coordinates
	\param[in] img - an image to draw
	\param[in] x - the x coordinate on the screen
	\param[in] y - the y coordinate on the screen
	\param[in] startX - x value of coordinate where the cutting part of a tile begins
	\param[in] startY - y value of coordinate where the cutting part of a tile begins
	\param[in] endX - x value of coordinate where the cutting part of a tile ends
	\param[in] endY - y value of coordinate where the cutting part of a tile ends
	*/
	bool DrawSprite(Sprite* img, int x, int y, int startX, int startY, int endX, int endY);
	/*!

	\brief Cuts the sprite from the sheet, makes it transparent and then draws it on the coordinates
	\param[in] img - an image to draw
	\param[in] x - the x coordinate on the screen
	\param[in] y - the y coordinate on the screen
	\param[in] startX - x value of coordinate where the cutting part of a tile begins
	\param[in] startY - y value of coordinate where the cutting part of a tile begins
	\param[in] endX - x value of coordinate where the cutting part of a tile ends
	\param[in] endY - y value of coordinate where the cutting part of a tile ends
	\param[in] alpha - amount of transparency
	*/
	bool DrawSprite(Sprite * img, int x, int y, int startX, int startY, int endX, int endY, int alpha);

};

#endif