// PlayerObject.h file for players

#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "MobileObject.h"

class PlayerObject : public MobileObject
{
protected:
	sf::Vector2f velocity;


public:
	PlayerObject();
	~PlayerObject();
	void loadObj();
	void unloadObj();
	void updateObj();
	void drawObj();





};


#endif // PLAYERCOBJECT_H