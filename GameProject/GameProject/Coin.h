#pragma once
#include "DynamicObject.h"
#include "Player.h"
class Coin :public DynamicObject
{
public:
	Coin(sf::Texture *texture,sf::Vector2f size, float switchTime, float speed, int type) :
		DynamicObject(texture, size, switchTime, speed, type) {
	}

	Coin(const Coin& coin);
	void addAnimation();
	void update(float deltaTime);
	void draw(sf::RenderWindow &window, Player &player) override;
	void onCollider(sf::Vector2f direction) {};
	~Coin();
};

