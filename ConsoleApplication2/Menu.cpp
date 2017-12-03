#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	ButtonList.clear();
	int i;
	for (i = 0; i < 3; i++)
	{
		Button * button = new Button();
		button->x = 400;
		button->y = 180 + i * 96;
		button->number = i;
		if (i == 0) button->state = Active;
		ButtonList.push_back(button);

	}
}

void Menu::UpdateMenu(Input * input, Builder* builder, LevelManager* lvlman)
{
	int numb;
	for (std::list<Button*>::iterator it = ButtonList.begin(); it != ButtonList.end(); ++it)
		if ((*it)->state == Active) numb = (*it)->number;
	if (input->KeyDown(SDL_SCANCODE_UP))
	{
		if (numb != 0)
		{
			for (std::list<Button*>::iterator it = ButtonList.begin(); it != ButtonList.end(); ++it)
			{
				if ((*it)->number == numb - 1) (*it)->state = Active;
				if ((*it)->number == numb) (*it)->state = Passive;

			}

		}

	}


	if (input->KeyDown(SDL_SCANCODE_DOWN))
	{

		if (numb != 2)
		{
			for (std::list<Button*>::iterator it = ButtonList.begin(); it != ButtonList.end(); ++it)
			{
				if ((*it)->number == numb + 1) (*it)->state = Active;
				if ((*it)->number == numb) (*it)->state = Passive;

			}

		}

	}

	if (input->KeyDown(SDL_SCANCODE_RETURN))

	{
		if (numb == 0)
		{
			lvlman->LoadLevel('1');
			builder->Build(lvlman->LevelStruct);
		}

	}

}

int Button::GetNumber()
{
	return number;
}

int Button::Getx()
{
	return x;
}

int Button::Gety()
{
	return y;
}
