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
	sf::Vector2f direction1;
	for (std::vector<Platform>::iterator it = platforms.begin(); it != platforms.end(); it++)
	{
		if ((*it).getHasCollider())
		{
			if (player.GetCollider().CheckCollision((*it).GetCollider(), direction1, 0))
			{
				player.OnCollision(direction1);
			}
			for (int j = 0; j < dynamicObjects.size(); j++) {
				sf::Vector2f direction2;
				if (dynamicObjects.at(j).getCollider().CheckCollision((*it).GetCollider(), direction2, 0))
				{
					dynamicObjects.at(j).onCollider(direction2);
				}
			}
		}
	}
}


void Map::draw(sf::RenderWindow & window,Player &player)
{
	
	for (std::vector<Platform>::iterator it = platforms.begin();it!=platforms.end();it++)
	{
		(*it).Draw(window);
	}
	for (std::vector<DynamicObject>::iterator it = dynamicObjects.begin(); it != dynamicObjects.end(); it++)
	{
		(*it).draw(window,player);
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
	objects->loadPlatform();
	objects->loadDynamic();
	int j = 0;
	while (std::getline(map, line)) {		
		if (j < 9) {
			for (int i = 0; i < line.length(); i++)
			{
				sf::Vector2f pos(i * 50, j * 50 + 30);
				if (line[i] < 91 && line[i]>64) {
					int at = line[i] - 65;					
					platforms.push_back(objects->getPlatform(at,pos));
				}
				if (line[i] <122 && line[i] > 96) {
					int at = line[i] - 97;
					dynamicObjects.push_back(objects->getDynamicObject(at, pos));
				};
			}
		}
		j++;
	}
	objects->clear();
	delete objects;
}