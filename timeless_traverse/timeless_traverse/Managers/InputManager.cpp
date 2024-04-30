#include "InputManager.h"

InputManager::InputManager() = default;

InputManager::~InputManager() = default;

void InputManager::HandleInput(sf::Event event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        // left
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        // right

    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space)
        {
            // jump
        }

        if (event.key.code == sf::Keyboard::F)
        {
            // action
        }
    }
}
