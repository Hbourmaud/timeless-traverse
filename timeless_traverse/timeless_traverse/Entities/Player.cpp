#include "Player.h"

#include <iostream>

#include "../GameManager.h"
#include "../Managers/InputManager.h"

Player::Player()
{
    InputManager& inputManager = InputManager::GetInstance();
    physicsComponent = new PhysicsComponent();
    inputManager.MovementDelegate.Bind(this, &Player::MoveHorizontal);
    inputManager.JumpDelegate.Bind(this, &Player::Jump);
};

Player::~Player() = default;

void Player::ApplyPhysics(float deltaTime)
{
    transformComponent->SetPosition(transformComponent->GetPosition() - physicsComponent->GetVelocity() * deltaTime);
    physicsComponent->ApplyGravity();
}

void Player::MoveHorizontal(float direction)
{
    physicsComponent->SetVelocity(new Vector2D::TVector2D(direction, physicsComponent->GetVelocity().Y));
}

void Player::Jump()
{
    physicsComponent->Impulse(new Vector2D::TVector2D(0.f, 200.f));
}
