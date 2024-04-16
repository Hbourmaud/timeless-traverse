#pragma once

#include "../Entities/Entity.h"

#include <iostream>
#include <vector>

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

	void CreateEntity();

	Entity* GetEntity(int id);

private:
	std::vector<Entity*> entityList;
};
