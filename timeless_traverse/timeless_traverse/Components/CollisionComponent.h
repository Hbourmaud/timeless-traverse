#include <SFML/Graphics/Rect.hpp>

#include "Component.h"

class CollisionComponent : public Component
{
public:
	CollisionComponent(float height, float width, float top, float left);
	~CollisionComponent();

	bool isColliding(const sf::Rect<float>& other);
	
	//getter
	sf::Rect<float> GetCollisionBox() { return collisionBox; }
	//setter
	void SetPosition(float top, float left);
	void SetSize(float height, float width);
private:
	sf::Rect<float> collisionBox;
	//Entity[] LayerOverrides;
};