#include "stdafx.h"
#include "Platform.h"


Platform::Platform(sf::Texture texture, sf::Vector2f size, sf::Vector2f position)
{
	mTexture = new sf::Texture(texture);
	body.setSize(size);
	body.setTexture(mTexture);
	body.setPosition(position);
	body.setOrigin(size / 2.0f);
}


Platform::~Platform()
{
}
