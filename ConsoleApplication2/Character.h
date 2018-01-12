#ifndef CHARACTER_H
#define CHARACTER_H
#include "SDL.h"
#include "Builder.h"

/*!
\brief The nice little thing that helps us with sprites and inputs
This tells other objects what direction the character is going/looking at
Extremely useful with the drawer
*/
enum direction {Up, Down, Left, Right, ClimbLeft, ClimbRight, DigLeft, DigRight};

/*!
\brief The basic character class
This class contains methods and variables that every type of character can use
*/

class Character
{
	
	
protected:
	direction dir = Left;
	int x, y;
	int Speed;
	/*!
	\brief A setter of character direction
	\param[in] newdir - new character direction
	*/
	direction setdir(direction newdir);
	
public:
	/*!
	\brief A getter of direction
	*/
	direction getdir();
	/*!
	\brief X coordinate getter
	*/
	int getx();
	/*!
	\brief Y coordinate getter
	*/
	int gety();
	friend class Builder;
	friend class CharacterController;
	/*!
	\brief Moves the character left by some amount multiplied by the speed param
	\param spd - movement speed
	*/
	void MoveLeft(int spd);
	/*!
	\brief Moves the character right by some amount multiplied by the speed param
	\param spd - movement speed
	*/
	void MoveRight(int spd);
	/*!
	\brief Moves the character up by some amount multiplied by the speed param
	\param spd - movement speed
	*/
	void ClimbUp(int spd);
	/*!
	\brief Moves the character down by some amount multiplied by the speed param
	\param spd - movement speed
	*/
	void ClimbDown(int spd);


	//FOR TESTS:
	bool GodMode = false; ///< Variable to make character invincible
};

class Runner : public Character
{

public:
	/*!
	\brief Constructor: sets the basic runner speed
	*/
	Runner();
};



class Robot : public Character
{
private:
	bool IsStuck = false;
	bool IsReady = true;
	int PrevCoords[2];

public:
	/*!
	\brief Getter of the boolean which tells if the robot got stuck
	*/
	bool GetStuck();
	/*!
	\brief Setter of the boolean which tells if the robot got stuck
	\param state - new IsStuck state
	*/
	void SetStuck(bool state);
	/*!
	\brief Getter of IsReady - boolean that tells if robot is standing perfectly in grid
	*/
	bool GetReady();
	/*!
	\brief Setter of IsReady - boolean that tells if robot is standing perfectly in grid
	\param ready - new IsReady value
	*/
	void SetReady(bool ready);
	/*!
	\brief Getter of robots previous X coordinate 
	*/
	int GetPrevX();
	/*!
	\brief Getter of robots previous Y coordinate 
	*/
	int GetPrevY();
	/*!
	\brief Saves the previous robot coordinates into two separate variables
	\param x - x coordinate
	\param y - y coordinate
	*/
	void SetPrevCoords(int x, int y);
};
#endif