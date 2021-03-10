#include "Point.hpp"

Point::Point(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GLfloat Point::getX()
{
	return this->x;
}

GLfloat Point::getY()
{
	return this->y;
}

GLfloat Point::getZ()
{
	return this->z;
}

