#include "Window.h"
#include <array>
#include "Plane.h"
#include "Tunnel.h"

Plane *plane = nullptr;
Tunnel *t;
float lenght;
int lastZ;

Window::Window()
{
	plane = new Plane();
	t = new Tunnel(false);
	lenght = t->getZFormat();
	std::cout << "ready to roll";
}

Window::~Window()
{
	objects.clear();
	t = nullptr;
	plane = nullptr;
}

void Window::Setup(int W_width, int W_height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, W_width, W_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, float(W_width / W_height), 0.1, 200);

	std::array<float,3> loc = plane->GetLocationFloat();
	gluLookAt(loc[0]/10, -loc[1]/10, loc[2] + 15, 0, 0, loc[2], 0, 1, 0);
}

void Window::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();

	plane->SetColor(1.0f, 0.5f, 0.0f);
	plane->Draw();

	glPopMatrix();
	glPushMatrix();

	t->Draw();
	for (auto obj : objects)
	{
		obj->Draw();
	}

	glPopMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat position[4] = { plane->GetLocation()->x, plane->GetLocation()->y, plane->GetLocation()->z, 0.1 };
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

void Window::ManageTunnel()
{
	int tempZ = -int(plane->GetLocation()->z);
	if (tempZ != lastZ) {
		if ((tempZ % 15) == 0)
		{
			std::cout << "cube \n";
			Cube *c = new Cube(rand() % 8 - 4, rand() % 8 - 4, plane->GetLocation()->z - 20);
			//Cube *c = new Cube(plane->GetLocation()->x, plane->GetLocation()->y, plane->GetLocation()->z);
			c->SetColor(rand() % 1, rand() % 1, rand() % 1);
			std::cout << c->GetLocation()[0] << " " << c->GetLocation()[1] << " " << c->GetLocation()[2] << " " <<  plane->GetLocation()->z << " " << objects.size() << "\n";
			objects.push_back(c);
		}
		lastZ = tempZ;
	}
	Vec3f* a = plane->GetLocation();
	for (auto p : objects)
	{
		if(a->z > p->GetLocation()[2] - cubesize && a->z < p->GetLocation()[2] + cubesize)
		{
			if(a->z > p->GetLocation()[0] - cubesize && a->z < p->GetLocation()[0] + cubesize)
			{
				if (a->z > p->GetLocation()[1] - cubesize && a->z < p->GetLocation()[1] + cubesize)
				{
					plane->SetColor(p->GetColor()[0], p->GetColor()[1], p->GetColor()[2]);
				}
			}
		}
	}
}
