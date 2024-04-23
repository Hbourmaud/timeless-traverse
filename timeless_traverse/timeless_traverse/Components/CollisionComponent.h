#include <SFML/Graphics/Rect.hpp>

#include "Component.h"

class CollisionComponent : public Component
{
public:
	CollisionComponent(float height, float width, float offset);
	~CollisionComponent();
	
	//getter
	sf::Rect<float> GetCollisionBox() { return collisionBox; }
	//setter
	void SetOffset();
private:
	sf::Rect<float> collisionBox;
	sf::Vector2f offset;
	//sf::Vector2f relativeLocation;
	//Entity[] LayerOverrides;
};