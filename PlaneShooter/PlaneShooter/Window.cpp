#include "Window.h"

Window::Window()
{
	std::cout << "ready to roll";
}

void Window::Setup(int W_width, int W_height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, W_width, W_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (float)W_width / W_height, 0.1, 100);
}

void Window::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glPushMatrix();

	/*
	stuff here
	*/
	
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
