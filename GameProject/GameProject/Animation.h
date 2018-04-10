#pragma once
#include <SFML\Graphics.hpp>
class Animation
{
private:
	sf::Vector2u imgaeCount;
	sf::Vector2u currentImage;
	sf::Vector2u start;
	sf::Vector2u end;
	float totalTime;
	float switchTime;
public:
	sf::IntRect uvRect;
private:

public:
	Animation(sf::Texture* texture,sf::Vector2u imageCount, float switchTime);
	void setTexture(sf::Vector2u start, sf::Vector2u end);
	void update(float deltaTime, bool faceRight);
	void update(int row, float deltaTime, bool faceRight);
	~Animation();	
};

