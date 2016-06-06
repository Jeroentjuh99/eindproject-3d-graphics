#include <GL/freeglut.h>
#include "ModelLoader.h"
#include "Model.h"

float width = 1920, height = 1080, lastFrameTime = 0;
ModelLoader* loader;

struct Camera
{
	float posX = 0;
	float posY = 0;
	float posZ = 0;
	float rotX = 0;
	float rotY = 0;
	float rotZ = 0;
} camera;

void SetupWindow()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.05f, 0.05f, 0.05f, 1.0f);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (width / height), 0.1f, 30);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glTranslatef(camera.posX, 0, camera.posY);
}

void Draw() {
	SetupWindow();

	for (auto& model : loader->GetModels()) {
		model.Draw();
	}
}

void KeyEvent(unsigned char key, int mouseX, int mouseY) {

}

void MouseMotionEvent(int x, int y) {

}

void Idle() {
	float frameTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;
	float deltaTime = frameTime - lastFrameTime;
	lastFrameTime = frameTime;

	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	loader = new ModelLoader();
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(int(width), int(height));
	glutInit(&argc, argv);
	glutCreateWindow("PlaneShooter");

	glEnable(GL_DEPTH_TEST);

	glutIdleFunc(Idle);
	glutDisplayFunc(Draw);
	
	glutMainLoop();
	return 0;
}