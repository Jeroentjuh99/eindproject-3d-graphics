#include "Window.h"

Window::Window()
{
	plane = new Plane();
	tunnel = new Tunnel();
	CreateCube();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	std::cout << "Ready to Roll! \n";
}

Window::~Window()
{
	plane = nullptr;
	tunnel = nullptr;
	cube = nullptr;
}

void Window::Setup(int windowWidth, int windowHeight)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, float(windowWidth / windowHeight), 0.1, 200);

	std::array<float, 3> loc = plane->GetLocation();
	gluLookAt(loc[0] / 10, -loc[1] / 10, loc[2] + 15, 0, 0, loc[2], 0, 1, 0);
}

void Window::Draw()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glPushMatrix();
	plane->Draw();
	glPopMatrix();

	glPushMatrix();
	tunnel->Draw();
	glPopMatrix();

	glPushMatrix();
	cube->Draw();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void Window::changeMouseLoc(int x, int y)
{
	plane->SetLocation(float(x / 25 - 15), -float(y / 25 - 10), plane->GetLocation()[2]);
}

void Window::Logic()
{
	GLfloat position[4] = {plane->GetLocation()[0], plane->GetLocation()[1], plane->GetLocation()[2], 0.1};
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	cube->SetLocation(cube->GetLocation()[0] + 0.05 * plane->GetLocation()[0], cube->GetLocation()[1] + 0.05 * plane->GetLocation()[1], cube->GetLocation()[2] + 0.05);

	std::array<float, 3> temp = cube->GetLocation(), planetemp = plane->GetLocation();
	if (temp[2] + cubesize > planetemp[2] && temp[2] - cubesize < planetemp[2])
	{
		if (temp[0] + cubesize > planetemp[0] && temp[0] - cubesize < planetemp[0])
		{
			if (temp[1] + cubesize > planetemp[1] && temp[1] - cubesize < planetemp[1])
			{
				plane->SetColor(cube->GetColor()[0], cube->GetColor()[1], cube->GetColor()[2]);
				tunnel->SetRotating(!tunnel->GetRotating());
				score++;
				CreateCube();
			}
		}
	}

	if (temp[2] > 15)
	{
		CreateCube();
	}
}

void Window::BarrelRoll()
{
	plane->SetRotation(0, 0, 360);
}

void Window::CreateCube()
{
	cube = new Cube();
	cube->SetLocation(rand() % 10 - 5, rand() % 10 - 5, -50);
	cube->SetColor(float(rand() % 100) / 100, float(rand() % 100) / 100, float(rand() % 100) / 100);
}

void Window::DrawScore()
{
	glLoadIdentity();
	std::string text = "Score: " + std::to_string(score);
	for (int i = 0; i < text.length(); i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	}
}
