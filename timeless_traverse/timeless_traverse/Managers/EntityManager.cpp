#include "EntityManager.h"

EntityManager::EntityManager() = default;
EntityManager::~EntityManager() = default;

Entity* EntityManager::CreateEntity(Entity* entity) {
	int id = entityList.size() + 1;
	entityList.push_back(entity);
	entity->SetId(id);

	return entity;
}

Entity* EntityManager::GetEntity(int id)
{
	for (Entity* entity : entityList)
	{
		if (entity->GetId() == id)
		{
			return entity;
		}
	}

	return nullptr;
}

std::vector<Entity*> EntityManager::GetEntityList()
{
	return entityList;
}

void EntityManager::Clear(int id)
{
	Entity* entity = this->GetEntity(id);
	for (const Entity* i : entityList)
	{
		if (i->GetId() == id)
			entityList.erase(std::find(entityList.begin(), entityList.end(), GetEntity(id)));
	}
	delete[]entity;
	entity = nullptr;

}

void EntityManager::ClearAll()
{
	for (Entity* entity : entityList) {
		delete entity;
		entity = nullptr;
	}
}