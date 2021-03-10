#include "engine.hpp"
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "Point.hpp"

Engine* Engine::instance = 0;

Engine* Engine::getInstance() {
    if (instance == 0) {
        instance = new Engine();
    }

    return instance;
}

void glVertex3f(Point point) {
	glVertex3f(point.getX(), point.getY(), point.getZ());
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	Point point1 = Point(0.0f, 1.0f, 0.0f);
	Point point2 = Point(-1.0f, -1.0f, 1.0f);
	Point point3 = Point(1.0f, -1.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(point1);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(point2);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(point3);

	glEnd();
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
	render();
}

void keyboard(unsigned char c, int x, int y) {
	if (c == 27) {
		exit(0);
	}
}

void mouse(int button, int state, int x, int y) {

}

void Engine::init(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("3D Engine");
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glewInit();
	glutMainLoop();
}

Engine::Engine() {}
