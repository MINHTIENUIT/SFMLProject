#pragma once
#include <vector>
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include "Player.h"
#include <string>
#include <sstream>
class Map
{
public:
	Map();
	 void loadmap();
	 void checkColider(Player & player);
	 void draw(sf::RenderWindow &window);
	~Map();
private:
	sf::IntRect getRect(std::string s);
	sf::Vector2f convertVector(std::string s);
	std::vector<std::string> split(const std::string &s, char delim);
private:
	std::vector<Platform> list;	
};

