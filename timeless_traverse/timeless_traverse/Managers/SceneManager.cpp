#include "SceneManager.h"

#include "EntityManager.h"
#include "../Entities/Character.h"
#include "../Entities/Enemy.h"
#include "../Entities/Platform.h"
#include "../Entities/Player.h"

SceneManager::SceneManager(sf::Window* win)
{
	window = win;
	camera->setCenter(0, 0);
}

SceneManager::SceneManager()
{
	player = &Player::GetInstance();
};

void SceneManager::SetCamera(float x, float y)
{
	camera->setCenter(x, y);
}

void SceneManager::LoadLevel(std::string levelName)
{
	
}

void SceneManager::UnloadLevel()
{

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
		}
	}
}