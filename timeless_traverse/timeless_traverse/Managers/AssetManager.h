#pragma once 
#include "../GameObject.h"
#include "SFML/Graphics.hpp"
#include <map>


class AssetManager : public GameObject
{
public:
    AssetManager();
    ~AssetManager();

    sf::Texture  GetTexture(std::string textureName);
    
private:
    std::map<std::string, sf::Texture*> textureMap;
    int i;

};