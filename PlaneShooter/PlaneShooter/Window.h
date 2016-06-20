#pragma once
#include <iostream>
#include <GL/freeglut.h>
#include <vector>
#include "Tunnel.h"

class Window {
public:
	Window();
	void Setup(int, int);
	void Draw();
	void changeMouseLoc(int, int) const;
	void movePlane();

private:
	std::vector<Tunnel *> objects;
	void CreateTunnel();
	void CreateTunnelObject();
	void ManageTunnel();
};