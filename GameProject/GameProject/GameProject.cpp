// GameProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"

static const float VIEW_HEIGHT = 512.0f;
void ResizeView(const sf::RenderWindow &window, sf::View& view)
{
	float aspecRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT*aspecRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(512.0f, 512.0f), "SFML Tutorial", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));



	sf::Texture marioTexture;

	marioTexture.loadFromFile("mario_sprite.png");

	//playerTexture.


	Player player(&marioTexture, sf::Vector2u(7, 2), 0.08f, 100.0f);
	Platform platform1(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(500.0f, 200.0f));
	Platform platform2(nullptr, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(200.0f, 500.0f));

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
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			default:
				break;
			}
		}


		player.Update(deltaTime);
		platform1.GetCollider().CheckCollision(player.GetCollider(), 0.0f);
		platform2.GetCollider().CheckCollision(player.GetCollider(), 0.0f);
		platform1.GetCollider().CheckCollision(platform2.GetCollider(), 0.0f);
		platform2.GetCollider().CheckCollision(platform1.GetCollider(), 0.0f);


		view.setCenter(player.GetPostion());
		//Draw and show
		window.clear(sf::Color(000, 255, 255));
		window.setView(view);
		player.Draw(window);
		platform1.Draw(window);
		platform2.Draw(window);
		window.display();
	}
	return 0;
}