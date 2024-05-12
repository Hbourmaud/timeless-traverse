﻿#pragma once

#include <SFML/Window/Event.hpp>

#include "../GameObject.h"
#include "../Delegate.h"

class InputManager : GameObject
{
public:
    static InputManager& GetInstance()
    {
        static InputManager instance;
        return instance;
    }

    void HandleInput(sf::Event event);

    DECLARE_DELEGATE(CharacterMovement, float)
    CharacterMovement MovementDelegate;

    DECLARE_DELEGATE(CharacterJump)
    CharacterJump JumpDelegate;

    DECLARE_DELEGATE(CharacterAction)
    CharacterAction ActionDelegate;

private:
    InputManager();
    ~InputManager();

    InputManager(const InputManager&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    
};
