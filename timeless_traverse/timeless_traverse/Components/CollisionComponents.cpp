#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(float height, float width, float top, float left)
{
	collisionBox.height = height;
	collisionBox.width = width;
	collisionBox.top = top;
	collisionBox.left = left;
}
CollisionComponent::~CollisionComponent() = default;

bool CollisionComponent::isColliding(const sf::Rect<float>& other)
{
	return collisionBox.intersects(other);
}

void CollisionComponent::SetPosition(float top, float left)
{
	collisionBox.top = top;
	collisionBox.left = left;
}

void CollisionComponent::SetSize(float height, float width)
{
	collisionBox.height = height;
	collisionBox.width = width;
}