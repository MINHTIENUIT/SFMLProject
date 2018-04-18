#include "stdafx.h"
#include "DynamicObject.h"


DynamicObject::DynamicObject(sf::Texture * texture, sf::Vector2f size, float switchTime, float speed)
{
	mTexture = *texture;
	this->switchTime = switchTime;
	this->speed = speed;
	this->totalTime = 0.0f;
	this->coutFrame = 0;
	body.setSize(size);
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(&mTexture);
	animation.setSpriteSheet(mTexture);
	hasCheckCollider = true;
}


void DynamicObject::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}

Collider DynamicObject::getCollider() {
	return Collider(body);
};

void DynamicObject::draw(sf::RenderWindow & window,Player &player)
{
	window.draw(body);
}

DynamicObject::~DynamicObject()
{
}
