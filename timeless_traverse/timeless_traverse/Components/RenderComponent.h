#include <SFML/Graphics/Sprite.hpp>
#include "sfml/graphics/Texture.hpp"
#include "Component.h"

class RenderComponent : public Component
{
public:
	RenderComponent();
	~RenderComponent();

	void SetSprite(sf::Texture texture);

private:
	sf::Sprite entitySprite;

};