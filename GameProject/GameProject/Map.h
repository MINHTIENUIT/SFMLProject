#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include "Player.h"
#include "StaticObject.h"
class Map
{
public:
	Map();
	void checkColider(Player & player);
	 void draw(sf::RenderWindow &window);
	 void loadMap(Player &player);
	 
	~Map();
	
private:
	StaticObject objects;
	std::vector<Platform> list;	
};

