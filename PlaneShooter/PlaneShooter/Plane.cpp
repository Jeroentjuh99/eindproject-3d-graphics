#include "Plane.h"

Plane::Plane() : SuperObject("models/plane/plane.obj")
{
	this->location = new Vec3f(0, 0, -5);
	this->rotation = new Vec3f(0, 0, 0);
}

Plane::~Plane()
{
}

void Plane::Draw()
{
	glTranslatef(location->x, location->y, location->z);
	glScalef(0.7, 0.7, -0.7);
	__super::Draw();
	glScalef(1, 1, 1);
	glTranslatef(0, 0, 0);
}
