#pragma once

#include "Entity.h"
#include "../Components/SpriteComponent.h"

class Decor : public Entity
{
public:
    Decor();
    ~Decor();

    SpriteComponent* spriteComponent;
};
