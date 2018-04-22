#include "stdafx.h"
#include "Platform.h"
#include <iostream>

Platform::Platform(sf::Texture texture, sf::Vector2f size, bool hasCheckCollider)
{
	mTexture = new sf::Texture(texture);
	body.setSize(size);
	body.setTexture(mTexture);
	body.setOrigin(size / 2.0f);
	this->hasCheckCollider = hasCheckCollider;
}

void Platform::setPosition(sf::Vector2f position)
{
	body.setPosition(position);	
}




Platform::~Platform()
{
}

bool Platform::getHasCollider()
{
	return hasCheckCollider;
}
