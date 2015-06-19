// This is the start of our Physics Game
// Brandon and Jamie

#include "GameEngine.h"

int main()
{
	GameEngine game;
	game.gameLoop();

	//PlayerObject p1("resources/blueBoy.png", sf::Vector2f(64, 64), sf::Vector2f(100, 630));
	//enum direction { Down, Left, Right, Up };
	////Game Engine Class Variables
	//sf::Vector2i screenSize(1000, 800);
	//float frameCounter = 0;
	//float switchFrame = 100;
	//float frameSpeed = 400;
	//bool movR = false;				
	//bool movL = false;
	//bool movU = false;
	//bool movD = false;	
	//sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Physics Game"); // loads game window	
	//sf::Clock clock;
	//sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	//sf::Clock deltaClock;
	//sf::Time timeSincelastUpdate = sf::Time::Zero;

	//// Physics Engine Class Variables

	////float acceleration = 0.5;	    removeable?

	//
	//// load background
	//sf::Texture backgroundTexture;
	//if (!backgroundTexture.loadFromFile("resources/marioBackground.jpg"))
	//	std::cout << "marioBackground.jpg failed to open!\n";
	//sf::Sprite backgroundSprite(backgroundTexture);
	//backgroundsprite->setScale(1.0f, (float)screenSize.y / backgroundTexture.getSize().y);		// sets scale of background image in y direction to match the size of the window

	//while (window.isOpen())  // game loop, game is running!
	//{
	//	sf::Time deltaTime = deltaClock.restart();
	//	timeSincelastUpdate += deltaTime;

	//	while (timeSincelastUpdate >= timePerFrame)
	//	{
	//		timeSincelastUpdate -= timePerFrame;

	//		sf::Event event;
	//		while (window.pollEvent(event))		// the event loop
	//		{
	//			switch (event.type) {
	//			case sf::Event::Closed:
	//				window.close();
	//				break;
	//			case sf::Event::KeyPressed:
	//				if (event.key.code == sf::Keyboard::Escape)
	//					window.close();
	//				if (event.key.code == sf::Keyboard::Right)
	//					movR = true;
	//				if (event.key.code == sf::Keyboard::Left)
	//					movL = true;
	//				if (event.key.code == sf::Keyboard::Up)
	//					movU = true;
	//				if (event.key.code == sf::Keyboard::Down)
	//					movD = true;
	//				break;

	//			case sf::Event::KeyReleased:
	//				if (event.key.code == sf::Keyboard::Right)
	//					movR = false;
	//				if (event.key.code == sf::Keyboard::Left)
	//					movL = false;
	//				if (event.key.code == sf::Keyboard::Up)	
	//					movU = false;
	//				if (event.key.code == sf::Keyboard::Down)
	//					movD = false;
	//			}
	//		}

	//		if (movU && !movD)
	//		{
	//			p1.setSourcePosY(Up);									// from object, setters and getters
	//			//if (velocity.x > 0)										// getters and setters
	//			//	velocity.x -= acceleration;
	//		}

	//		if (movD && !movU)
	//		{
	//			p1.setSourcePosY(Down);
	//			/*if (velocity.x > 0)
	//				velocity.x -= acceleration;*/
	//		}

	//		if (movR && !movL)
	//		{
	//			p1.setSourcePosY(Right);		// changes the direction the sprite is facing
	//			if (p1.getVelC().x < p1.getVelM().x)
	//				p1.setVelC(p1.getVelC() + p1.getForceN());
	//			else
	//				p1.setVelC(p1.getVelM());

	//		}
	//		else
	//		{
	//			if (p1.getVelC().x > 0)
	//				p1.setVelC(p1.getVelC() - p1.getForceN());

	//		}


	//		if (movL && !movR)
	//		{
	//			p1.setSourcePosY(Left);
	//			if (p1.getVelC().x > 0 - p1.getVelM().x)
	//				p1.setVelC(p1.getVelC() - p1.getForceN());
	//			else
	//				p1.setVelC(sf::Vector2f( 0 , 0 ) - p1.getVelM());
	//		}
	//		else
	//		{
	//			if (p1.getVelC().x < 0)
	//				p1.setVelC(p1.getVelC() + p1.getForceN());
	//		}

	//		if (movL || movR || movU || movD)
	//			frameCounter += frameSpeed *clock.restart().asSeconds();
	//		else
	//			frameCounter = 0;

	//		//prep for refresh
	//		p1.update(frameCounter, switchFrame);
	//	}
	//	// frame refresh cycle
	//	window.clear();
	//	window.draw(backgroundSprite);
	//	p1.draw(window);
	//	window.display();
	//}
	return 0;
}