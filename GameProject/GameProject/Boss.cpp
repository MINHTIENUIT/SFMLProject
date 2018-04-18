#include "stdafx.h"
#include "Boss.h"


void Boss::addAnimation()
{
	animation.setSpriteSheet(mTexture);
	animation.addFrame(sf::IntRect(1,509,45,42));
	animation.addFrame(sf::IntRect(51, 509, 45, 42));
	animation.addFrame(sf::IntRect(100, 509, 45, 42));
	animation.addFrame(sf::IntRect(1, 559, 45, 41));
	animation.addFrame(sf::IntRect(51, 559, 45, 41));
	animation.addFrame(sf::IntRect(100, 559, 45, 41));
	body.setTextureRect(animation.getFrame(0));
}

void Boss::update(float deltaTime)
{
	velocity.x = 0.0f;
	velocity.x -= speed;
	totalTime += deltaTime;
	if (totalTime > switchTime) {
		if (coutFrame < animation.getSize() - 1)
			coutFrame++;
		else
		{
			coutFrame = 0;
		}
		totalTime = 0;
	}

	velocity.y += 981.0f*deltaTime;
	body.setTextureRect(animation.getFrame(coutFrame));
	body.move(velocity*deltaTime);
}

void Boss::draw(sf::RenderWindow & window, Player & player)
{
	sf::Vector2f direction(0.0f, 0.0f);
	if (player.GetCollider().CheckCollision(getCollider(), direction, 0)) {
		player.setLive(false);
	}
	window.draw(body);
}

void Boss::onCollider(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//Collision on the left.
		velocity.x = 0.0f;
		speed = -speed;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
		speed = -speed;
	}

	if (direction.y > 0.0f)
	{
		//Collision on ther bottom.
		velocity.y = 0.0f;
	}
	else if (direction.y < 0.0f)
	{
		//Collision on ther top;
		velocity.y = 0.0f;
	}
}


Boss::~Boss()
{
}