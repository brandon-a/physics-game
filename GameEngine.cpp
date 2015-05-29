//GameEngine.cpp implementation file

#include "GameEngine.h"

GameEngine::GameEngine()
{
	movR = false;			// should only one be true at a time
	movL = false;
	movU = false;
	movD = false;
	timePerFrame = sf::seconds(1.0f / 60.0f);
}

GameEngine::~GameEngine()
{
}

void GameEngine::gameLoop(){


	PlayerObject p1("resources/blueBoy.png", sf::Vector2f(64, 64), sf::Vector2f(100, 630));
	sf::Vector2f screenSize(1000, 800);		// keep elsewhere do not delete
	StaticObject background("resources/marioBackground.jpg", screenSize, sf::Vector2f(0, 0));
	background.setScale(1.0f, (float)screenSize.y / background.getTexture().getSize().y);		// sets scale of background image in y direction to match the size of the window

	


	//Game Engine Class Variables
	float frameCounter = 0;				// for animations isanimatable
	float switchFrame = 100;			// for animations isanimatable
	float frameSpeed = 400;				// for animations isanimatable

	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Physics Game"); // loads game window	
	sf::Clock deltaClock;
	sf::Time timeSincelastUpdate = sf::Time::Zero;

	// Physics Engine Class Variables

	// float acceleration = 0.5;	    removeable?

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
				//if (velocity.x > 0)										// getters and setters
				//	velocity.x -= acceleration;
			}

			if (movD && !movU)
			{
				p1.setSourcePosY(Down);
				/*if (velocity.x > 0)
				velocity.x -= acceleration;*/
			}

			if (movR && !movL)
			{
				p1.setSourcePosY(Right);		// changes the direction the sprite is facing
				if (p1.getVelC().x < p1.getVelM().x)
					p1.setVelC(p1.getVelC() + p1.getForceN());
				else
					p1.setVelC(p1.getVelM());

			}
			else
			{
				if (p1.getVelC().x > 0)
					p1.setVelC(p1.getVelC() - p1.getForceN());

			}


			if (movL && !movR)
			{
				p1.setSourcePosY(Left);
				if (p1.getVelC().x > 0 - p1.getVelM().x)
					p1.setVelC(p1.getVelC() - p1.getForceN());
				else
					p1.setVelC(sf::Vector2f(0, 0) - p1.getVelM());
			}
			else
			{
				if (p1.getVelC().x < 0)
					p1.setVelC(p1.getVelC() + p1.getForceN());
			}

			if (movL || movR || movU || movD)
				frameCounter += frameSpeed *clock.restart().asSeconds();
			else
				frameCounter = 0;

			//prep for refresh
			p1.update(frameCounter, switchFrame);
		}
		// frame refresh cycle
		window.clear();
		window.draw(background.getSprite());
		p1.draw(window);
		window.display();
	}
}