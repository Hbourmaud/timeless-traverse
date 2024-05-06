#include "Player.h"

Player::Player()
{
    physicsComponent = new PhysicsComponent();
};

Player::~Player() = default;

void Player::ApplyPhysics(float deltaTime)
{
    transformComponent->SetPosition(transformComponent->GetPosition() - physicsComponent->GetVelocity() * deltaTime);
    physicsComponent->ApplyGravity();
}
