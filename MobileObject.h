//  MobileObject.h header file for non movable objects derived from the Object class

#ifndef MOBILEOBJECT_H
#define MOBILEOBJECT_H

#include "Object.h"

class MobileObject : public Object
{
protected:
	sf::Vector2f velC;		// current velocity
	sf::Vector2f velM;		// max velocity		NOT NEEDED? PHYSICS ENGINE
	sf::Vector2f forceN;

public:
	MobileObject(std::string fileName, sf::Vector2f size, sf::Vector2f pos) : Object(fileName, size, pos) { velC = { 0, 0 }; velM = { 10, 0 }; forceN = { 0.5 , 0 }; }
	~MobileObject() {};
	void update(float &frameCounter, float switchFrame);
	sf::Vector2f getVelC() const { return velC; };
	sf::Vector2f getVelM() const {return velM;}
	sf::Vector2f getForceN() const { return forceN; }			
	void setVelC(sf::Vector2f vel) { this->velC = vel; }
	void setVelM(sf::Vector2f vel) { this->velM = vel; }
	void setForceN(sf::Vector2f acc) { this->forceN = acc; }
};

#endif // MOBILEOBJECT_H