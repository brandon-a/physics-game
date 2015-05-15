// This is the start of our Physics Game
// Brandon and Jamie

#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	//Variables
	sf::Vector2i screenSize(1000, 800);
	float pHeight = 64;		// chibi size y direction (height)

	// to be moved to physics engine
	sf::Vector2f velocity(0, 0);
	float acceleration = 0.5;
	float maxSpeedR = 10;
	float maxSpeedL = -10;

	bool rMove = false;
	bool lMove = false;
	// Game Setup
	
	

	// Load playerSpriteData
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	if (!playerTexture.loadFromFile("resources/blueBoy.png"))
		std::cout << "blueBoy.png failed to open!\n";
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(2.0f, 2.0f);
	sf::Vector2u pSource(0, 2);
	playerSprite.setPosition(100, 630);	// set initial position

	// load background
	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("resources/marioBackground.jpg"))
		std::cout << "marioBackground.jpg failed to open!\n";
	sf::Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setScale(1.0f, (float)screenSize.y / backgroundTexture.getSize().y);		// sets scale of background image in y direction to match the size of the window

	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "Physics Game"); // loads game window
	
	sf::Clock clock;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Clock deltaClock;
	sf::Time timeSincelastUpdate = sf::Time::Zero;

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
					{
						rMove = true;
					}
					if (event.key.code == sf::Keyboard::Left)
						lMove = true;
					break;


				case sf::Event::KeyReleased:

					if (event.key.code == sf::Keyboard::Right)
						rMove = false;
					if (event.key.code == sf::Keyboard::Left)
						lMove = false;


				}

			}
			//std::cout << playerSprite.getPosition().x << "," << playerSprite.getPosition().y << std::endl;    position to console

			if (rMove)
			{

				if (velocity.x < maxSpeedR)
				{
					velocity.x += acceleration;

				}

				/*else
					velocity.x = maxSpeedR;*/				// Not needed
			}
			if (lMove)
				if (velocity.x > maxSpeedL)
					velocity.x -= acceleration;
				/*else
					velocity.x = maxSpeedL;*/				// Not needed
			if (!lMove && !rMove)
			{
				if (velocity.x > 0)
					velocity.x -= acceleration;
				if (velocity.x < 0)
					velocity.x += acceleration;
			}

			//prep for refresh
			playerSprite.setTextureRect(sf::IntRect(pSource.x * pHeight / 2, pSource.y * pHeight / 2, pHeight / 2, pHeight / 2));
			playerSprite.move(velocity.x, velocity.y);
			//std::cout << velocity.x << std::endl;
		}
		// frame refresh cycle
		window.clear();
		window.draw(backgroundSprite);
		window.draw(playerSprite);
		window.display();
	}
	return 0;
}