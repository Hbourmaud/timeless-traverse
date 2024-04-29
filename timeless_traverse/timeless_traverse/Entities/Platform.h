#pragma once

#include "Entity.h"

#include "../Components/CollisionComponent.h"
#include "../Components/SpriteComponent.h"

class Platform : public Entity
{
public:
	Platform();
	~Platform();

	CollisionComponent* collisionComponent;
	SpriteComponent* spriteComponent;

private:

};