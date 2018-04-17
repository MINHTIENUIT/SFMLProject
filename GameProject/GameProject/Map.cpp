#include "stdafx.h"
#include "Map.h"

#include <iostream>
#include <sstream>
#include <fstream>


Map::Map()
{
}

void Map::checkColider(Player & player)
{
	sf::Vector2f direction;
	for (std::vector<Platform>::iterator it = list.begin(); it != list.end(); it++)
	{
		if ((*it).getHasCollider())
		{
			if (player.GetCollider().CheckCollision((*it).GetCollider(), direction, 0))
			{
				player.OnCollision(direction);
			}
		}
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

void Map::loadMap(Player & player)
{
	std::ifstream map("map1.txt");
	std::string line;
	sf::Texture tmpTexture;
	objects.loadTexture();
	Platform *tempPlatform;
	int j = 0;
	while (std::getline(map, line)) {		
		if (j < 9) {
			for (int i = 0; i < line.length(); i++)
			{
				sf::Vector2f pos(i * 50, j * 50 + 30);
				if (line[i] < 91 && line[i]>64) {
					int at = line[i] - 65;					
					list.push_back(objects.getPlatform(at,pos));
				}
			}
		}
		j++;
	}
	objects.clear();
}