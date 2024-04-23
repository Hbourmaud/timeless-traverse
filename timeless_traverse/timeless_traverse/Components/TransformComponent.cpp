#include "TransformComponent.h"

TransformComponent::TransformComponent() = default;

TransformComponent::~TransformComponent() = default;

void TransformComponent::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
};

void TransformComponent::SetRotation()
{
	//à faire
}

void TransformComponent::SetScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
}