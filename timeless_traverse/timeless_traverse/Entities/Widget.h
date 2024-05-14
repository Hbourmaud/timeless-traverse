#pragma once

#include <functional>

#include "Entity.h"
#include "../Components/SpriteComponent.h"

class Widget : public Entity
{
public:
    Widget();
    ~Widget();

    void setText(std::string text, sf::Color color = sf::Color::White, int size = 50) const;
    void setShape(sf::Shape* shape);

    sf::Shape* getShape() { return m_shape; }

    template<typename T>
    void setOnClick(T method)
    {
        m_onClick = method;
    }

    void draw(sf::RenderWindow* window);
    void onClick();

    SpriteComponent* spriteComponent;

private:
    sf::Text* m_text;
    sf::Shape* m_shape;
    sf::Font font;

    std::function<void()> m_onClick;
};
