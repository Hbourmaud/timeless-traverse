#include "SpriteComponent.h"
#include <filesystem>

#include <__msvc_filebuf.hpp>

SpriteComponent::SpriteComponent() = default;

SpriteComponent::~SpriteComponent() = default;

void SpriteComponent::SetSprite(std::string textureName)
{
	texture = assetManager.GetTexture(textureName);//new sf::Texture;
	texture->setSmooth(true);
	entitySprite.setTexture(*texture);
}

void SpriteComponent::setPosition(float x, float y)
{
	entitySprite.setPosition(x,y);
}
