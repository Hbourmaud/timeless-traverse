#pragma once

#include "../Entities/Entity.h"

#include <iostream>
#include <vector>

class EntityManager : GameObject
{
public:
	EntityManager();
	~EntityManager();

	Entity* CreateEntity(Entity* entity);

	Entity* GetEntity(int id);

	void Clear(int id);
	void ClearAll();

private:
	std::vector<Entity*> entityList;
};
