#include "Plane.h"

Plane::Plane() : SuperObject("plane/plane.obj", true)
{
	location[2] = -5;
	color[0] = 0.5f;
	color[1] = 0.0f;
	color[2] = 1.0f;
}

Plane::~Plane()
{
}

void Plane::Draw()
{
	glTranslatef(location[0], location[1], location[2]);
	glScalef(0.7, 0.7, -0.7);
	if (rotation[2] != 0)
	{
		angle--;
		rotation[2]--;
	}
	else
	{
		if (angle != 0)
			angle = 0;
	}
	glRotatef(angle, 0, 0, 1);
	__super::Draw();
	glScalef(1, 1, 1);
	glTranslatef(0, 0, 0);
}