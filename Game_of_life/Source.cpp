#include<iostream>
#include<sstream>
#include<ctime>

#include"SFML/Window.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Audio.hpp"

#include"Button.h"

using namespace std;



int rng(int min, int max) {
	return rand() % (max - min + 1) + min;
}
void boot(sf::Clock clock, sf::Time time, float time_limit, sf::Font font, sf::RenderWindow& window)
{
	sf::SoundBuffer buffer;
	sf::Sound boot;

	if (!buffer.loadFromFile("90s PC boot sequence sound HD.wav"))
	{
		sf::err();
	}

	boot.setBuffer(buffer);
	boot.play();

	sf::Text text_1;
	text_1.setFont(font);
	text_1.setCharacterSize(50);
	text_1.setPosition(10,10);
	text_1.setString("DupaBIOS v.1.0.3-lv2");

	sf::Text text_2;
	text_2.setFont(font);
	text_2.setCharacterSize(50);
	text_2.setPosition(10, 70);
	text_2.setString("Booting from hard drive...");


	sf::Text text_3;
	text_3.setFont(font);
	text_3.setCharacterSize(50);
	text_3.setPosition(10, 260);
	text_3.setString("Loading external tools:");

	sf::Text text_3_1;
	text_3_1.setFont(font);
	text_3_1.setCharacterSize(50);
	text_3_1.setPosition(10, 320);
	text_3_1.setString("\t\tDUPA user data library");

	sf::Text text_3_2;
	text_3_2.setFont(font);
	text_3_2.setCharacterSize(50);
	text_3_2.setPosition(10, 380);
	text_3_2.setString("\t\tcustom package manager");

	sf::Text text_3_3;
	text_3_3.setFont(font);
	text_3_3.setCharacterSize(50);
	text_3_3.setPosition(10, 440);
	text_3_3.setString("\t\tuser GUI");


	sf::Text text_4_1;
	text_4_1.setFont(font);
	text_4_1.setCharacterSize(50);
	text_4_1.setPosition(10, 560);
	text_4_1.setString("Checking raw data transfer system...");

	sf::Text text_4_2;
	text_4_2.setFont(font);
	text_4_2.setCharacterSize(50);
	text_4_2.setPosition(10, 620);
	text_4_2.setString("Setting up user interface...");


	sf::Text text_5;
	text_5.setFont(font);
	text_5.setCharacterSize(50);
	text_5.setPosition(10, 740);
	text_5.setString("Rerouting access to user...");

	sf::Text text_6;
	text_6.setFont(font);
	text_6.setCharacterSize(50);
	text_6.setPosition(10, 860);
	text_6.setString("Boot successful");


	sf::CircleShape c1(150);
	c1.setFillColor(sf::Color::White);
	c1.setOutlineColor(sf::Color::Black);
	c1.setOutlineThickness(5);
	c1.setOrigin(c1.getRadius(), c1.getRadius());
	c1.setPosition(window.getSize().x - c1.getRadius() - 110, c1.getRadius() + 20);

	sf::CircleShape c2(150);
	c2.setFillColor(sf::Color::White);
	c2.setOutlineColor(sf::Color::Black);
	c2.setOutlineThickness(5);
	c2.setOrigin(c2.getRadius(), c2.getRadius());
	c2.setPosition(window.getSize().x - c2.getRadius() * 2 - 110, c2.getRadius() + 20);

	sf::Text dupa;
	dupa.setStyle(sf::Text::Underlined);
	dupa.setFont(font);
	dupa.setCharacterSize(50);
	dupa.setPosition(window.getSize().x - 600, c1.getRadius() * 2 + 20);
	dupa.setString("DUPA Technologies");
	// \nCopyright (C) [date_time], DUPA inc.

	sf::Text load;
	load.setStyle(sf::Text::Bold);
	load.setFont(font);
	load.setCharacterSize(50);
	load.setPosition(10,130);
	load.setString("");
	
	int n = 0;
	stringstream ss;

	cout << "Don't do anythig while its booting or it will crash :(" << endl;

	clock.restart();
	while (window.isOpen())
	{
		int num = time.asSeconds();

		time = clock.getElapsedTime();
		if (time.asSeconds() >= time_limit)
		{
			break;
		}

		window.clear();

		if (time.asSeconds() > 0.4)
		{
			window.draw(c2);
			window.draw(c1);
			window.draw(dupa);
		}

		if (time.asSeconds()>1)
			window.draw(text_1);	
	
		if (time.asSeconds() > 1.3)
		{
			window.draw(text_2);
			window.draw(load);
		}
			

		if (time.asSeconds() > 3)
			window.draw(text_3);
		if (time.asSeconds() > 3.7)
			window.draw(text_3_1);
		if (time.asSeconds() > 4.2)
			window.draw(text_3_2);
		if (time.asSeconds() > 5)
			window.draw(text_3_3);
		
		if (time.asSeconds() > 6)
			window.draw(text_4_1);

		if (time.asSeconds() > 6.4)
		{
			text_4_1.setString("Checking raw data transfer system\t[finished]");
			window.draw(text_4_2);
		}
			
		if (time.asSeconds() > 7.4)
		{
			text_4_2.setString("Setting up user interface\t[finished]");
			window.draw(text_5);
		}
			
		if (time.asSeconds() > 9)
		{
			text_5.setString("Rerouting acess to user\t[finished]");
			window.draw(text_6);
		}
			
		if (num > n)
		{
			load.setString("");
			ss << ".";
			load.setString(ss.str());
			n = num;
		}
		window.display();
	}
}
void background(sf::RenderWindow& window) 
{
	sf::Color color(200,200,200);

	sf::RectangleShape backebox;
	backebox.setPosition(sf::Vector2f(10,10));
	backebox.setSize(sf::Vector2f(window.getSize().x - 20, window.getSize().y - 20));




	backebox.setFillColor(sf::Color(0,0,0));

	backebox.setOutlineColor(sf::Color(200,200,200));
	backebox.setOutlineThickness(5);

	window.draw(backebox);
}
void shader()
{

}
sf::RectangleShape play_window(sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f size)
{
	sf::RectangleShape r;

	r.setFillColor(sf::Color::Black);
	r.setOutlineColor(sf::Color::White);
	r.setOutlineThickness(5);

	r.setPosition(pos);
	r.setSize(size);

	window.draw(r);
	return r;
}
int wrapValue(int v, int vMax)
{
	if (v == -1) return vMax - 1;
	if (v == vMax) return 0;
	return v;
}

void test(sf::RenderWindow& window) {

	sf::CircleShape c(100);
	c.setPosition(sf::Vector2f(500,500));


}

int main() {

	const int cell_size = 40;
	const int grid_width = 50;
	const int grid_height = 38;

	const int all_cells = grid_height * grid_width;
	bool grid[all_cells] = {  };

	bool next_Iteration[all_cells];

	int delay = 50;
	bool playing = false;

	// enable/disable boot intro - change intro value
	bool intro = false;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 0;
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Game of life", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	srand(time(nullptr));

	sf::Font font;
	if (!font.loadFromFile("OCRAEXT.TTF"))
	{
		sf::err();
		return 1;
	}

	sf::Mouse mouse;
	mouse.setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2));

	sf::Clock clock;
	sf::Time delta_time;

	if (intro)
	{
		boot(clock, delta_time, 12, font, window);
	}

	bool lock = false;

	Button gog(window, font, "Game of life");
	gog.set_size(400,125);
	gog.set_position(sf::Vector2f(240,100));
	bool gog_toggle = false;

	Button ef(window, font, "Play");
	ef.set_size(400, 125);
	ef.set_position(sf::Vector2f(240, 100 + 125 + 50));

	Button exit(window, font, "Exit");
	exit.set_size(400, 125);
	exit.set_position(sf::Vector2f(240, 100 + 125 + 125 + 50 + 50));


	sf::CircleShape c(50);
	c.setPosition(sf::Vector2f(500,500));

	//-----------------------------------------------------------------

	while (window.isOpen())
	{



		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			switch (event.type)
			{
				case sf::Event::MouseButtonPressed:
					if (play_window(window, sf::Vector2f(500, 35), sf::Vector2f(cell_size * grid_width, cell_size * grid_height)).getGlobalBounds().contains(sf::Vector2f(mouse.getPosition())))
					{
						int x = double(event.mouseButton.x - 500) / cell_size;
						int y = double(event.mouseButton.y - 35) / cell_size;
						grid[x + y * grid_width] = !grid[x + y * grid_width];
					}
				break;
			}
		}

		cout << mouse.getPosition().x << " " << mouse.getPosition().y << endl;

		if (exit.return_button_value())
		{
			window.close();
		}


		if (gog.return_button_value() && lock == false)
		{
			lock = true;
			gog_toggle = !gog_toggle;
		}
		else if (mouse.isButtonPressed(sf::Mouse::Left) && lock == true)
			lock = true;
		else
			lock = false;

		if (ef.return_button_value() && lock == false)
		{
			lock = true;
			playing = !playing;
		}
		else if (mouse.isButtonPressed(sf::Mouse::Left) && lock == true)
			lock = true;
		else
			lock = false;


		delta_time = clock.restart();



		window.clear();

		background(window);

		exit.draw();
		gog.draw();
		ef.draw();
		shader();

		//-----------------------------

		play_window(window, sf::Vector2f(500, 35), sf::Vector2f(cell_size * grid_width, cell_size * grid_height));

		for (int x = 0; x < grid_width; x++)
		{
			for (int y = 0; y < grid_height; y++)
			{
				sf::RectangleShape r;

				r.setFillColor(sf::Color::Black);
				r.setOutlineColor(sf::Color(100,100,100));
				r.setOutlineThickness(3);

				r.setPosition(x * cell_size + 500, y * cell_size + 35);
				r.setSize(sf::Vector2f(cell_size, cell_size));
				
				if (grid[x + y * grid_width] == true)
				{
					r.setFillColor(sf::Color::White);
				}
				else
				{
					r.setFillColor(sf::Color::Black);
				}
				window.draw(r);

				if (playing)
				{
					int neighborSum = 0;
					for (int i = -1; i < 2; i++)
						for (int j = -1; j < 2; j++)
						{
							int xi = wrapValue(x + i, grid_width);
							int yj = wrapValue(y + j, grid_height);
							neighborSum += grid[xi + yj * grid_width];
						}

					int current = x + y * grid_width;
					neighborSum -= grid[current];
					next_Iteration[current] = grid[current];
					if (grid[current] == 1 && (neighborSum < 2 || neighborSum > 3))
						next_Iteration[current] = 0;
					else if (neighborSum == 3)
						next_Iteration[current] = 1;
				}

				
			}
		}

		if (playing)
			for (int i = 0; i < all_cells; i++)
				grid[i] = next_Iteration[i];

		//-----------------------------

		window.display();
	}

	return 0;
}
