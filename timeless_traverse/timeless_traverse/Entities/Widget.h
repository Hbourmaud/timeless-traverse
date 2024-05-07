#pragma once

#include "Entity.h"
#include "../Components/SpriteComponent.h"

class Widget : public Entity
{
public:
    Widget();
    ~Widget();

    void setText(std::string text, sf::Color color = sf::Color::White, int size = 50) const;
    void setShape(sf::Shape* shape);

    void draw(sf::RenderWindow* window);

    SpriteComponent* spriteComponent;

private:
    sf::Text* m_text;
    sf::Shape* m_shape;
    sf::Font font;

};
