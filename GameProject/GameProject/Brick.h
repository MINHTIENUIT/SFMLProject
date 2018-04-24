#pragma once
#include "AnimationObject.h"
#include "DynamicObject.h"
class Brick: public DynamicObject
{
public:
	Brick(sf::Texture *texture, sf::Vector2f size, float switchTime, float speed, int type) :
		DynamicObject(texture, size, switchTime, speed, type) {
	}

	void addAnimation();
	void update(float deltaTime);
	void draw(sf::RenderWindow &window, Player &player) override;
	void onCollider(sf::Vector2f direction);
	~Brick();
};

