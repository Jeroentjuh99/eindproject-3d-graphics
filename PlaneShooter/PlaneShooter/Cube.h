#pragma once
#include <GL/freeglut.h>

#define cubesize 2

class Cube
{
public:
	Cube(float, float, float);
	~Cube();
	void Draw();
	void SetColor(float, float, float);
	float* GetColor();
	float* GetLocation();


private:
	float location[3], color[3];
	float angle = 0;
};