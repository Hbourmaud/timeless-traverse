#include "AssetManager.h"
#include <filesystem>

AssetManager::AssetManager() = default;

AssetManager::~AssetManager() = default;

sf::Texture * AssetManager::GetTexture(std::string textureName)
{
	if (textureMap.contains(textureName))
	{
		return &textureMap.at(textureName);//[];
	}
	else
	{
		texture = new sf::Texture;
		textureName = std::filesystem::current_path().generic_string() + "/Asset/Texture/" + textureName;
		texture->loadFromFile(textureName);
		sf::Texture texttr = *texture;
		textureMap.insert(std::pair <std::string, sf::Texture>(textureName, texttr));

		return texture;
	}
}

void AssetManager::ClearTextureBuffer()
{
	textureMap.clear();
}

void AssetManager::UnloadSpecificTexture(std::string textureName)
{
	textureMap.erase(textureName);
}

std::vector<std::string> AssetManager::GetTextureLoaded()
{
	std::vector<std::string> textureKeyArray;
	for (auto it = textureMap.begin(); it != textureMap.end(); it++)
	{
		textureKeyArray.push_back(it->first);
	}
	return textureKeyArray;
}