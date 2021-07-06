#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	const int x = 50, y = 50;
	bool rotation = 0;
	sf::RectangleShape rectangle(sf::Vector2f(x, y));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(100, 100);
	rectangle.setOrigin(25,25);

	while (window.isOpen())
	{
		window.clear();
		window.draw(rectangle);
		window.display();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A) rotation = true;
				if (event.key.code == sf::Keyboard::D) rotation = false;
				break;
			}
		}
		if (rotation)
		{
			rectangle.rotate(-2.f);
		}
	}
	return 0;
}