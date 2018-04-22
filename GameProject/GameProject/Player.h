#pragma once
#include <SFML\Graphics.hpp>
#include <thread>
#include <mutex>
#include "Animation.h"
#include "Collider.h"

#define synchronized(m) \
    for(std::unique_lock<std::recursive_mutex> lk(m); lk; lk.unlock());

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime,float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	int OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPostion();

	Collider GetCollider() { return Collider(body); };

	bool isLive();
	void setLive(bool live);

	int getPoint() {
		return point;
	}

	void setPoint(int point) {
		std::recursive_mutex mutex;
		synchronized(mutex) {
			this->point = point;
		}		
	}
	
private:
	bool live = true;
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
	int point = 0;
};