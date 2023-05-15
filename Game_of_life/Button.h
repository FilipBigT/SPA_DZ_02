#pragma once
#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include<string>
using namespace std;

class Button
{
private:
	sf::RenderWindow& window;
	sf::Font font;
	sf::Text text;

	sf::Vector2f pos;

	bool button_value = false;

	void geo();

	sf::RectangleShape r1;
	sf::RectangleShape r2;
	sf::RectangleShape shadow;

	void colors();

	void center_text();

	void logic();

	sf::Mouse mouse;

public:
	Button(sf::RenderWindow& window);
	Button(sf::RenderWindow& window, sf::Font font, string line);

	bool return_button_value();

	void set_size(float width, float height);
	void set_position(sf::Vector2f pos);

	void set_text(string line);

	void draw();
};

