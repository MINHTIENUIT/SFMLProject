#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include "Player.h"
#include "Object.h"
#include "DynamicObject.h"
class Map
{
public:
	Map();
	void checkColider(Player & player);
	 void draw(sf::RenderWindow &window, Player &player);
	 void loadMap(Player &player);
	 
	~Map();
	
private:
	Object* objects = new Object("images/map.png");

	std::vector<DynamicObject> dynamicObjects;
	std::vector<Platform> platforms;	
};

