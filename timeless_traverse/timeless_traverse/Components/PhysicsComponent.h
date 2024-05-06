#pragma once

#include "Component.h"
#include "../Math/Vector2D.h"

class PhysicsComponent : public Component
{
public:
	PhysicsComponent();
	~PhysicsComponent();

	Vector2D::TVector2D<float> GetVelocity() { return velocity; }

	void SetVelocity(Vector2D::TVector2D<float>* velocityVector);

	void Impulse(Vector2D::TVector2D<float>* impulseForce);
	void ApplyGravity();

private:
	Vector2D::TVector2D<float> velocity;
	Vector2D::TVector2D<float> gravity;
};
