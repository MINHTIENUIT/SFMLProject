#pragma once
#include <SFML\Graphics.hpp>
#include "Platform.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "DynamicObject.h"
#include "Coin.h"
#include "Boss.h"
#include "Turtle.h"
#include "Mushroom.h"
#include "Princess.h"
#include "Brick.h"
class Object
{
public:
	Object(std::string filemap);

	void loadPlatform();

	void loadDynamic(); 

	Platform getPlatform(int at, sf::Vector2f pos);

	void getDynamicObject(std::vector<DynamicObject*> &dObjects, int at, sf::Vector2f &pos);

	void clear(); 
	~Object();
private:
	sf::Image image;
	std::vector<DynamicObject*> dynamics;
	std::vector<Platform> platfroms;
};