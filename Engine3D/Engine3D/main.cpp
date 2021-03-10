#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;

static int choice = 0;

void createBlock(float a, float b, float c, float d, float e, float f, float g, float h) {
	glBegin(GL_QUADS);
	glVertex2f(a, b);
	glVertex2f(c, d);
	glVertex2f(e, f);
	glVertex2f(g, h);
	glEnd();
}

void display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	createBlock(100, 180, 180, 180, 180, 160, 100, 160);
	createBlock(100, 140, 180, 140, 180, 120, 100, 120);
	createBlock(100, 180, 120, 180, 120, 100, 100, 100);
	glutSwapBuffers();
}

void display2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	switch (choice) {
		case 0:
			glutWireTeapot(1);
			break;
		case 1:
			glutWireCone(0, 2, 3, 1);
			break;
		case 2:
			glutWireTorus(0.5, 1, 4, 6);
			break;
		case 3:
			glutWireCube(0.5);
		default:
			glutWireSphere(0.5, 10, 10);
			break;
	}
	
	glutSwapBuffers();
}

void reshape1(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void reshape2(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void klawiatura(unsigned char key, int x, int y)
{
	cout << choice;
	switch (key)
	{
		case 's':
			choice--;
			break;
		case 'w':
			choice++;
			break;
		case 'q':
			exit(0);
			break;
	}
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display1);
	glutReshapeFunc(reshape1);
	//glutDisplayFunc(display2);
	//glutReshapeFunc(reshape2);
	glutKeyboardFunc(klawiatura);
	glutMainLoop();
	return 0;

}