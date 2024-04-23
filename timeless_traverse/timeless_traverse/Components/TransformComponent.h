#include <SFML/System/Vector2.hpp>

#include "Component.h"

class TransformComponent : public Component
{
public:
	TransformComponent();
	~TransformComponent();

	//getter
	sf::Vector2f GetPosition() { return position; }
	sf::Vector2f GetRotation() { return rotation; }
	sf::Vector2f GetScale() { return scale; }
	//setter
	void SetPosition(float x, float y);
	void SetRotation();
	void SetScale(float x, float y);

private:
	sf::Vector2f position;
	sf::Vector2f rotation;
	sf::Vector2f scale;
};