// This is the start of our Physics Game
// Brandon and Jamie

#include <SFML/Graphics.hpp>
#include <iostream>
#include "PlayerObject.h"
#include "StaticObject.h"

int main()
{
	PlayerObject p1("resources/blueBoy.png", sf::Vector2f(64, 64), sf::Vector2f(100, 630));

	///////////////////////////TO BE REMOVED  ---   OBJECT OR DERIVED OBJECT CLASSES
	float pHeight = 64;		// chibi size y direction (height)			//***PlayerObject Constructor
	sf::Vector2f velocity(0, 0);									//***PlayerObject Constructor
	float maxSpeedR = 10;		//********************************************** READY TO LEAVE
	float maxSpeedL = -10;		//********************************************** READY TO LEAVE  (convert pos and neg) ***************
	enum direction { Down, Left, Right, Up };
	sf::Texture playerTexture;	//********************************************** READY TO LEAVE
	sf::Sprite playerSprite;		//********************************************** READY TO LEAVE
	if (!playerTexture.loadFromFile("resources/blueBoy.png"))	//********************************************** READY TO LEAVE
		std::cout << "blueBoy.png failed to open!\n";	//********************************************** READY TO LEAVE
	playerSprite.setTexture(playerTexture);	//********************************************** READY TO LEAVE
	playerSprite.setScale(2.0f, 2.0f);	//********************************************** READY TO LEAVE
	sf::Vector2u pSource(0, 0);	//********************************************** READY TO LEAVE
	playerSprite.setPosition(100, 630);	// set initial position		//********************************************** READY TO LEAVE

	//Game Engine Class Variables
	sf::Vector2i screenSize(1000, 800);
	float frameCounter = 0;
	float switchFrame = 100;
	float frameSpeed = 500;
	bool movR = false;				// Game engine
	bool movL = false;
	bool movU = false;
	bool movD = false;	
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Physics Game"); // loads game window	
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Clock deltaClock;
	sf::Time timeSincelastUpdate = sf::Time::Zero;

	// Physics Engine Class Variables

	float acceleration = 0.5;			

	// Game Setup
	
	// load background
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("resources/marioBackground.jpg"))
		std::cout << "marioBackground.jpg failed to open!\n";
	sf::Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setScale(1.0f, (float)screenSize.y / backgroundTexture.getSize().y);		// sets scale of background image in y direction to match the size of the window

	while (window.isOpen())  // game loop, game is running!
	{
		sf::Time deltaTime = deltaClock.restart();
		timeSincelastUpdate += deltaTime;

		while (timeSincelastUpdate >= timePerFrame)
		{
			timeSincelastUpdate -= timePerFrame;

			sf::Event event;
			while (window.pollEvent(event))		// the event loop
			{
				switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:

					if (event.key.code == sf::Keyboard::Escape)
						window.close();
					if (event.key.code == sf::Keyboard::Right)
						movR = true;
					if (event.key.code == sf::Keyboard::Left)
						movL = true;
					if (event.key.code == sf::Keyboard::Up)
						movU = true;
					if (event.key.code == sf::Keyboard::Down)
						movD = true;
					break;


				case sf::Event::KeyReleased:

					if (event.key.code == sf::Keyboard::Right)
						movR = false;
					if (event.key.code == sf::Keyboard::Left)
						movL = false;
					if (event.key.code == sf::Keyboard::Up)	
						movU = false;
					if (event.key.code == sf::Keyboard::Down)
						movD = false;
				}
			}

			if (movU && !movD)
			{
				p1.setSourcePosY(Up);									// from object, setters and getters
				if (velocity.x > 0)										// getters and setters
					velocity.x -= acceleration;
			}

			if (movD && !movU)
			{
				p1.setSourcePosY(Down);
				if (velocity.x > 0)
					velocity.x -= acceleration;
			}

			if (movR && !movL)
			{
				p1.setSourcePosY(Right);		// changes the direction the sprite is facing
				if (velocity.x < maxSpeedR)
				{
					velocity.x += acceleration;

				}
				else
					velocity.x = maxSpeedR;		// get/set
			}
			else
				if (velocity.x > 0)
					velocity.x -= acceleration;

			if (movL && !movR)
			{
				p1.setSourcePosY(Left);
				if (velocity.x > maxSpeedL)
					velocity.x -= acceleration;
				else
					velocity.x = maxSpeedL;
			}
			else
				if (velocity.x < 0)
					velocity.x += acceleration;

			if (movL || movR || movU || movD)
			{
				frameCounter += frameSpeed *clock.restart().asSeconds();

			}
			else
			{
				frameCounter = 0;
			}

			//prep for refresh
			p1.update(frameCounter, switchFrame);
			playerSprite.setTextureRect(sf::IntRect(pSource.x * pHeight / 2, pSource.y * pHeight / 2, pHeight / 2, pHeight / 2));		// player object update function
			playerSprite.move(velocity.x, velocity.y);			// player object update
		}
		// frame refresh cycle
		window.clear();
		window.draw(backgroundSprite);
		window.draw(playerSprite);
		p1.draw(window);
		window.display();
	}
	return 0;
}