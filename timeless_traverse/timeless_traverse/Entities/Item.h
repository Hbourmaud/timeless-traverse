#pragma once

#include "Entity.h"
#include "../Components/CollisionComponent.h"
#include "../Components/SpriteComponent.h"

class Item : Entity
{
public:
    Item();
    ~Item();

    CollisionComponent* collisionComponent;
    SpriteComponent* spriteComponent;
};
