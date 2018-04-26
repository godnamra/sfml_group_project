#include <SFML\Graphics.hpp>
#define height 1024
#define width 768

int main()
{
	sf::RenderWindow window(sf::VideoMode(height, width), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();	
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}