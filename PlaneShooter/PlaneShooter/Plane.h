#pragma once

#include "ModelLoader.h"

class Plane : public ModelLoader
{
public:
	Plane();
	~Plane();
	void SetLocation(float, float, float);
	void SetRotation(float, float, float);
	Vec3f * GetLocation();
	Vec3f * GetRotation();

private:
	Vec3f *location, *rotation;
};