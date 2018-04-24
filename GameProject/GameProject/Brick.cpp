#include "stdafx.h"
#include "Brick.h"



void Brick::addAnimation()
{
	animation.setSpriteSheet(mTexture);
	animation.addFrame(sf::IntRect(272, 25, 14, 14));
	//animation.addFrame(sf::IntRect(308, 94, 13, 14));
	body.setTextureRect(animation.getFrame(0));
}

void Brick::update(float deltaTime)
{
	velocity.x = 0.0f;
	//velocity.x -= speed;
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

	//velocity.y += 981.0f*deltaTime;
	body.setTextureRect(animation.getFrame(coutFrame));
	body.move(velocity*deltaTime);
}

void Brick::draw(sf::RenderWindow & window, Player & player)
{
	sf::Vector2f direction(0.0f, 0.0f);
	if (hasCheckCollider) {
		if (player.GetCollider()
			.CheckCollision(getCollider(), direction, 0)) {						
			if (player.OnCollision(direction) == 4) {
				hasCheckCollider = false;
			}
		}
		window.draw(body);
	}
}

void Brick::onCollider(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//Collision on the left.
		velocity.x = 0.0f;
		speed = -speed;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
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

Brick::~Brick()
{
}
