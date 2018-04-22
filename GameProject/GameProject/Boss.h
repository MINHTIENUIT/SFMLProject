#pragma once
#include "DynamicObject.h"
#include "Player.h"
class Boss:public DynamicObject
{
private:
	bool live=true;
public:	
	Boss(sf::Texture *texture, sf::Vector2f size, float switchTime, float speed, int type) :
		DynamicObject(texture, size, switchTime, speed, type) {
	};
	void setLive(bool live);
	bool isLive();
	void addAnimation();
	void update(float deltaTime);
	void draw(sf::RenderWindow &window, Player &player);
	void onCollider(sf::Vector2f direction);
	~Boss();
};

