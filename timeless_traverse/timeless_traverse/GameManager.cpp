#include "GameManager.h"

#include "Factory.h"
#include "Entities/Enemy.h"
#include "Entities/Platform.h"
#include "Entities/Player.h"
#include "Managers/EntityManager.h"
#include "Managers/InputManager.h"
//#include "ENtities/Platform.h"


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

	InputManager& IM = InputManager::GetInstance();

	float dt = 0.f;

	EntityManager& EM = EntityManager::GetInstance();

	Player& player = Player::GetInstance();
	player.spriteComponent->SetSprite("WonderBoy.png");
	player.transformComponent->SetPosition(500.f, 400.f);

	Factory<Entity> factory;

	factory.Register<Platform>();
	
	Platform* platformA = dynamic_cast<Platform*>(factory.Create(typeid(Platform)));
	platformA->spriteComponent->SetSprite("platform1.png");
	platformA->transformComponent->SetPosition(500.f,500.f);

	SceneManager* SM = new SceneManager();
	InputManager& IM = InputManager::GetInstance();

	SM->SetUpCollisionBox();
	
	while (window.isOpen())
	{
		////////////////////////
		//Input
		while (window.pollEvent(event))
		{
			IM.HandleInput(event);
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			IM.HandleInput(event);

		}
		/////////////////////////
		//Calcul

		SM->DoPhysics(dt);

		//sf::Texture* texture = new sf::Texture();
		//texture->loadFromFile("E:/Travail Ynov/C++/timeless-traverse/timeless_traverse/timeless_traverse/Asset/Texture/platform1.png");

		/////////////////////////
		//Draw
		window.clear();
		window.draw(platformA->spriteComponent->GetSprite());
		window.draw(player.spriteComponent->GetSprite());

		window.display();
		/////////////////////////
		//DeltaTime
		dt = timeBetweenFrame.restart().asSeconds();
	}
}