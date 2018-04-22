#include "stdafx.h"
#include "Coin.h"



Coin::Coin(const Coin& coin)
{
	this->mTexture = coin.mTexture;
	this->body = coin.body;
	this->switchTime = coin.switchTime;
	this->speed = coin.speed;
	this->totalTime = coin.totalTime;
	this->animation = coin.animation;
	this->coutFrame = coin.coutFrame;
	this->type = coin.type;
	this->hasCheckCollider = coin.hasCheckCollider;
	this->velocity = coin.velocity;
}

void Coin::addAnimation()
{
	animation.setSpriteSheet(mTexture);
	animation.addFrame(sf::IntRect(290,94,14,14));
	animation.addFrame(sf::IntRect(308, 94, 13, 14));
	body.setTextureRect(animation.getFrame(0));
}

void Coin::update(float deltaTime)
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

void Coin::draw(sf::RenderWindow & window, Player & player)
{
	sf::Vector2f direction(0.0f, 0.0f);
	if (hasCheckCollider) {
		if (player.GetCollider()
			.CheckCollision(getCollider(), direction, 0)) {
			hasCheckCollider = false;
			player.setPoint(player.getPoint() + 200);
		}
		window.draw(body);
	}
}


Coin::~Coin()
{
}