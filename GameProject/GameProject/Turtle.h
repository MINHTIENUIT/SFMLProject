#pragma once
#include "DynamicObject.h"
#include "Player.h"
class Turtle:public DynamicObject
{
private:
	bool live = true;
	int check = 0;
public:
	Turtle(sf::Texture *texture, sf::Vector2f size, float switchTime, float speed, int type) :
		DynamicObject(texture, size, switchTime, speed, type) {
	};
	void setLive(bool live);
	bool isLive();
	void addAnimation();
	void update(float deltaTime);
	void draw(sf::RenderWindow & window, Player &player);
	void onCollider(sf::Vector2f direction);	
	Turtle();
	~Turtle();
};

