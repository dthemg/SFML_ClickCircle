#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void getRandomColors(int arr[3]);


int main()
{
	// Initialize random seed
	srand(time(NULL));
	int colors[3];

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	float radius = 50.f;
	const int maxCircles = 10;

	sf::CircleShape savedCircles[maxCircles];
	int numberSaved = 0;
	int index = 0;
	int numberOfSides = 3; // Start with a triangle

	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);

					sf::CircleShape shape(radius, numberOfSides);

					getRandomColors(colors);
					shape.setFillColor(sf::Color(colors[0], colors[1], colors[2]));

					shape.setPosition(localPosition.x, localPosition.y);
					shape.setOrigin(radius, radius);

					savedCircles[index] = shape;
					if (numberSaved < maxCircles)
					{
						numberSaved++;
					}
					numberOfSides++;
					index++;
					index = index % maxCircles;
				}
			}
		}
		
		for (int i=0; i <numberSaved; i++) 
		{
			window.draw(savedCircles[i]);
		}
	window.display();
	}
	
	return 0;
}


void getRandomColors(int arr[3])
{
	arr[0] = rand() % (256 - 20 + 1) + 20;
	arr[1] = rand() % (256 - 20 + 1) + 20;
	arr[2] = rand() % (256 - 20 + 1) + 20;
}
