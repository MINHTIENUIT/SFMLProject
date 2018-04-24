#include "stdafx.h"
#include "Object.h"


Object::Object(std::string filename)
{
	image.loadFromFile(filename);
}

void Object::loadPlatform()
{
	sf::Texture texture;
	sf::Vector2f *size;
	//0-Brick1
	texture.loadFromImage(image, sf::IntRect(221, 25, 16, 15));
	platfroms.push_back(*(new Platform(texture, sf::Vector2f(50, 50), true)));

	//1-Ong
	texture.loadFromImage(image, sf::IntRect(270, 115, 30, 30));
	size = new sf::Vector2f(100, 100);
	platfroms.push_back(*(new Platform(texture, *size, true)));


	//3-Direct
	texture.loadFromImage(image, sf::IntRect(187, 115, 47, 46));
	size = new sf::Vector2f(100, 100);
	platfroms.push_back(*(new Platform(texture, *size, false)));

	//4-Door
	texture.loadFromImage(image, sf::IntRect(374, 250, 16, 30));
	size = new sf::Vector2f(70, 140);
	platfroms.push_back(*(new Platform(texture, *size, false)));
}

void Object::loadDynamic()
{

	sf::Texture texture;
	texture.loadFromImage(image);

	//1-Coin
	dynamics.push_back((new Coin(&texture, sf::Vector2f(50, 50), 0.8f, 50.0f, 1)));

	//2-Boss
	dynamics.push_back((new Boss(&texture, sf::Vector2f(100, 100), 0.4f, 50.0f, 2)));

	//3-Turtle
	dynamics.push_back((new Turtle(&texture, sf::Vector2f(75, 75), 0.4f, 50.0f, 3)));

	//4-Mushroom
	dynamics.push_back((new Mushroom(&texture, sf::Vector2f(50, 50), 0.4f, 50.0f, 4)));

	//5-Princess
	dynamics.push_back((new Princess(&texture, sf::Vector2f(50, 100), 0.4f, 50.0f, 5)));

	//6-Brick
	dynamics.push_back((new Brick(&texture, sf::Vector2f(50, 50), 0.4f, 50.0f, 6)));
}

Platform Object::getPlatform(int at, sf::Vector2f pos)
{
	platfroms.at(at).setPosition(pos);
	return platfroms.at(at);
}

void Object::getDynamicObject(std::vector<DynamicObject*>& dObjects, int at, sf::Vector2f & pos)
{
	DynamicObject * tmp = NULL;
	switch (dynamics.at(at)->type)
	{
	case 1:
		tmp = new Coin(*dynamic_cast<Coin*>(dynamics.at(at)));		
		break;
	case 2:
		tmp = new Boss(*dynamic_cast<Boss*>(dynamics.at(at)));
		break;
	case 3:
		tmp = new Turtle(*dynamic_cast<Turtle*>(dynamics.at(at)));		
		break;
	case 4:
		tmp = new Mushroom(*dynamic_cast<Mushroom*>(dynamics.at(at)));		
		break;
	case 5:
		tmp = new Princess(*dynamic_cast<Princess*>(dynamics.at(at)));
		break;
	case 6:
		tmp = new Brick(*dynamic_cast<Brick*>(dynamics.at(at)));
		break;
	default:
		break;
	}
	tmp->setPosition(pos);
	tmp->addAnimation();
	dObjects.push_back(tmp);
}
void Object::clear()
{
	platfroms.clear();
	dynamics.clear();
}


Object::~Object()
{
}
