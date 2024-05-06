#include "SpriteComponent.h"
#include <filesystem>

#include <__msvc_filebuf.hpp>

SpriteComponent::SpriteComponent() = default;

SpriteComponent::~SpriteComponent() = default;

void SpriteComponent::SetSprite(std::string textureName)
{
	texture = assetManager.GetTexture(textureName);//new sf::Texture;
	//textureName = std::filesystem::current_path().generic_string() + "/Asset/Texture/" + textureName;
	//if (!texture->loadFromFile(textureName))
	//{
	//	// erreur...
	//	return;
	//}
	texture->setSmooth(true);
	entitySprite.setTexture(*texture);
}


