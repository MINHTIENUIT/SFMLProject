#pragma once
#include <SFML\Graphics.hpp>
#include "Platform.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "DynamicObject.h"
#include "Coin.h"
#include "Boss.h"
class Object
{
public:
	Object(std::string filemap);

	void loadPlatform() {		
		sf::Texture texture;		
		sf::Vector2f *size;		
		//0-Brick1
		texture.loadFromImage(image,sf::IntRect(221, 25, 16, 15));
		size = new sf::Vector2f(50, 50);
		platfroms.push_back(*(new Platform(texture, *size, true)));

		//1-Ong
		texture.loadFromImage(image, sf::IntRect(270, 115, 30, 30));
		size = new sf::Vector2f(100, 100);
		platfroms.push_back(*(new Platform(texture, *size, true)));

		//2-Coin
		texture.loadFromImage(image, sf::IntRect(290, 94, 15, 15));
		size = new sf::Vector2f(50, 50);
		platfroms.push_back(*(new Platform(texture, *size, false)));

		//3-Direct
		texture.loadFromImage(image, sf::IntRect(187, 115, 47, 46));
		size = new sf::Vector2f(100, 100);		
		platfroms.push_back(*(new Platform(texture, *size, false)));

		//4-Door
		texture.loadFromImage(image, sf::IntRect(374, 250, 16, 30));
		size = new sf::Vector2f(70, 140);
		platfroms.push_back(*(new Platform(texture, *size, false)));

		delete size;
	}

	void loadDynamic() {
		sf::Texture texture;		
		texture.loadFromImage(image);
		
		//1-Coin
		dynamics.push_back(*(new Coin(&texture,sf::Vector2f(50,50),0.4f,20.0f)));
		
		//2-Boss
		dynamics.push_back(*(new Boss(&texture, sf::Vector2f(100, 100), 0.4f, 0.4f)));
	}

	Platform getPlatform(int at,sf::Vector2f pos) {
		platfroms.at(at).setPosition(pos);
		return platfroms.at(at);
	}

	DynamicObject getDynamicObject(int at, sf::Vector2f pos) {		
		dynamics.at(at).setPosition(pos);
		dynamics.at(at).addAnimation();
		return dynamics.at(at);
	};

	void clear() {
		platfroms.clear();
		dynamics.clear();
	}
	~Object();
private:
	sf::Image image;
	std::vector<DynamicObject> dynamics;
	std::vector<Platform> platfroms;
};