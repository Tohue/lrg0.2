#ifndef DRAWER_H
#define DRAWER_H

#include "SDL.h"
#include "Character.h"
#include "Graphics.h"
#include "Input.h"
#include "Builder.h"
#include "Sprite.h"
#include "Object.h"


class Builder;
class Graphics;

class Drawer
{
private:
	int RightFrame = 1;
	int LeftFrame = 1;
	int UpFrame = 1;
	int DownFrame = 1;
public:
	Sprite* TestAsset[5];
	Drawer(Graphics* graph);

	void UpdateSprite(Runner* runner, Graphics* graph, Input* input);
	void UpdateSprite(Object* object, Graphics* graph);
	void UpdateSprite(Robot* robot, Graphics* graph);


};



#endif