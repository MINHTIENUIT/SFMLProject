#include "stdafx.h"
#include "Animation.h"


Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imgaeCount = imageCount;
	this->switchTime = switchTime;
	currentImage.x = 0;
	totalTime = 0.0f;
	uvRect.width = texture->getSize().x / (imageCount.x);
	uvRect.height = texture->getSize().y /(imageCount.y);
}

void Animation::setTexture(sf::Vector2u start, sf::Vector2u end) {
	this->start = start;
	this->end = end;
	currentImage = this->start;
}

void Animation::update(float deltaTime, bool faceRight)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= end.x) 
		{
			currentImage.x = 0;
			currentImage.y++;
			if (currentImage.y >= end.y) {
				currentImage.y = 0;
			}
		}
	}

	uvRect.top = currentImage.y*uvRect.height;
	if (faceRight)
	{
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 1)*abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

void Animation::update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imgaeCount.x)
		{
			currentImage.x = 0;			
		}
	}	
	uvRect.top = currentImage.y*uvRect.height;
	if (faceRight)
	{
		uvRect.left = currentImage.x*uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 1)*abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

Animation::~Animation()
{
}
