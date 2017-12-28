#include "Builder.h"
#include <iostream>
#include <list>
#include <string>
#include <set>

void Builder::Destroy()
{
	ObjectList.clear();
	PathList.clear();
	EnemyList.clear();
	delete(runner);

}

void Builder::Build(char LevelStruct[])
{
	//if (CurrentLevel != NULL)
		//delete CurrentLevel;

	CurrentLevel = new Level();

	char ObjectMaps[] = {'-','R', '$', '@' , '#', '1', '&', '_'};
	std::set<char> a(ObjectMaps, ObjectMaps + 9);

	memset(grid, 0, sizeof grid);

	//Loading level structure
	int j,m;
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
	while (LevelStruct[k] != NULL) k++;
	CurrentLevel->SetLevelNumber((int)LevelStruct[k - 1]);


	if (CurrentLevel == NULL) Destroy();


	int CoinCount = 0;

	//Decoding level structure
	for (j = 0; j < 15; j++)
	
	{
		for (i = 0; i < 21; i++)
		{


			if (grid[i][j] == '_')
			{
				Path* path = new Path();
				path->x = i * GRID_SIZE;
				path->y = (j) * GRID_SIZE;
				PathList.push_back(path);
			}


			if (grid[i][j] == '&')
			{
				Robot* robot = new Robot();
				robot->x = i * GRID_SIZE;
				robot->y = j * GRID_SIZE;
				EnemyList.push_back(robot);

				Path* path = new Path();
				path->x = i * GRID_SIZE;
				path->y = (j) * GRID_SIZE;
				PathList.push_back(path);

			}

			if (grid[i][j] == '1')
			{
				Object* block = new Block();
				block->x = i * GRID_SIZE;
				block->y = j * GRID_SIZE;
				ObjectList.push_back(block);
			}

			if (grid[i][j] == 'R')
			{
				runner = new Runner();
				runner->setdir(Left);
				runner->x = i * GRID_SIZE;
				runner->y = j * GRID_SIZE + 3;

				Path* path = new Path();
				path->x = i * GRID_SIZE;
				path->y = (j)* GRID_SIZE;
				PathList.push_back(path);
			}
			if (grid[i][j] == '#')
			{
				bool NoUpperParts = false;
				bool NoPartsLower = false;
				if (grid[i][j + 1] != '#')
					NoPartsLower = true;
				if (grid[i][j - 1] != '#')
					NoUpperParts = true;
				Ladder* ladder = new Ladder(NoUpperParts, NoPartsLower);
				ladder->x = i * GRID_SIZE;
				ladder->y = j * GRID_SIZE;
				ObjectList.push_back(ladder);
		
				Path* path = new Path();
				path->x = ladder->x;
				path->y = ladder->y;
				PathList.push_back(path);
				

			}

			if (grid[i][j] == '$')
			{
				Coin* coin = new Coin();
				coin->x = i * GRID_SIZE;
				coin->y = j * GRID_SIZE;
				ObjectList.push_back(coin);
				CoinCount++;

				Path* path = new Path();
				path->x = i * GRID_SIZE;
				path->y = (j)* GRID_SIZE;
				PathList.push_back(path);
			}

			if (grid[i][j] == '@')
			{
				Teleporter* teleport = new Teleporter();
				teleport->x = i * GRID_SIZE;
				teleport->y = j * GRID_SIZE;
				ObjectList.push_back(teleport);
				CurrentLevel->teleport = teleport;

				Path* path = new Path();
				path->x = i * GRID_SIZE;
				path->y = (j)* GRID_SIZE;
				PathList.push_back(path);
			}

			if (grid[i][j] == '-')
			{
				Tube* tube = new Tube();
				tube->x = i * GRID_SIZE;
				tube->y = j * GRID_SIZE;
				ObjectList.push_back(tube);


				Path* path = new Path();
				path->x = i * GRID_SIZE;
				path->y = (j)* GRID_SIZE;
				PathList.push_back(path);
			}

		}

		
	}
	CurrentLevel->SetScoreToFinish(CoinCount);

}

void Builder::BuildMenu()
{
	if (menu != NULL) delete(menu);
	menu = new Menu();
}

