#pragma once

#include <SFML/Window/Event.hpp>

#include "../GameObject.h"

class InputManager : GameObject
{
public:
    static InputManager& GetInstance()
    {
        static InputManager instance;
        return instance;
    }

    void HandleInput(sf::Event event);

private:
    InputManager();
    ~InputManager();

    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    
};
