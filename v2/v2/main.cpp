#include <GL/freeglut.h>
#include "Window.h"

Window* window = nullptr;
GLint windowInt;

void Init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
}

void KeyEvent(unsigned char key, int mouseX, int mouseY)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case ' ':
		window->BarrelRoll();
		break;
	}
}

void MouseMotionEvent(int x, int y)
{
	window->changeMouseLoc(x, y);
}

void PaintComponent(void)
{
	window->Setup(800, 600);
	window->Logic();
	window->Draw();
}

void resize(int width, int height)
{
	glutReshapeWindow(800, 600);
}

void Idle()
{
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);

	windowInt = glutCreateWindow("Plane Game");

	glutKeyboardFunc(KeyEvent);
	glutPassiveMotionFunc(MouseMotionEvent);
	glutMotionFunc(MouseMotionEvent);
	glutDisplayFunc(PaintComponent);
	glutReshapeFunc(resize);
	glutIdleFunc(Idle);

	Init();
	window = new Window();
	glutMainLoop();
	return 0;
}
