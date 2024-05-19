#include "Enemy.h"

Enemy::Enemy()
{
    physicsComponent = new PhysicsComponent();
};

Enemy::~Enemy() = default;

void Enemy::ApplyPhysics(float deltaTime)
{
    transformComponent->SetPosition(transformComponent->GetPosition() - physicsComponent->GetVelocity() * deltaTime);
    physicsComponent->ApplyGravity();
}

void Enemy::Move(float direction)
{
    // simple movement for example
    physicsComponent->SetVelocity(new Vector2D::TVector2D(direction, physicsComponent->GetVelocity().Y));
}
