#include "Button.h"

void Button::geo()
{
    r1.setOrigin(r1.getSize().x / 2, r1.getSize().y / 2);
    r2.setOrigin(r2.getSize().x / 2, r2.getSize().y / 2);
    shadow.setOrigin(shadow.getSize().x / 2, shadow.getSize().y / 2);
}

void Button::colors()
{
    r1.setFillColor(sf::Color::Black);
    r1.setOutlineColor(sf::Color::White);
    r1.setOutlineThickness(3);

    r2.setFillColor(sf::Color::Black);
    r2.setOutlineColor(sf::Color::White);
    r2.setOutlineThickness(3);

    shadow.setFillColor(sf::Color(100,100,100));
}

void Button::center_text()
{
    text.setPosition(r1.getPosition() - r1.getSize() / float(2) + sf::Vector2f(10, 0));
}

void Button::logic()
{
    if (r1.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition())) && mouse.isButtonPressed(sf::Mouse::Left) && button_value == false)
    {
        button_value = true;
    }
    else if (button_value == true && mouse.isButtonPressed(sf::Mouse::Left))
    {
        button_value = true;
        r1.setFillColor(sf::Color(80, 80, 80));
    }
    else
    {
        button_value = false;
        r1.setFillColor(sf::Color::Black);
    }

    if (r1.getGlobalBounds().contains(sf::Vector2f(mouse.getPosition())))
    {
        r2.setOutlineColor(sf::Color(70,70,70));
    }
    else 
    {
        r2.setOutlineColor(sf::Color::White);
    }
}

Button::Button(sf::RenderWindow& window) : window(window)
{
    set_text("N/A");
    colors();
    set_size(200,100);
    set_position(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
}

Button::Button(sf::RenderWindow& window, sf::Font font, string line) : window(window)
{
    this->font = font;
    set_text(line);

    
    colors();
    set_size(200, 100);
    set_position(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    center_text();
}

bool Button::return_button_value()
{
    return button_value;
}

void Button::set_size(float width, float height)
{
    r1.setSize(sf::Vector2f(width, height));
    r2.setSize(sf::Vector2f(width + 10, height + 10));
    shadow.setSize(sf::Vector2f(width + 10, height + 10));
    geo();
    center_text();
}

void Button::set_position(sf::Vector2f pos)
{
    r1.setPosition(pos);
    r2.setPosition(pos);
    shadow.setPosition(pos+sf::Vector2f(15,10));
    center_text();
}

void Button::set_text(string line)
{
    text.setFont(font);
    text.setCharacterSize(50);
    text.setString(line);
}

void Button::draw()
{
    logic();

    window.draw(shadow);
    window.draw(r2);
    window.draw(r1);
    window.draw(text);
}
