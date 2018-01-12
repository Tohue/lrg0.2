#ifndef PATHFINDER_H
#define PATHFINDER_H
#include <list>
#include "Object.h"

class Path;

/*!
\brief Builds the paths for robots
PathFinder checks every path object to build up an optimal route for robot to runner
*/

class PathFinder
{
private:
	int PathArray[25][20];
	int px[300], py[300];      
	int len;                       
public:
	/*!
	\brief Records into private array the possible map routes
	\param[in] PathList - The list of Path objects to look up their coordinates and memorize them
	*/
	void GetPath(std::list<Path*> PathList);
	/*!
	\brief Finds an optimal route from one coordinates to another using the waving method
	\param[in] enemy_x - robot X coordinate
	\param[in] enemy_y - robot Y coordinate
	\param[in] player_x - runner X coordinate
	\param[in] player_y - runner Y coordinate
	*/
	int FindPath(int enemy_x, int enemy_y, int player_x, int player_y);
	/*!
	\brief The getter of the x coordinate of the next block in path
	*/
	int GetNextPathX();
	/*!
	\brief The getter of the y coordinate of the next block in path
	*/
	int GetNextPathY();



};


#endif