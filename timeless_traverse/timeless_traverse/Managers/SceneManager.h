#pragma once 
#include "../GameObject.h"
#include "SFML/Graphics.hpp"


class SceneManager : public GameObject
{
public:
    SceneManager() = default;
    ~SceneManager() = default;

    void SetCamera();

private:
    sf::View camera;

};