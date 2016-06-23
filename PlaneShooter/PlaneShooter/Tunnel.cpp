#include "Tunnel.h"

Tunnel::Tunnel(bool isRotating) : SuperObject("models/tunnel/tunnel.obj")
{
	this->location = new Vec3f(0, 0, -5);
	this->rotation = new Vec3f(0, 0, 0);
	this->isRotating = isRotating;
}

Tunnel::~Tunnel()
{
}

void Tunnel::Draw()
{
	glTranslatef(location->x, location->y, location->z);
	glScalef(2, 2, 200);
	if(isRotating)
	{
		angle += 0.2;
		glRotatef(angle, 0, 0, 1);
	}
	__super::Draw();
	glScalef(1, 1, 1);
	glTranslatef(0, 0, 0);
}

bool Tunnel::GetRotating()
{
	return isRotating;
}

void Tunnel::setRotating(bool isRotating)
{
	this->isRotating = isRotating;
}
