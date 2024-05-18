#pragma once

#include <unordered_map>
#include <SFML/Graphics/Rect.hpp>

#include "Component.h"

class CollisionComponent : public Component
{
public:
	enum Direction {nullDirection = 0, top = 1, right = 2, bottom = 3, left = 4 };
	
	CollisionComponent(float height, float width, float top, float left);
	~CollisionComponent();

	bool isColliding(const sf::Rect<float>& other);

	Direction directionalColliding(const sf::Rect<float>& other);
	
	sf::Rect<float> GetCollisionBox() { return collisionBox; }
	std::unordered_map<Direction,sf::Rect<float>> GetDirectionalCollisionBox() { return directionalCollisionBoxes; }

	void SetPosition(float top, float left);
	void SetSize(float height, float width);
	void SetDirectionalCollisionBox();

private:
	sf::Rect<float> collisionBox;
	std::unordered_map<Direction,sf::Rect<float>> directionalCollisionBoxes;

	const float sizeBox = 5.f; 
};