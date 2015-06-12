//  PlayerObject.h file for players

#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "MobileObject.h"

class PlayerObject : public MobileObject
{
protected:
	
public:
	PlayerObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos, float mu = 1, sf::Vector2f forceA = { 0.5, 0 }) : MobileObject(fileName, size, pos, mu) {};
	~PlayerObject() {};

};

#endif // PLAYERCOBJECT_H