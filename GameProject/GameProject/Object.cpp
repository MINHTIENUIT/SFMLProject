#include "stdafx.h"
#include "Object.h"


Object::Object(std::string filename)
{
	image.loadFromFile(filename);
}


Object::~Object()
{
}
