#include "Tunnel.h"

Tunnel::Tunnel() : SuperObject("tunnel/tunnel.obj", false)
{
	location[2] = -5;
}

Tunnel::~Tunnel()
{
}

void Tunnel::Draw()
{
	glTranslatef(location[0], location[1], location[2]);
	glScalef(2.5, 2.5, 2);
	if (isRotating)
	{
		angle += 0.2f;
	}
	glRotatef(angle, 0, 0, 1);
	
	__super::Draw();
	glScalef(1, 1, 1);
	glTranslatef(0, 0, 0);
}

bool Tunnel::GetRotating()
{
	return isRotating;
}

void Tunnel::SetRotating(bool rotating)
{
	isRotating = rotating;
}
