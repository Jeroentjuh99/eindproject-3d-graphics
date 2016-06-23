#pragma once
#include <iostream>
#include <GL/freeglut.h>
#include <array>
#include <string>
#include "Plane.h"
#include "Tunnel.h"
#include "Cube.h"

class Window
{
public:
	Window();
	~Window();
	void Setup(int, int);
	void Draw();
	void changeMouseLoc(int, int);
	void Logic();
	void BarrelRoll();

private:
	Plane * plane = nullptr;
	Tunnel * tunnel = nullptr;
	Cube * cube = nullptr;
	void CreateCube();
	void DrawScore();
	int score = 0;
};