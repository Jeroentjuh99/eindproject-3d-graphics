#include "Tunnel.h"

Tunnel::Tunnel(bool isRotating) : SuperObject("models/tunnel/tunnel.obj")
{
	this->location = new Vec3f(0, 0, -15);
	this->rotation = new Vec3f(0, 0, 0);
	this->isRotating = isRotating;
}

Tunnel::~Tunnel()
{
}

void Tunnel::Draw()
{
	glTranslatef(location->x, location->y, location->z);
	glScalef(2, 2, 2);
	if(isRotating)
	{
		angle += 0.2;
		glRotatef(angle, 0, 0, 1);
	}
	__super::Draw();
	glScalef(1, 1, 1);
	glTranslatef(0, 0, 0);
}
