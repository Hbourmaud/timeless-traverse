#pragma once

#include "Entity.h"

#include "../Components/CollisionComponent.h"
#include "../Components/RenderComponent.h"
#include "../Components/StatsComponent.h"

class Character : public Entity
{
public:
	Character();
	~Character();

	CollisionComponent* collisionComponent;
	RenderComponent* renderComponent;
	// StatsComponent

private:

};