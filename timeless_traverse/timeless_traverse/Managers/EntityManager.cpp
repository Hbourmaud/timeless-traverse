#include "EntityManager.h"

EntityManager::EntityManager() = default;
EntityManager::~EntityManager() = default;

void EntityManager::CreateEntity() {
	Entity* entity = new Entity();
	int id = entityList.size() + 1;
	entityList.push_back(entity);
	entity->id = id;
}

Entity* EntityManager::GetEntity(int id)
{
	for (Entity* entity : entityList)
	{
		return (entity->id == id) ? entity : NULL;
	}
}