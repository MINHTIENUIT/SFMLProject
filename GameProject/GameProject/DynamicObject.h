#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "AnimationObject.h"
#include "collider.h"
#include "Player.h"
class DynamicObject
{
protected:
	sf::Texture mTexture;
	sf::RectangleShape body;
	float switchTime;
	float speed;
	float totalTime;
	AnimationObject animation;
	int coutFrame;
	bool hasCheckCollider;
	sf::Vector2f velocity;
public:
	DynamicObject(sf::Texture * texture, sf::Vector2f size, float switchTime, float speed);
	virtual void addAnimation() {};
	virtual void update(float deltaTime) {};
	void setPosition(sf::Vector2f pos);
	Collider getCollider();
	virtual void onCollider(sf::Vector2f direction) {};
	virtual void draw(sf::RenderWindow& window, Player &player);
	~DynamicObject();
};