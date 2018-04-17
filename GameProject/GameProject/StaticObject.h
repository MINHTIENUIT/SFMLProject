#pragma once
#include <SFML\Graphics.hpp>
#include "Platform.h"
#include <iostream>
#include <fstream>
#include <vector>
class StaticObject
{
public:
	StaticObject();

	void loadTexture() {
		sf::Image imageObject;
		imageObject.loadFromFile("images/map.png");
		sf::Texture texture;		
		sf::Vector2f *size;

		//0-Brick1
		texture.loadFromImage(imageObject,sf::IntRect(221, 25, 16, 15));
		size = new sf::Vector2f(50, 50);
		platfroms.push_back(*(new Platform(texture, *size, true)));

		//1-Ong
		texture.loadFromImage(imageObject, sf::IntRect(270, 115, 30, 30));
		size = new sf::Vector2f(100, 100);
		platfroms.push_back(*(new Platform(texture, *size, true)));

		//2-Coin
		texture.loadFromImage(imageObject, sf::IntRect(290, 94, 15, 15));
		size = new sf::Vector2f(50, 50);
		platfroms.push_back(*(new Platform(texture, *size, false)));

		//3-Direct
		texture.loadFromImage(imageObject, sf::IntRect(187, 115, 47, 46));
		size = new sf::Vector2f(100, 100);		
		platfroms.push_back(*(new Platform(texture, *size, false)));

		//4-Door
		texture.loadFromImage(imageObject, sf::IntRect(374, 250, 16, 30));
		size = new sf::Vector2f(70, 140);
		platfroms.push_back(*(new Platform(texture, *size, false)));

		delete size;
	}

	Platform getPlatform(int at,sf::Vector2f pos) {
		platfroms.at(at).setPosition(pos);
		return platfroms.at(at);
	}

	void clear() {
		platfroms.clear();
	}
	~StaticObject();
private:
	std::vector<Platform> platfroms;
};