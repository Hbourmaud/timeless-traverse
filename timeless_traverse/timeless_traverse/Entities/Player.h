#pragma once

#include "Character.h"
#include "../Components/PhysicsComponent.h"

/*
 * Singleton
*/
class Player : public Character
{
public:
    static Player& GetInstance()
    {
        static Player instance;
        return instance;
    }

    PhysicsComponent* physicsComponent;

    void ApplyPhysics(float deltaTime);
    void MoveHorizontal(float direction);
    void Jump();
    void Action();
    void OnCollision(CollisionComponent::Direction directionColliding);

private:
    Player();
    ~Player();

    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;
};
