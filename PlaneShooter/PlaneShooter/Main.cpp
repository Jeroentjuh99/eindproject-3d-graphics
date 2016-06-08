#include <GL/freeglut.h>
#include "Window.h"

Window* window = NULL;
GLint windowInt;

void Init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE_2D);
	GLfloat position[4] = { 0, 5, 0, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void KeyEvent(unsigned char key, int mouseX, int mouseY) {
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

void PaintComponent(void)
{
	window->Setup(800, 600);
	window->Draw();
}

void resize(int width, int height) {
	glutReshapeWindow(800, 600);
}

void Idle() {
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);

	windowInt = glutCreateWindow("PlaneShooter");

	glutKeyboardFunc(KeyEvent);
	glutDisplayFunc(PaintComponent);
	glutReshapeFunc(resize);
	glutIdleFunc(Idle);

	Init();
	window = new Window();
	glutMainLoop();
	return 0;
}