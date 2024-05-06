#pragma once 
#include <list>

#include "../GameObject.h"
#include "SFML/Graphics.hpp"
#include <map>
#include <vector>


class AssetManager : public GameObject
{
public:
    AssetManager();
    ~AssetManager();
    sf::Texture * GetTexture(std::string textureName);
    void ClearTextureBuffer();
    void UnloadSpecificTexture(std::string textureName);
    std::vector<std::string> GetTextureLoaded();

private:
    std::map<std::string, sf::Texture> *textureMap;
    int unsigned mapSize;
    int unsigned i;
    sf::Texture* texture;

};