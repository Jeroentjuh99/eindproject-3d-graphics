#pragma once
#include <iostream>
#include <GL/freeglut.h>

class Window {
public:
	Window();
	void Setup(int, int);
	void Draw();
};