#include "GameManager.h"


GameManager::GameManager() = default;

GameManager::~GameManager() = default;

void GameManager::Init()
{
	screenWidth = 1920;
	screenHeight = 1080;
	GameLoop();
}

void GameManager::GameLoop()
{
	sf::Clock timeBetweenFrame;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Timeless_Traverse");
	window.setFramerateLimit(60);
	sf::Event event;

	while (window.isOpen())
	{
		////////////////////////
		//Input
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		/////////////////////////
		//Calcul
		


		/////////////////////////
		//Draw
		window.clear();



		window.display();
		/////////////////////////
		//DeltaTime
		dt = timeBetweenFrame.restart().asSeconds();
	}
}