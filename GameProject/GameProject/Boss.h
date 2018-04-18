#pragma once
#include "DynamicObject.h"
#include "Player.h"
class Boss:public DynamicObject
{
public:
	Boss(sf::Texture *texture, sf::Vector2f size, float switchTime, float speed) :
		DynamicObject(texture, size, switchTime, speed) {
	};
	void addAnimation();
	void update(float deltaTime);
	void draw(sf::RenderWindow &window, Player &player);
	void onCollider(sf::Vector2f direction);
	~Boss();
};

