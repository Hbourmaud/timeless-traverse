#include "TransformComponent.h"

TransformComponent::TransformComponent() = default;

TransformComponent::~TransformComponent() = default;

void TransformComponent::SetPosition(float x, float y)
{
	position.X = x; 
	position.Y = y;
};

void TransformComponent::SetRotation()
{
	//� faire
}

void TransformComponent::SetScale(float x, float y)
{
	scale.X = x;
	scale.Y = y;
}