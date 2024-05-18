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
	UpdateEntities();
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


void SceneManager::UpdateEntities()
{
	player->spriteComponent->setPosition(player->transformComponent->GetPosition().X, player->transformComponent->GetPosition().Y);
	player->collisionComponent->SetPosition(player->transformComponent->GetPosition().Y, player->transformComponent->GetPosition().X);
	player->collisionComponent->SetDirectionalCollisionBox();
	
	std::vector<Entity*> entityList = EntityManager::GetInstance().GetEntityList();
	for (auto entity : entityList)
	{
		if(typeid(*entity) == typeid(Platform))
		{
			Platform *platform = dynamic_cast<Platform*>(entity);
			platform->spriteComponent->setPosition(entity->transformComponent->GetPosition().X, entity->transformComponent->GetPosition().Y);
			platform->collisionComponent->SetPosition(entity->transformComponent->GetPosition().Y, entity->transformComponent->GetPosition().X);

			player->OnCollision(player->collisionComponent->directionalColliding(platform->collisionComponent->GetCollisionBox()));
			
			continue;
		}

		if(typeid(*entity) == typeid(Enemy))
		{
			Enemy *enemy = dynamic_cast<Enemy*>(entity);
			enemy->spriteComponent->setPosition(entity->transformComponent->GetPosition().Y, entity->transformComponent->GetPosition().X);
			continue;
		}
	}
}