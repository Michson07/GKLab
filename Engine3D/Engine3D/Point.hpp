#pragma once
#include <GL\glew.h>
class Point
{
private:
	GLfloat x, y, z;

public:
	Point(GLfloat x, GLfloat y, GLfloat z);
	GLfloat getX();
	GLfloat getY();
	GLfloat getZ();
};

