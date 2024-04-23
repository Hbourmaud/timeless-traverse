#include "RenderComponent.h"

RenderComponent::RenderComponent()
{

}

RenderComponent::~RenderComponent() = default;

void RenderComponent::SetSprite(sf::Texture texture)
{
	if (!texture.loadFromFile("WonderBoy.png"))
	{
		// erreur...
	}
	texture.setSmooth(true);
	entitySprite.setTexture(texture);
}

