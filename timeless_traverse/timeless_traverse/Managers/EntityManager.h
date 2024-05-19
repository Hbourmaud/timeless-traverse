#pragma once

#include "../Entities/Entity.h"

#include <vector>

/*
 * Singleton
*/
class EntityManager : GameObject
{
public:
	static EntityManager& GetInstance()
	{
		static EntityManager instance;
		return instance;
	}

	Entity* CreateEntity(Entity* entity);

	Entity* GetEntity(int id);
	std::vector<Entity*> GetEntityList();

	void Clear(int id);
	void ClearAll();

private:
	EntityManager();
	~EntityManager();

	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;
	
	std::vector<Entity*> entityList;
};
