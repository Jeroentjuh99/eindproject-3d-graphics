#pragma once
#include <array>
#include <GL/freeglut.h>

#define cubesize 2

class Cube
{
public:
	Cube();
	~Cube();
	void Draw();
	void SetColor(float, float, float);
	void SetLocation(float, float, float);
	std::array<float, 3> GetColor();
	std::array<float, 3> GetLocation();

private:
	float location[3], color[3], angle = 0;
};