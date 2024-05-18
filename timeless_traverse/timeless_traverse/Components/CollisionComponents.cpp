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

CollisionComponent::Direction CollisionComponent::directionalColliding(const sf::Rect<float>& other)
{
	for (auto& directionalCollisionBox : directionalCollisionBoxes)
	{
		if (directionalCollisionBox.second.intersects(other))
		{
			return directionalCollisionBox.first;
		}
	}
	
	return nullDirection;
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

void CollisionComponent::SetDirectionalCollisionBox()
{
	directionalCollisionBoxes[top] = sf::Rect<float>(collisionBox.left,collisionBox.top - sizeBox/2, collisionBox.width, sizeBox);
	directionalCollisionBoxes[right] = sf::Rect<float>(collisionBox.left + collisionBox.width - sizeBox/2,collisionBox.top, sizeBox,collisionBox.height);
	directionalCollisionBoxes[bottom] = sf::Rect<float>(collisionBox.left,collisionBox.top + collisionBox.height - sizeBox/2, collisionBox.width,sizeBox);
	directionalCollisionBoxes[left] = sf::Rect<float>(collisionBox.left - sizeBox/2,collisionBox.top, sizeBox,collisionBox.height);
}
