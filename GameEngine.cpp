//GameEngine.cpp implementation file

#include "GameEngine.h"

GameEngine::GameEngine()
{
	movR = false;			// should only one be true at a time
	movL = false;
	movU = false;
	movD = false;
	timePerFrame = sf::seconds(1.0f / 60.0f);
	txtrMng.addDirectory("resources/");

	p1 = new PlayerObject(txtrMng.getTexture("blueBoy.png"), sf::Vector2f(64, 64), sf::Vector2f(100, 630));

	screenSize = sf::Vector2f(1000, 800);		// keep elsewhere do not delete
	background = new StaticObject(txtrMng.getTexture("marioBackground.jpg"), screenSize, sf::Vector2f(0, 0));
	//  this line is going to be changed with views.
	background->setScale(1.0f, (float)screenSize.y / background->getTexture()->getSize().y);		// sets scale of background image in y direction to match the size of the window

	frameCounter = 0;				// for animations isanimatable     -  perhaps static
	switchFrame = 100;				// for animations isanimatable
	frameSpeed = 400;				// for animations isanimatable	- perhaps static

	window = new sf::RenderWindow(sf::VideoMode(screenSize.x, screenSize.y), "Physics Game"); // loads game window	
	timeSincelastUpdate = sf::Time::Zero;

	physEng.setGravity({ 0.0f, -9.8f });

}

GameEngine::~GameEngine()
{
}

void GameEngine::gameLoop(){

	while (window->isOpen()) 
	{
		sf::Time deltaTime = deltaClock.restart();
		timeSincelastUpdate += deltaTime;

		while (timeSincelastUpdate >= timePerFrame)
		{
			timeSincelastUpdate -= timePerFrame;

			sf::Event event;
			while (window->pollEvent(event))		// the event loop
			{
				switch (event.type) {
				case sf::Event::Closed:
					window->close();
					break;
				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
						window->close();
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
				p1->setSourcePosY(Up);									// from object, setters and getters
				//if (velocity.x > 0)										// getters and setters
				//	velocity.x -= acceleration;
			}

			if (movD && !movU)
			{
				p1->setSourcePosY(Down);
				/*if (velocity.x > 0)
				velocity.x -= acceleration;*/
			}

			if (movR && !movL)
			{
				p1->setSourcePosY(Right);		// changes the direction the sprite is facing
				if (p1->getVelC().x < p1->getMaxAForce())
					p1->setVelC(p1->getVelC() + p1->getForceA());
				else
					p1->setVelC(sf::Vector2f(p1->getMaxAForce(), 0));

			}
			else
			{
				if (p1->getVelC().x > 0)
					p1->setVelC(p1->getVelC() - p1->getForceA());

			}


			if (movL && !movR)
			{
				p1->setSourcePosY(Left);
				if (p1->getVelC().x > 0 - p1->getMaxAForce())
					p1->setVelC(p1->getVelC() - p1->getForceA());
				else
					p1->setVelC(sf::Vector2f(0, 0) - sf::Vector2f(p1->getMaxAForce(),0));
			}
			else
			{
				if (p1->getVelC().x < 0)
					p1->setVelC(p1->getVelC() + p1->getForceA());
			}

			if (movL || movR || movU || movD)
				frameCounter += frameSpeed *clock.restart().asSeconds();
			else
				frameCounter = 0;


			//prep for refresh
			p1->update(frameCounter, switchFrame);
		}
		// frame refresh cycle
		window->clear();
		background->draw(*window);
		p1->draw(*window);
		window->display();


	}
}