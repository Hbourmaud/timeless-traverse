#include <filesystem>
#include <iostream>

#include "Widget.h"

Widget::Widget()
{
    spriteComponent = new SpriteComponent();

    if (!font.loadFromFile(std::filesystem::current_path().generic_string() + "/Asset/Font/arial.ttf"))
    {
        throw "Failed to load font";
    }

    m_text = new sf::Text();
    m_shape = new sf::RectangleShape();
}

Widget::~Widget() = default;

void Widget::setText(std::string text, sf::Color color, int size) const
{
    m_text->setString(text);
    m_text->setFillColor(color);
    m_text->setCharacterSize(size);
    m_text->setFont(font);
}

void Widget::setShape(sf::Shape* shape)
{
    m_shape = shape;
    m_shape->setPosition(m_text->getPosition());
}

void Widget::draw(sf::RenderWindow* window)
{
    window->draw(*m_shape);
    window->draw(*m_text);
}

void Widget::onClick()
{
    m_onClick();
}

