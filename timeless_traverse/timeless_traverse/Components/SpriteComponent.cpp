#include "SpriteComponent.h"

SpriteComponent::SpriteComponent()
{

}

SpriteComponent::~SpriteComponent() = default;

void SpriteComponent::SetSprite(std::string textureName)
{
	sf::Texture texture;

	if (!texture.loadFromFile(textureName))
	{
		// erreur...
		return;
	}
	texture.setSmooth(true);
	entitySprite.setTexture(texture);
}
