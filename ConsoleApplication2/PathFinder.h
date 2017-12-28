#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <list>
#include "Object.h"

class Path;

class PathFinder
{
private:
	int PathArray[25][20];
	int px[300], py[300];      
	int len;                       
public:
	void GetPath(std::list<Path*> PathList);
	int FindPath(int enemy_x, int enemy_y, int player_x, int player_y);
	int GetNextPathX();
	int GetNextPathY();



};


#endif