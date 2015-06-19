//  PlayerObject.h file for players

#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H

#include "MobileObject.h"

class PlayerObject : public MobileObject
{
protected:
	
public:
	PlayerObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos, float mass = 30, float mu = 1, sf::Vector2f forceA = { 0.5, 0 }, float theta = 0, sf::Vector2f velC = { 0, 0 }, float maxAForce = 5)
		: MobileObject(fileName, size, pos, mass, mu, forceA, theta, velC, maxAForce){};
	~PlayerObject() {};

};

#endif // PLAYERCOBJECT_H