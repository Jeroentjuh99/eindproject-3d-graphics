#pragma once
#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include "Tunnel.h"
#include "Cube.h"

class Window {
public:
	Window();
	~Window();
	void Setup(int, int);
	void Draw();
	void changeMouseLoc(int, int) const;
	void movePlane();
	void ManageTunnel();

private:
	std::vector<Cube *> objects;
};