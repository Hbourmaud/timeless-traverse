#include "TransformComponent.h"

TransformComponent::TransformComponent() = default;

TransformComponent::~TransformComponent() = default;

void TransformComponent::SetPosition(float x, float y)
{
	position.X = x; 
	position.Y = y;
};

void TransformComponent::SetPosition(Vector2D::TVector2D<float> newPosition)
{
	position = newPosition;
};

void TransformComponent::SetRotation()
{
	//à faire
}

void TransformComponent::SetScale(float x, float y)
{
	scale.X = x;
	scale.Y = y;
}