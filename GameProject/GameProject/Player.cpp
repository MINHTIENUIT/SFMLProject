#include "stdafx.h"
#include "Player.h"



Player::Player(sf::Texture * texture, sf::Vector2u imageCount, float switchTime, float speed,float jumpHeight)
	:animation(texture,imageCount,switchTime)
{
	this->jumpHeight = jumpHeight;
	this->speed = speed;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(600.0f, 385.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x *= 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && live) {
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && live) {
		velocity.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump && live)
	{
		canJump = false;
		velocity.y = -sqrt(2.0f*981.0f*jumpHeight);
	}

	velocity.y += 981.0f*deltaTime;

	if (velocity.x == 0.0f)
	{
		animation.setTexture(sf::Vector2u(0.0f, 0.0f), sf::Vector2u(0.0f, 0.0f));
		//row = 0;
		animation.update(deltaTime, faceRight);
	}
	else {
		row = 1;
		if (velocity.x > 0.0f) {
			faceRight = true;
		}
		else {
			faceRight = false;
		}
		animation.update(1,deltaTime, faceRight);
	}
	
	body.setTextureRect(animation.uvRect);
	body.move(velocity*deltaTime);

}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//Collision on the left.
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}

	if (direction.y > 0.0f)
	{
		//Collision on ther bottom.
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y < 0.0f)
	{
		//Collision on ther top;
		velocity.y = 0.0f;
	}
}

sf::Vector2f Player::GetPostion()
{
	return body.getPosition();
}

bool Player::isLive()
{
	if (GetPostion().y > 480) {
		live = false;
	};
	return live;
}
