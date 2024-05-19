#pragma once
#include "../GameObject.h"
#include <fstream>
#include "../Factory.h"
#include "../Utilitaire/json.hpp"
#include "SFML/Graphics.hpp"


class Player;

class SceneManager : public GameObject
{
public:
    SceneManager();
    SceneManager(sf::RenderWindow* win);
    ~SceneManager() = default;

    bool LoadLevel(std::string levelName, Factory<Entity> factory);
    void UnloadLevel();
    void DoPhysics(float deltaTime);
    void SetUpCollisionBox();
    int quitGame() { if (window->isOpen()) { window->close(); return 1; } }
    void SetCamera(float x, float y);
    sf::View* GetCamera() { return camera; }

private:
    sf::View* camera;
    sf::RenderWindow* window;
    Player* player;
    
    void UpdateEntities(float deltaTime);
};
