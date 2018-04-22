#include "stdafx.h"
#include "Turtle.h"


void Turtle::setLive(bool live)
{
	this->live = live;
}

bool Turtle::isLive()
{
	return live;
}

void Turtle::addAnimation()
{
	animation.setSpriteSheet(mTexture);
	animation.addFrame(sf::IntRect(0,82,16,23));
	animation.addFrame(sf::IntRect(17, 82, 16, 23));
	animation.addFrame(sf::IntRect(34, 51, 15, 13));
}

void Turtle::update(float deltaTime)
{
	velocity.x = 0.0f;
	velocity.x -= speed;
	totalTime += deltaTime;
	if (totalTime > switchTime) {
		if (coutFrame < animation.getSize() - 2)
			coutFrame++;
		else
		{
			coutFrame = 0;
		}
		totalTime = 0;
	}

	velocity.y += 981.0f*deltaTime;

	
	if (live == false) {
		coutFrame = 2;		
		body.setSize(sf::Vector2f(50.0f, 50.0f));
		body.setOrigin(body.getSize() / 2.0f);
		velocity.x *= 7;
	}
	sf::IntRect rect(animation.getFrame(coutFrame));
	body.setTextureRect(rect);
	if (velocity.x < 0) {
		body.setScale(1.0f, 1.0f);
	}
	else {
		body.setScale(-1.0f, 1.0f);
	}
	body.move(velocity*deltaTime);
}

void Turtle::draw(sf::RenderWindow & window, Player & player)
{
	sf::Vector2f direction(0.0f, 0.0f);
	if (hasCheckCollider) {
		if (player.GetCollider().CheckCollision(getCollider(), direction, 0)) {
			int check = player.OnCollision(direction);
			if (check == 1 || check == 2)
				player.setLive(false);
			else {
				live = false;
				//hasCheckCollider = false;
			}
		}		
	}
	window.draw(body);
}

void Turtle::onCollider(sf::Vector2f direction)
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

Turtle::Turtle()
{
}


Turtle::~Turtle()
{
}
