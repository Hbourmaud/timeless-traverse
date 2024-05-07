#include "PhysicsComponent.h"

#include <iostream>
#include <SFML/System/Thread.hpp>

PhysicsComponent::PhysicsComponent()
{
    // set default gravity value
    this->gravity.X = 0.f;
    this->gravity.Y = -5.f;

    isSubjectGravity = false;

    this->SetVelocity(new Vector2D::TVector2D(0.f, 0.f));
}

PhysicsComponent::~PhysicsComponent() = default;

void PhysicsComponent::SetVelocity(Vector2D::TVector2D<float>* velocityVector)
{
    if( !velocityVector)
    {
        velocity = gravity;
        return;
    }
    
    velocity = *velocityVector;
    isSubjectGravity = false;
}

void PhysicsComponent::Impulse(Vector2D::TVector2D<float>* impulseForce)
{
    velocity += *impulseForce;
}

void PhysicsComponent::ApplyGravity()
{
    velocity += gravity;

    if (!isSubjectGravity) {
        isSubjectGravity = true;
    }
}
