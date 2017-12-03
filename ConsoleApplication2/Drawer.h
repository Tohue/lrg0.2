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

class Drawer
{
private:
	int RightFrame = 0;
	int LeftFrame = 0;
	int ClimbFrame = 0;
	int BackgroundFrame = 0;
	int TubingFrame = 0;
	int LeftDigFrame = 0;
	int RightDigFrame = 0;
	int LightFrame = 0;
public:
	Sprite* TestAsset[30];
	Sprite* FXAsset[20];
	Drawer(Graphics* graph);

	void DrawBackgrounds(Graphics * graph, LevelManager* lvlman);

	void UpdateSprite(Runner* runner, Graphics* graph, Input* input);
	void UpdateSprite(Builder* builder, Graphics* graph);
	void UpdateSprite(Object* object, Graphics* graph, Builder * builder);
	void UpdateSprite(Robot* robot, Graphics* graph);
	void UpdateScoreSprite(Graphics* graph, Builder * builder);

};



#endif