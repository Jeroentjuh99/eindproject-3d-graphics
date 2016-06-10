#include "Plane.h"

Plane::Plane() : ModelLoader("models/plane/plane.obj")
{
}

Plane::~Plane()
{
}

void Plane::SetLocation(float x, float y, float z)
{
	this->location = new Vec3f(x, y, z);
}

void Plane::SetRotation(float rotX, float rotY, float rotZ)
{
	this->rotation = new Vec3f(rotX, rotY, rotZ);
}

Vec3f * Plane::GetLocation()
{
	return location;
}

Vec3f * Plane::GetRotation()
{
	return rotation;
}
