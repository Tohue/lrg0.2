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

void LevelManager::LoadLevel(char LevelNumber)
{


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
	file.close();
}
