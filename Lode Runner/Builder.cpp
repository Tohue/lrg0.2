#include "stdafx.h"
#include "Builder.h"
#include <iostream>
#include <list>
#include <string>
#include <set>

void Builder::Build(char LevelStruct[])
{

	char ObjectMaps[] = { '*', '_', '@' , '#'};
	std::set<char> a(ObjectMaps, ObjectMaps + 4);

	memset(grid, 0, sizeof grid);

	//Loading level structure
	int j;
	int k = 0;

	for (j = 0; j < 15; j++)
	{
		
			for (i = 0; i < 21; i++)
		{
			if (a.find(LevelStruct[k]) != a.end())
			{
				grid[i][j] = LevelStruct[k];
				
			}
			k++;
		}
	}

	//Decoding level structure
	for (j = 0; j < 15; j++)
	
	{
		for (i = 0; i < 21; i++)
		{
			if (grid[i][j] == '*')
			{
				Object* block = new Block();
				block->x = i * GRID_SIZE;
				block->y = j * GRID_SIZE;
				ObjectList.push_back(block);

			}
			if (grid[i][j] == '@')
			{
				runner = new Runner();
				runner->setdir(Left);
				runner->x = i * GRID_SIZE;
				runner->y = j * GRID_SIZE;
			}
			if (grid[i][j] == '#')
			{
				Ladder* ladder = new Ladder();
				ladder->x = i * GRID_SIZE;
				ladder->y = j * GRID_SIZE;
				ObjectList.push_back(ladder);

			}

		}
	}
}

