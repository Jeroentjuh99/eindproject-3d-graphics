#pragma once
#include "SuperObject.h"
#include <string>
#include <array>
#include <GL/freeglut.h>

class Tunnel : public SuperObject
{
public:
	Tunnel(bool);
	~Tunnel();
	void Draw();
	bool GetRotating();
	void setRotating(bool);

private:
	bool isRotating = false;
	float angle = 0;
};