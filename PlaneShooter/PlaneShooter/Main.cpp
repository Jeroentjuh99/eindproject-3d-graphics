#include <GL/freeglut.h>
#include "Window.h"

Window* window = nullptr;
GLint windowInt;

void Init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
}

void KeyEvent(unsigned char key, int mouseX, int mouseY) {
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

void MouseMotionEvent(int x, int y)
{
	window->changeMouseLoc(x, y);
}

void PaintComponent(void)
{
	window->Setup(1000, 1000);
	window->Draw();
}

void resize(int width, int height) {
	glutReshapeWindow(1000, 1000);
}

void Idle() {
	window->movePlane();
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);

	windowInt = glutCreateWindow("Tunnel Warrior");

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