// MobileObject.h header file for movable objects derived from the Object class


#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "Object.h"

class MobileObject : public Object
{
protected:
	sf::Vector2f velC;		// current velocity
	sf::Vector2f velM;		// max velocity

	

public:
	MobileObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos) : Object(fileName, size, pos) { velC = { 0, 0 }; velM = { 10, 10 }; };
	~MobileObject() {};
	void loadObj() {};
	void unloadObj() {};
	void updateObj() {};
	void drawObj() {};
	sf::Vector2f const getVelC() {};
	sf::Vector2f const getVelM() {};
	void setVelC(sf::Vector2f) {};
	void setVelM(sf::Vector2f) {};




};


#endif // MOBILEOBJECT_H