#pragma once
#include <SFML\Graphics.hpp>
#include "collider.h"
class Platform
{
public:
	Platform() {};
	Platform(sf::Texture texture, sf::Vector2f size, bool hasCheckCollider);
	void setPosition(sf::Vector2f position);
	~Platform();
	void Draw(sf::RenderWindow& window) {
		window.draw(body);
	};
	Collider GetCollider() {
		return Collider(body);
	};
	bool getHasCollider();
private:
	bool hasCheckCollider;
	sf::RectangleShape body;
	sf::Texture* mTexture;
};