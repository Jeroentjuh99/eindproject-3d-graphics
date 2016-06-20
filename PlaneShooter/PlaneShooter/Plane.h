#pragma once

#include "SuperObject.h"
#include <array>
#include <GL/freeglut.h>

class Plane : public SuperObject
{
public:
	Plane();
	~Plane();
	void Draw(void);

private:
};
