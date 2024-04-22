#pragma once

#include "../Entities/Entity.h"

#include <iostream>
#include <vector>

class EntityManager : GameObject
{
public:
	EntityManager();
	~EntityManager();

	void CreateEntity();

	Entity* GetEntity(int id);

private:
	std::vector<Entity*> entityList;
};
