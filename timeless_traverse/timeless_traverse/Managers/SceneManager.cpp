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
	player->ApplyPhysics(deltaTime);
	UpdateEntities();
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


void SceneManager::UpdateEntities()
{
	player->spriteComponent->setPosition(player->transformComponent->GetPosition().X, player->transformComponent->GetPosition().Y);
	player->collisionComponent->SetPosition(player->transformComponent->GetPosition().X, player->transformComponent->GetPosition().Y);

	std::vector<Entity*> entityList = EntityManager::GetInstance().GetEntityList();
	for (auto entity : entityList)
	{
		if(typeid(*entity) == typeid(Platform))
		{
			Platform *platform = dynamic_cast<Platform*>(entity);
			platform->spriteComponent->setPosition(entity->transformComponent->GetPosition().X, entity->transformComponent->GetPosition().Y);
			platform->collisionComponent->SetPosition(entity->transformComponent->GetPosition().X, entity->transformComponent->GetPosition().Y);

			if (player->collisionComponent->isColliding(platform->collisionComponent->GetCollisionBox()))
			{
				std::cout << "iscolliding" << std::endl;
				player->physicsComponent->SetVelocity(new Vector2D::TVector2D(player->physicsComponent->GetVelocity().X, 0.f));
			}

			continue;
		}

		if(typeid(*entity) == typeid(Enemy))
		{
			Enemy *enemy = dynamic_cast<Enemy*>(entity);
			enemy->spriteComponent->setPosition(entity->transformComponent->GetPosition().X, entity->transformComponent->GetPosition().Y);
			continue;
		}
	}
}