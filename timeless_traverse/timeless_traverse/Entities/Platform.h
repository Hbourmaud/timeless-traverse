#pragma once

#include "Entity.h"

#include "../Components/CollisionComponent.h"
#include "../Components/RenderComponent.h"

class Platform : public Entity
{
public:
	Platform();
	~Platform();

	CollisionComponent* collisionComponent;
	RenderComponent* renderComponent;

private:

};