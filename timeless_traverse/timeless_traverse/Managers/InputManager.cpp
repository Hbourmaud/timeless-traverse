﻿#include "InputManager.h"
#include "../GameManager.h"

InputManager::InputManager() = default;

InputManager::~InputManager() = default;

void InputManager::HandleInput(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        MovementDelegate.BroadCast(100.f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        MovementDelegate.BroadCast(-100.f);
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space)
        {
            JumpDelegate.BroadCast();
        }

        if (event.key.code == sf::Keyboard::F)
        {
            ActionDelegate.BroadCast();
        }
    }
}

sf::Vector2f InputManager::GetMousePosition(const sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition( window );
    sf::Vector2f mousePosF( static_cast<float>( mousePos.x ), static_cast<float>( mousePos.y ) );

    return mousePosF;
}
