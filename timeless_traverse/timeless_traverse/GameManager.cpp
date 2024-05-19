#include "GameManager.h"

#include "Factory.h"
#include "Entities/Enemy.h"
#include "Entities/Platform.h"
#include "Entities/Player.h"
#include "Managers/EntityManager.h"
#include "Managers/InputManager.h"


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
	
	float dt = 0.f;
	
	InputManager& IM = InputManager::GetInstance();
	EntityManager& EM = EntityManager::GetInstance();
	SceneManager* SM = new SceneManager(&window);

	Player& player = Player::GetInstance();
	player.spriteComponent->SetSprite("WonderBoy.png");

	Factory<Entity> factory;

	SM->LoadLevel("level1.txt", factory);

	SM->SetUpCollisionBox();
	
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
			if (event.key.code == sf::Keyboard::B)
			{
				SM->UnloadLevel();
				SM->LoadLevel("level1.txt", factory);
				SM->SetUpCollisionBox();
				player.physicsComponent->SetVelocity(0);
			}
			IM.HandleInput(event);

		}
		/////////////////////////
		//Calcul

		SM->SetCamera(player.transformComponent->GetPosition().X,player.transformComponent->GetPosition().Y);
		window.setView(*SM->GetCamera());
		
		window.clear();
		
		SM->DoPhysics(dt);

		/////////////////////////
		//Draw
		window.draw(player.spriteComponent->GetSprite());

		window.display();
		/////////////////////////
		//DeltaTime
		dt = timeBetweenFrame.restart().asSeconds();
	}
}