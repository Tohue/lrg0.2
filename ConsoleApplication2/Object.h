#ifndef OBJECT_H
#define OBJECT_H
#include "SDL.h"
#include "Builder.h"


/*!
\brief A basic object class
A parent of every object
*/
class Object
{
protected:
	bool Top = false; ///< Used for ladders
	bool Bottom = false; ///< Used for ladders
	int x, y; 
	bool Solid = true; ///< Tells if this object will have a collision and will be drawn
public:
	bool Climbable = false; ///< Tells if this object can be climbed
	bool Collectable = false; ///< Tells if this object can be collected
	bool IsTube = false; ///< Tells if this object is actually a tube
	/*!
	\brief A getter for IsTop
	*/
	bool IsTop();
	/*!
	\brief A getter for IsBottom
	*/
	bool IsBottom();
	/*!
	\brief A getter for Solid
	*/
	bool IsSolid();
	/*!
	\brief A setter for Solid
	\param[in] set - sets the value
	*/
	void SetSolid(bool set);

	friend class Builder;
	/*!
	\brief An x getter
	*/
	int getx();
	/*!
	\brief An y getter
	*/
	int gety();

};

/*!
\brief A basic digable block
*/

class Block : public Object
{
public:
	Block();
};
/*!
\brief Climbable tube
*/
class Tube : public Object
{
public:
	Tube();
};

/*!
\brief Climbable ladder
*/
class Ladder : public Object
{
protected:
	bool Top;
	bool Bottom;
public:
	bool IsTop();
	bool IsBottom();
	Ladder(bool istop, bool isbottom); //! Constructor sets if it is the bottom or top ladder block
};
/*!
\brief Collectable Coin
It is actually some kind of microchip
*/
class Coin : public Object
{
public:
	Coin();
};
/*!
\brief An invisible path block that contains coordinates for robots path
*/
class Path : public Object
{
};
/*!
\brief A teleporter
A teleporter will turn on when all the coins are collected;
on collision with runner the next level starts 
*/
class Teleporter : public Object
{
public:
	bool IsOn = false; ///< Is it on or it is not on
};
#endif