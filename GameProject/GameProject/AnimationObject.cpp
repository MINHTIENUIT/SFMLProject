#include "stdafx.h"
#include "AnimationObject.h"


void AnimationObject::addFrame(sf::IntRect rect)
{
	mFrames.push_back(rect);
}

void AnimationObject::setSpriteSheet(sf::Texture & texture)
{
	mTexture = &texture;
}

sf::IntRect AnimationObject::getFrame(int i)
{
	return mFrames[i];
}

sf::Texture * AnimationObject::getSpriteSheet()
{
	return mTexture;
}

int AnimationObject::getSize()
{
	return mFrames.size();
}

AnimationObject::AnimationObject()
{
}


AnimationObject::~AnimationObject()
{
}
