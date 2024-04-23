#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(float height, float width, float offset)
{
	collisionBox.height = height;
	collisionBox.width = width;
	collisionBox.top = 0 + offset;
	collisionBox.left = 0 + offset;
}
CollisionComponent::~CollisionComponent() = default;

void SetOffset()
{
	
}