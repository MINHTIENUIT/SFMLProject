#pragma once
#include <vector>
#include <iostream>
#include <SFML\Graphics.hpp>
class AnimationObject
{
public:
	void addFrame(sf::IntRect rect);
	void setSpriteSheet(sf::Texture& texture);
	sf::IntRect getFrame(int i);
	sf::Texture* getSpriteSheet();
	int getSize(); 
	AnimationObject();
	~AnimationObject();
private:
	std::vector<sf::IntRect> mFrames;
	sf::Texture* mTexture;
};