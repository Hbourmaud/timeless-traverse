#include "SceneManager.h"

#include "../Factory.h"
#include "../Entities/Character.h"
#include "../Entities/Enemy.h"
#include "../Entities/Platform.h"
#include "../Entities/Player.h"
using json = nlohmann::json;

SceneManager::SceneManager(sf::RenderWindow* win)
{
	player = &Player::GetInstance();
	window = win;
	camera = new sf::View(sf::FloatRect(0.f,0.f,window->getSize().x,window->getSize().y));
	camera->setViewport(sf::FloatRect(0.f,0.f,1.f,1.f));
}

SceneManager::SceneManager()
{
	player = &Player::GetInstance();
};

void SceneManager::SetCamera(float x, float y)
{
	camera->setCenter(x, y);
}

void SceneManager::LoadLevel(std::string levelName, Factory<Entity> factory)
{
	// afin de charger les niveaux, on utilise un fichier json contenant toute les informations n�cessaires
	// � la cr�ation des entit�s d'un niveau (joueur, ennemie, plate-forme...) 

	factory.Register<Platform>();
	factory.Register<Enemy>();
	std::string path = std::filesystem::current_path().generic_string() + "/Asset/Level/" + levelName;
	
	std::ifstream levelFile(path);

	json level = json::parse(levelFile);

	// it�ration dans le fichier JSON
	int j = 0;
	for (auto it = level.at("entities").begin(); it != level.at("entities").end(); ++it)
	{
		float xpos = 0;
		float ypos = 0;
		std::string textureName = "";

		//r�cup�ration des information de l'entit�
		if (!level.at("entities")[j].empty())
		{
			if (!level.at("entities")[j].at("entitieName").empty())  
			{
				std::string entities = level.at("entities")[j].at("entitieName");

				if (!level.at("entities")[j].at("xPos").empty())
				{
					xpos = level.at("entities")[j].at("xPos");
				}
				if (!level.at("entities")[j].at("yPos").empty())
				{
					ypos = level.at("entities")[j].at("yPos");
				}
				if (!level.at("entities")[j].at("texture").empty())
				{
					textureName = level.at("entities")[j].at("texture");
				}

				//cr�ation et param�trage des entit�s du niveaux
				if (entities == "Platform")
				{
					Platform* platform = dynamic_cast<Platform*>(factory.Create(typeid(Platform)));
					platform->transformComponent->SetPosition(xpos, ypos);
					platform->spriteComponent->SetSprite(textureName);
				}
				else if (entities == "Enemy")
				{
					Enemy* enemy = dynamic_cast<Enemy*>(factory.Create(typeid(Enemy)));
					enemy->transformComponent->SetPosition(xpos, ypos);
					enemy->spriteComponent->SetSprite(textureName);
				}
				else if (entities == "Player")
				{
					Player::GetInstance().transformComponent->SetPosition(xpos, ypos);
					Player::GetInstance().spriteComponent->SetSprite(textureName);
				}
			}
		}
		j++;
	}
}

void SceneManager::UnloadLevel()
{
	//EntityManager entity_manager();
	//entity_manager().ClearAll();
}

void SceneManager::DoPhysics(float deltaTime)
{
	UpdateEntities(deltaTime);
	player->ApplyPhysics(deltaTime);
}

void SceneManager::SetUpCollisionBox()
{
	sf::Vector2<int> textureSize = player->spriteComponent->GetSprite().getTextureRect().getSize();
	player->collisionComponent->SetSize(textureSize.x, textureSize.y);
	
	std::vector<Entity*> entityList = EntityManager::GetInstance().GetEntityList();
	for (auto entity : entityList)
	{
		if(typeid(*entity) == typeid(Platform))
		{
			Platform *platform = dynamic_cast<Platform*>(entity);
			sf::Vector2<int> textureSize = platform->spriteComponent->GetSprite().getTextureRect().getSize();
			platform->collisionComponent->SetSize(textureSize.x, textureSize.y);
			continue;
		}

		if(typeid(*entity) == typeid(Enemy))
		{
			Enemy *enemy = dynamic_cast<Enemy*>(entity);
			sf::Vector2<int> textureSize = enemy->spriteComponent->GetSprite().getTextureRect().getSize();
			enemy->collisionComponent->SetSize(textureSize.x, textureSize.y);
			continue;
		}
	}
}


void SceneManager::UpdateEntities(float deltaTime)
{
	player->spriteComponent->setPosition(player->transformComponent->GetPosition().X, player->transformComponent->GetPosition().Y);
	player->collisionComponent->SetPosition(player->transformComponent->GetPosition().Y, player->transformComponent->GetPosition().X);
	player->collisionComponent->SetDirectionalCollisionBox();
	
	std::vector<Entity*> entityList = EntityManager::GetInstance().GetEntityList();
	std::vector<Platform*> platforms;
	
	for (auto entity : entityList)
	{
		if(typeid(*entity) == typeid(Platform))
		{
			Platform *platform = dynamic_cast<Platform*>(entity);
			platforms.push_back(platform);

			platform->spriteComponent->setPosition(entity->transformComponent->GetPosition().X, entity->transformComponent->GetPosition().Y);
			platform->collisionComponent->SetPosition(entity->transformComponent->GetPosition().Y, entity->transformComponent->GetPosition().X);

			player->OnCollision(player->collisionComponent->directionalColliding(platform->collisionComponent->GetCollisionBox()));

			window->draw(platform->spriteComponent->GetSprite());
		}

	}

	for (auto entity : entityList)
	{
		if(typeid(*entity) == typeid(Enemy))
		{
			Enemy *enemy = dynamic_cast<Enemy*>(entity);
			enemy->ApplyPhysics(deltaTime);
			enemy->spriteComponent->setPosition(entity->transformComponent->GetPosition().X, entity->transformComponent->GetPosition().Y);
			enemy->collisionComponent->SetPosition(entity->transformComponent->GetPosition().Y, entity->transformComponent->GetPosition().X);

			enemy->Move(25.f);
			
			for (Platform* platform : platforms)
			{
				if (platform->collisionComponent->isColliding(enemy->collisionComponent->GetCollisionBox()))
				{
					enemy->physicsComponent->SetVelocity(new Vector2D::TVector2D(enemy->physicsComponent->GetVelocity().X, 0.f));
				}
			}
			
			window->draw(enemy->spriteComponent->GetSprite());
		}
	}
}