#pragma once

#include "../Entities/Entity.h"

#include <iostream>
#include <vector>

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

	void Clear(int id);
	void ClearAll();

private:
	EntityManager();
	~EntityManager();

	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;
	
	std::vector<Entity*> entityList;
};
