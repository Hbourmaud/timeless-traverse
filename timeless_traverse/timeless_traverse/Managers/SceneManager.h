#pragma once
#include <windows.data.json.h>
#include "../GameObject.h"
#include "SFML/Graphics.hpp"


class SceneManager : public GameObject
{
public:
    SceneManager(sf::Window* win);
    ~SceneManager() = default;

    void LoadLevel(std::string levelName);
    void UnloadLevel();
    void Dophysics();
    void SetCamera(float x, float y);
    sf::View* GetCamera() { return camera; }

private:
    sf::View* camera;
    sf::Window* window;
    
};