#include "AssetManager.h"
#include <filesystem>

AssetManager::AssetManager() = default;

AssetManager::~AssetManager() = default;

sf::Texture AssetManager::GetTexture(std::string textureName)
{
	if (textureMap.contains(textureName))
	{
		return* textureMap[textureName];
	}
	else
	{
		sf::Texture* texture = new sf::Texture;
		textureName = std::filesystem::current_path().generic_string() + "/Asset/Texture/" + textureName;
		if (!texture->loadFromFile(textureName))
		{

			
		}
	}
}
