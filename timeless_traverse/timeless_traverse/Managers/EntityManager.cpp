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

void EntityManager::Clear(int id)
{
	Entity* entity = this->GetEntity(id);
	delete []entity;
	entity = nullptr;
}

void EntityManager::ClearAll()
{
	for (Entity* entity : entityList) {
		delete entity;
		entity = nullptr;
	}
}