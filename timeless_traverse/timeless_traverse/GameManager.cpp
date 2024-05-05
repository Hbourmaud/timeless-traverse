#include "GameManager.h"
#include "ENtities/Platform.h"


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
		
		//Platform* platformA = new Platform();
		//sf::Texture* texture = new sf::Texture();
		//texture->loadFromFile("E:/Travail Ynov/C++/timeless-traverse/timeless_traverse/timeless_traverse/Asset/Texture/platform1.png");
		//platformA->renderComponent->SetSprite(texture);

		/////////////////////////
		//Draw
		window.clear();
		//window.draw(platformA->renderComponent->entitySprite);


		window.display();
		/////////////////////////
		//DeltaTime
		dt = timeBetweenFrame.restart().asSeconds();
	}
}