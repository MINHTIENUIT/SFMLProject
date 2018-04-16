#include "stdafx.h"
#include "Map.h"

#include <iostream>
#include <sstream>
#include <fstream>


Map::Map()
{
}

void Map::loadmap()
{
	std::ifstream map("map.txt");
	std::string line;	
	while (std::getline(map, line)) {
		std::vector<std::string> convert;
		if (line.find('-') !=0) {
			convert = split(line, ':');
			std::string rect = convert[0];
			std::string size = convert[1];
			std::string pos = convert[2];
			sf::Texture tmpTexture;
			tmpTexture.loadFromFile("images/map.png", getRect(rect));
			Platform tempPlatform(tmpTexture, convertVector(size), convertVector(pos));
			list.push_back(tempPlatform);
		}		
	}
}

void Map::checkColider(Player & player)
{
	for (std::vector<Platform>::iterator it = list.begin(); it != list.end(); it++)
	{		
		player.GetCollider().CheckCollision((*it).GetCollider(), 0);
	}	
}


void Map::draw(sf::RenderWindow & window)
{
	
	for (std::vector<Platform>::iterator it = list.begin();it!=list.end();it++)
	{
		(*it).Draw(window);
	}
}

Map::~Map()
{
}

sf::IntRect Map::getRect(std::string s)
{
	std::vector<std::string> rectString;
	rectString = split(s, ',');
	int tmp[4];
	for (int i = 0; i < rectString.size(); i++)
	{
		std::stringstream geek(rectString[i]);
		geek >> tmp[i];
	}
	return sf::IntRect(tmp[0],tmp[1],tmp[2],tmp[3]);
}

sf::Vector2f Map::convertVector(std::string s)
{	
	std::vector<std::string> vectorString;
	vectorString = split(s, ',');
	int tmp[2];
	for (int i = 0; i < vectorString.size(); i++)
	{
		std::stringstream geek(vectorString[i]);
		geek >> tmp[i];
	}
	return sf::Vector2f(tmp[0],tmp[1]);
}

std::vector<std::string> Map::split(const std::string & s, char delim)
{
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
	return std::vector<std::string>();
}