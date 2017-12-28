#include "stdafx.h"
#include "LevelManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <errno.h>
#include <set>

int LevelManager::getlevel()
{
	return CurrentLevel;
}

void LevelManager::GoToMenu(Builder * builder)
{

	if (builder->CurrentLevel != NULL)
	{
		EndLevel(builder);
	}
	
	

	st = InMenu;


}

void LevelManager::LoadLevel(char LevelNumber)
{

	if (st == InMenu) st = Playing;

	std::string tmp("../levels/");
	tmp = tmp + LevelNumber;
	int lt = 0;
	int i = 0;
	std::ifstream file(tmp);					
	while ((lt = file.get()) != EOF)
	{
		if	(lt != '\n')
			LevelStruct[i] = lt;
		i++;
	}
	LevelStruct[i] = LevelNumber;
	file.close();
}

void LevelManager::EndLevel(Builder* builder)
{

	delete (builder->CurrentLevel);
	builder->Destroy();

}

void LevelManager::NextLevel(Builder * builder, PathFinder * pathf)
{
	int LevelNumber = builder->CurrentLevel->GetLevelNumber();
	EndLevel(builder);
	LevelNumber++;
	LoadLevel((char)LevelNumber);
	builder->Build(LevelStruct);
	pathf->GetPath(builder->PathList);
}
