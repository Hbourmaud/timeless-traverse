#include "Player.h"

Player::Player()
{
    physicsComponent = new PhysicsComponent();
};

Player::~Player() = default;

void Player::ApplyPhysics()
{
    transformComponent->SetPosition(transformComponent->GetPosition() - physicsComponent->GetVelocity());
}
