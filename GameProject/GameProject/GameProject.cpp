// GameProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(515, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);	
	sf::RectangleShape bird(sf::Vector2f(100.0f, 100.0f));	
	bird.setPosition(100.0f, 100.0f);
	sf::Texture marioTexture;
	sf::Texture birdTexture;
	marioTexture.loadFromFile("mario_sprite.png");
	birdTexture.loadFromFile("bird.png");
	//playerTexture.
	bird.setTexture(&birdTexture);


	Animation animationBird(&birdTexture, sf::Vector2u(3, 3), 0.2f);
	animationBird.setTexture(sf::Vector2u(0, 0), sf::Vector2u(3, 3));

	Player player(&marioTexture, sf::Vector2u(7, 2), 0.3f, 100.0f);

	float deltaTime = 0.0f;	

	sf::Clock clock;
	
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		//Exit Window
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window.close();
		}
		//Event Window
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		animationBird.update(deltaTime,false);



		bird.setTextureRect(animationBird.uvRect);
		player.Update(deltaTime);
		//Draw and show
		window.clear(sf::Color(255,255,255));
		player.Draw(window);
		window.draw(bird);
		window.display();
	}
	return 0;
}

