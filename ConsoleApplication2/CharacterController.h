#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "SDL.h"
#include "Character.h"
#include "Graphics.h"
#include "Input.h"
#include "Builder.h"
#include "Object.h"
#include "Collider.h"
#include "PathFinder.h"


class Object;
class Runner;
class Robot;
class Point;

/*!
\brief Enum for checking what's going on with main character
*/

enum states { Running, Digging, Falling, Climbing, Tubing };

class CharacterController
{

private:
	int DiggingTimer = 0;
	int CoinsCaptured;
	bool IsStanding = true;
	bool CollisionCheckResult = false;
	bool LadderCollision = false;
	bool TubeCollision = false;
	bool LeftCol = false;
	bool RightCol = false;
	Object* LadderCol;
	Object *LeftDel;
	Object *RightDel;
	Object *BottomBlock;
public:
	friend class Collider;
	states state = Running;

	bool IsClimbing(); ///< for climbing updates
	bool IsTubing(); ///< for updates when the character is climbing on tube

	/*!
	\brief Updates the state of the runner
	\param[out] runner - what runner should be checked 
	\param[in] input - an input object so we can check if something is pressed
	*/
	states UpdateCharacterState(Runner* runner, Input* input);
	/*!
	\brief Updates runners coordinates if something is pressed
	\param[out] runner - what runner should be moved
	\param[in] input - an input object so we can check if something is pressed
	*/
	void UpdateCoords(Runner * runner, Input* input, Collider* collider);
	/*!
	\brief The third update if the character happens to be running
	\param[out] runner
	\param[in] input
	*/
	void RunningUpdate(Runner * runner, Input* input);
	/*!
	\brief The third update if the character happens to be falling
	\param[out] runner
	*/
	void FallingUpdate(Runner * runner);
	/*!
	\brief The third update if the character happens to be digging
	\param[out] runner
	\param[in] collider
	*/
	void DiggingUpdate(Runner* runner, Collider* collider);
	/*!
	\brief Updates the specific robot coordinates
	\param[out] robot - the robot which is being moved
	\param[in] input
	\param[in] runner - to check the paths to the character
	\param[out] pathf - path controller to update the paths if needed
	\param[in] points - the list of points where the robot whould fall into the pit
	*/
	void UpdateRobotCoords(Robot* robot, Input* input, Runner* runner, PathFinder* pathf, std::list<Point*> points);
	/*!
	\brief A function to move robot in the direction of path
	\param[out] robot - robot to move
	\param[in] x - the X of next path block
	\param[in] y - the Y of next path block
	*/
	void MoveRobot(Robot* robot, int x, int y);
};

#endif

