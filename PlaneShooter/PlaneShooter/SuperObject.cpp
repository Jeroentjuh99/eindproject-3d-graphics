#include "SuperObject.h"

SuperObject::SuperObject(std::string path) : ModelLoader(path)
{
}

SuperObject::~SuperObject()
{
}

void SuperObject::SetLocation(float x, float y, float z)
{
	this->location = new Vec3f(x, y, z);
}

void SuperObject::SetRotation(float rotX, float rotY, float rotZ)
{
	this->rotation = new Vec3f(rotX, rotY, rotZ);
}

Vec3f * SuperObject::GetLocation(void) const
{
	return location;
}

std::array<float, 3> SuperObject::GetLocationFloat() const
{
	std::array<float, 3> temp = std::array<float, 3>();
	temp[0] = location->x;
	temp[1] = location->y;
	temp[2] = location->z;
	return temp;
}

Vec3f * SuperObject::GetRotation(void) const
{
	return rotation;
}

std::array<float, 3> SuperObject::GetRotationFloat() const
{
	std::array<float, 3> temp = std::array<float, 3>();
	temp[0] = rotation->x;
	temp[1] = rotation->y;
	temp[2] = rotation->z;
	return temp;
}

void SuperObject::SetColor(const float r, const float g, const float b)
{
	this->color[0] = r;
	this->color[1] = g;
	this->color[2] = b;
}

void SuperObject::Draw(void)
{
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(color[0], color[1], color[2]);
	__super::draw();
	glDisable(GL_COLOR_MATERIAL);
}

void SuperObject::SetZLocation(float z) const
{
	location->z = z;
}

float SuperObject::GetZLocation()
{
	return location->z;
}
