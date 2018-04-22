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
	int type;
	bool hasCheckCollider = true;
	sf::Vector2f velocity;
public:
	DynamicObject();
	DynamicObject(sf::Texture * texture, sf::Vector2f size, float switchTime, float speed, int type);	
	void setPosition(sf::Vector2f &pos);
	float getPosX() {
		return body.getPosition().x;
	}
	Collider getCollider();
	bool isHasCheckCollider();
	virtual void onCollider(sf::Vector2f direction) {};
	//virtual void draw(sf::RenderWindow& window, Player &player)=0;
	virtual void draw(sf::RenderWindow& window, Player &player) {
		std::cout << "Draw" << std::endl;
	};
	virtual void addAnimation() {};
	virtual void update(float deltaTime)  {};
	~DynamicObject();
	friend class Object;
};