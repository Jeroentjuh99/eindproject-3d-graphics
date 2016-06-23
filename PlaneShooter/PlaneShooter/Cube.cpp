#include "Cube.h"

Cube::Cube(float x, float y, float z)
{
	location[0] = x;
	location[1] = y;
	location[2] = z;
}

Cube::~Cube()
{
	delete location;
	delete color;
}

void Cube::Draw()
{
	glPushMatrix();
	glTranslatef(location[0], location[1], location[2]);
	glBegin(GL_QUADS);
	glColor3f(color[0], color[1], color[2]);
	glVertex3f(cubesize, -cubesize, -cubesize);
	glVertex3f(cubesize, cubesize, -cubesize);
	glVertex3f(-cubesize, cubesize, -cubesize);
	glVertex3f(-cubesize, -cubesize, -cubesize);

	// BACK
	glVertex3f(cubesize, -cubesize, cubesize);
	glVertex3f(cubesize, cubesize, cubesize);
	glVertex3f(-cubesize, cubesize, cubesize);
	glVertex3f(-cubesize, -cubesize, cubesize);

	// LEFT
	glVertex3f(-cubesize, -cubesize, cubesize);
	glVertex3f(-cubesize, cubesize, cubesize);
	glVertex3f(-cubesize, cubesize, -cubesize);
	glVertex3f(-cubesize, -cubesize, -cubesize);

	// RIGHT
	glVertex3f(cubesize, -cubesize, -cubesize);
	glVertex3f(cubesize, cubesize, -cubesize);
	glVertex3f(cubesize, cubesize, cubesize);
	glVertex3f(cubesize, -cubesize, cubesize);

	// TOP
	glVertex3f(cubesize, cubesize, cubesize);
	glVertex3f(cubesize, cubesize, -cubesize);
	glVertex3f(-cubesize, cubesize, -cubesize);
	glVertex3f(-cubesize, cubesize, cubesize);

	// BOTTOM
	glVertex3f(cubesize, -cubesize, -cubesize);
	glVertex3f(cubesize, -cubesize, cubesize);
	glVertex3f(-cubesize, -cubesize, cubesize);
	glVertex3f(-cubesize, -cubesize, -cubesize);
	glEnd();
	glPopMatrix();
}

void Cube::SetColor(float i, float ii, float iii)
{
	color[0] = i;
	color[1] = ii;
	color[2] = iii;
}

float * Cube::GetColor()
{
	return color;
}

float * Cube::GetLocation()
{
	return location;
}
