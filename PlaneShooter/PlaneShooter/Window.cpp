#include "Window.h"
#include <array>
#include "Plane.h"
#include "Tunnel.h"

Plane *plane = nullptr;
Tunnel *t;
float lenght;

Window::Window()
{
	plane = new Plane();
	t = new Tunnel(false);
	lenght = t->getZFormat();
	std::cout << lenght << "\n";
	objects.push_back(t);
	std::cout << "ready to roll";
	CreateTunnel();
}

void Window::Setup(int W_width, int W_height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, W_width, W_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, float(W_width / W_height), 0.1, 100);

	std::array<float,3> loc = plane->GetLocationFloat();
	gluLookAt(0, 0, loc[2] + 15, 0, 0, loc[2], 0, 1, 0);
}

void Window::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();

	plane->SetColor(1.0f, 0.5f, 0.0f);
	plane->Draw();

	glPopMatrix();
	glPushMatrix();

	for (auto obj : objects)
	{
		obj->Draw();
	}

	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat position[4] = { plane->GetLocation()->x, plane->GetLocation()->y, plane->GetLocation()->z, 0.5 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glFlush();
	glutSwapBuffers();
}

void Window::changeMouseLoc(int x, int y) const
{
	plane->SetLocation(float(x)/50 -10, -float(y)/50 +10, plane->GetLocation()->z);
}

void Window::movePlane()
{
	plane->SetZLocation(plane->GetZLocation() - 0.1);
}

void Window::CreateTunnel()
{
	for(int i = 0; i < 5; i++)
	{
		CreateTunnelObject();
	}
}

void Window::CreateTunnelObject()
{
	Tunnel * t = new Tunnel(rand() % 2);
	t->SetLocation(0, 0, objects.at(0)->GetLocation()->z + 7.9223);
	objects.push_back(t);
}

void Window::ManageTunnel()
{
	for (auto tunnel : objects)
	{
		if(tunnel->GetLocation()->z + 8 < plane->GetLocation()->z - 15)
		{
			objects.erase(std::find(objects.begin(), objects.end(), tunnel) - 1);
			CreateTunnelObject();
		}
	}
}
