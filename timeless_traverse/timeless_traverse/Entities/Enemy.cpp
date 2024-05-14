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
