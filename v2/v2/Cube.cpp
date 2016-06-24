#include "Cube.h"

Cube::Cube()
{
}

Cube::~Cube()
{
}

void Cube::Draw()
{
	glPushMatrix();
	glTranslatef(location[0], location[1], location[2]);
	glDisable(GL_TEXTURE_2D);
	GLfloat ambient[4] = {color[0] * 0.5f, color[1] * 0.5f, color[2] * 0.5f, 0.8f};
	GLfloat diffuse[4] = {color[0], color[1], color[2], 0.8f};
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
	glRotatef(40, 1, 1, 0);
	//	glEnable(GL_COLOR_MATERIAL);
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
	//	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_TEXTURE_2D);
	glPopMatrix();
}

void Cube::SetColor(float r, float g, float b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void Cube::SetLocation(float x, float y, float z)
{
	location[0] = x;
	location[1] = y;
	location[2] = z;
}

std::array<float, 3> Cube::GetColor()
{
	std::array<float, 3> temp;
	temp[0] = color[0];
	temp[1] = color[1];
	temp[2] = color[2];
	return temp;
}

std::array<float, 3> Cube::GetLocation()
{
	std::array<float, 3> temp;
	temp[0] = location[0];
	temp[1] = location[1];
	temp[2] = location[2];
	return temp;
}
