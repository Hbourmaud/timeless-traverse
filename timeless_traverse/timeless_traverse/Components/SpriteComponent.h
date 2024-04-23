#include <SFML/Graphics/Sprite.hpp>
#include "sfml/graphics/Texture.hpp"
#include "Component.h"
#include <string>

class SpriteComponent : public Component
{
public:
	SpriteComponent();
	~SpriteComponent();

	sf::Sprite GetSprite() { return entitySprite; }
	void SetSprite(std::string textureName);

private:
	sf::Sprite entitySprite;

};