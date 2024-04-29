#pragma once

#include "Entity.h"

#include "../Components/CollisionComponent.h"
#include "../Components/SpriteComponent.h"
#include "../Components/StatsComponent.h"

class SpriteComponent;

class Character : public Entity
{
public:
	Character();
	~Character();

	CollisionComponent* collisionComponent;
	SpriteComponent* spriteComponent;
	// StatsComponent

private:

};
