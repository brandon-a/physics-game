// PhysicsEngine.h manages all physics in the game

#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <cmath>
#include <SFML\System\Vector2.hpp>

struct System
{
	float mass;
	sf::Vector2f force;
	float theta;
	float mu;
	sf::Vector2f vel;
	sf::Vector2f acc;
};

class PhysicsEngine
{
private:
	sf::Vector2f gravity;		// fed in at the beggining of a level

public:
	void setGravity(sf::Vector2f grav) { gravity = grav; }
	sf::Vector2f getGravity() { return gravity; }
	sf::Vector2f *calcAcceleration(System *mFV, int num);
	sf::Vector2f calcAcceleration(System sys1, System sys2);
	sf::Vector2f calcNetForce(System sys1, System sys2);

};


#endif // PHYSICSENGINE_H