#pragma once
#include "SuperObject.h"

class Plane : public SuperObject
{
public:
	Plane();
	~Plane();
	void Draw();

private:
	float angle = 0.0f;
};