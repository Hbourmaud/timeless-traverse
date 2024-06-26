﻿#pragma once

#include "Character.h"
#include "../Components/PhysicsComponent.h"

class Enemy : public Character
{
public:
    Enemy();
    ~Enemy();

    void ApplyPhysics(float deltaTime);
    void Move(float direction);

    PhysicsComponent* physicsComponent;
};
