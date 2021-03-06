// GameProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Map.h"
#include "Coin.h"
#include "Boss.h"
static const float VIEW_HEIGHT = 450.0f;
#define WIDTH 640
#define HEIGHT 450
void ResizeView(const sf::RenderWindow &window, sf::View& view)
{
	float aspecRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT*aspecRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT), "Mario", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(WIDTH,HEIGHT));
	Map map;

	sf::Texture marioTexture;
	marioTexture.loadFromFile("images/mario_sprite.png");
	marioTexture.setSmooth(true);

	//playerTexture.
	Player player(&marioTexture, sf::Vector2u(7, 2), 0.08f, 150.0f,175.0f);
	map.loadMap(player);
	float deltaTime = 0.0f;

	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;
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
		map.checkColider(player);
		map.update(deltaTime);
		player.Update(deltaTime);	


		if (player.GetPostion().x < WIDTH/2) {
			view.setCenter(WIDTH / 2, HEIGHT / 2);
		}
		else {
			view.setCenter(player.GetPostion().x,HEIGHT/2);
		}		
		//Draw and show
		window.clear(sf::Color(74, 141, 223));
		window.setView(view);				
		map.draw(window,player);

		if (player.isLive()) {
			player.Draw(window);
		}
		else
		{
			sf::Font font;
			if (!font.loadFromFile("arial.ttf"))
			{
				// error...
			}
			sf::Text endGame;
			endGame.setPosition(player.GetPostion().x-100, 230);
			endGame.setString("Game Over");
			endGame.setCharacterSize(30);
			endGame.setStyle(sf::Text::Bold);
			endGame.setFont(font);
			window.draw(endGame);
		}
		window.display();
	}
	return 0;
}