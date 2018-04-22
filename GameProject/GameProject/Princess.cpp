#include "stdafx.h"
#include "Princess.h"


void Princess::setLive(bool live)
{
	this->live;
}

bool Princess::isLive()
{
	return live;
}

void Princess::addAnimation()
{
	animation.setSpriteSheet(mTexture);
	animation.addFrame(sf::IntRect(493, 585, 15, 30));
}

void Princess::update(float deltaTime)
{
	velocity.x = 0.0f;
	//velocity.x -= speed;
	//totalTime += deltaTime;
	//if (totalTime > switchTime) {
	//	if (coutFrame < animation.getSize() - 1)
	//		coutFrame++;
	//	else
	//	{
	//		coutFrame = 0;
	//	}
	//	totalTime = 0;
	//}

	//velocity.y += 981.0f*deltaTime;

	sf::IntRect rect(animation.getFrame(0));
	body.setTextureRect(rect);
	body.move(velocity*deltaTime);
}

void Princess::draw(sf::RenderWindow & window, Player & player)
{
	sf::Vector2f direction(0.0f, 0.0f);
	sf::Text endGame;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	endGame.setCharacterSize(30);
	endGame.setStyle(sf::Text::Bold);
	endGame.setFont(font);	
	bool end = false;
	if (hasCheckCollider) {
		if (player.GetCollider().CheckCollision(getCollider(), direction, 0)) {
			//hasCheckCollider = false;
			std::string endString = "You save my live, Mario. Thank you!!";
			endGame.setString(endString);
			endGame.setPosition(window.getView().getCenter().x-250,200);
			window.draw(body);
			player.Draw(window);
			window.draw(endGame);
			window.display();
			end = true;
			while (end) {				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)
					||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					end = false;
				}				
			}
		}
	}	
	window.draw(body);
	
}

void Princess::onCollider(sf::Vector2f direction)
{
}

Princess::~Princess()
{
}
