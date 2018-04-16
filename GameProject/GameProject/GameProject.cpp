// GameProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Map.h"

static const float VIEW_HEIGHT = 480.0f;
void ResizeView(const sf::RenderWindow &window, sf::View& view)
{
	float aspecRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT*aspecRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(640.0f, 480.0f), "Mario", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(640.0f, 480.0f));
	sf::FloatRect fbounds(0, 0, 2000, 216);
	Map map;
	sf::IntRect ibounds(fbounds);	

	sf::Texture marioTexture;
	sf::Texture backgroundTexture;		
	backgroundTexture.loadFromFile("images/background.png");
	float scaleX = (float)window.getSize().x / backgroundTexture.getSize().x;
	float scaleY = (float)window.getSize().y / backgroundTexture.getSize().y;
	backgroundTexture.setRepeated(true);
	sf::Sprite background(backgroundTexture, ibounds);
	background.setPosition(-400.0f, 50.0f);
	background.setScale(scaleX, scaleY);
	marioTexture.loadFromFile("images/mario_sprite.png");
	marioTexture.setSmooth(true);
	map.loadmap();

	//playerTexture.

	Player player(&marioTexture, sf::Vector2u(7, 2), 0.08f, 150.0f);

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
		map.checkColider(player);

		view.setCenter(player.GetPostion()-sf::Vector2f(0,140));
		//Draw and show
		window.clear(sf::Color(255, 255, 255));
		window.setView(view);
		window.draw(background);
		player.Draw(window);				
		map.draw(window);
		window.display();
	}
	return 0;
}