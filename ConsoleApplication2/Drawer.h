#ifndef DRAWER_H
#define DRAWER_H

#include "SDL.h"
#include "Character.h"
#include "Graphics.h"
#include "Input.h"
#include "Builder.h"
#include "Sprite.h"
#include "Object.h"
#include "LevelManager.h"

class Builder;
class Graphics;


/*!
\brief Draws the images onto the screen using Graphics
*/

class Drawer
{
private:
	int RightFrame = 0;
	int LeftFrame = 0;
	int ClimbFrame = 0;

	int rRightFrame = 0;
	int rLeftFrame = 0;
	int rClimbFrame = 0;


	int BackgroundFrame = 0;
	int TubingFrame = 0;
	int LeftDigFrame = 0;
	int RightDigFrame = 0;
	int LightFrame = 0;
public:
	Sprite* TestAsset[30]; ///< Here loads every sprite in the game
	Sprite* FXAsset[20]; ///< This is the true testing asset!
	/*!
	\brief The constructor loads every sprite into special asset
	\param[in] graph - Graphics object which creates sprites
	*/
	Drawer(Graphics* graph);
	/*!
	\brief Draws the background images
	\param[in] graph - Graphics object to actually draw
	\param[in] lvlman - to check what level it is
	*/
	void DrawBackgrounds(Graphics * graph, LevelManager* lvlman);
	/*!
	\brief Updates runners sprite
	\param[in] runner
	\param[in] graph - Graphics object to actually draw
	\param[in] input - to check if something is pressed
	*/
	void UpdateSprite(Runner* runner, Graphics* graph, Input* input);
	/*!
	\brief Additional sprite update
	\param[in] builder - to check some variables from builder
	\param[in] graph - Graphics object to actually draw
	*/
	void UpdateSprite(Builder* builder, Graphics* graph);
	/*!
	\brief Updates objects sprite
	\param[in] object -an object from list
	\param[in] graph - Graphics object to actually draw
	\param[in] builder -  To check if the teleporter is on
	*/
	void UpdateSprite(Object* object, Graphics* graph, Builder * builder);
	/*!
	\brief Updates robots sprite
	\param[in] robot
	\param[in] graph - Graphics object to actually draw
	*/
	void UpdateSprite(Robot* robot, Graphics* graph);
	/*!
	\brief Updates scores
	\param[in] graph - Graphics object to actually draw
	\param[in] builder - to check the actual score value
	*/
	void UpdateScoreSprite(Graphics* graph, Builder * builder);

};



#endif