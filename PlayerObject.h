// PlayerObject.h file for players

#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "MobileObject.h"

class PlayerObject : public MobileObject
{
protected:
	


public:
	PlayerObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos) : MobileObject(fileName, size, pos) {};
	~PlayerObject() {};
	void loadObj() {};
	void unloadObj() {};
	void updateObj() {};
	void drawObj() {};


};


#endif // PLAYERCOBJECT_H