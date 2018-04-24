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
	body.setPosition(600.0f, 400.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x *= 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && live) {
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && live) {
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
	sf::Text pointString;
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
	pointString.setCharacterSize(30);
	pointString.setStyle(sf::Text::Bold);
	pointString.setFont(font);
	std::string endString = "Point: "+ std::to_string(point);
	pointString.setString(endString);
	pointString.setPosition(window.getView().getCenter().x - window.getSize().x/2, 50);
	window.draw(pointString);
	window.draw(body);
}

int Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f) {
		//Collision on the left.
		velocity.x = 0.0f;
		return 1;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
		return 2;
	}

	if (direction.y > 0.0f)
	{
		//Collision on ther bottom.
		velocity.y = 0.0f;
		canJump = true;
		return 3;
	}
	else if (direction.y < 0.0f)
	{
		//Collision on ther top;
		velocity.y = 0.0f;
		return 4;
	}
	return 0;
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

void Player::setLive(bool live)
{
	this->live = live;
}