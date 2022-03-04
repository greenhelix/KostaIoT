#include "GL/glut.h"
#include <windows.h>
#include <stdio.h>
using namespace std;
#include <iostream>

float mx = 0, my = 0;
void DrawPointer() {

	glPointSize(10);

	glBegin(GL_POINTS);

	float consell[11][2] =
	{
		{0.0, 0.5},
		{1.0, 0.8},
		{1.1, 1.0},
		{-0.4, 0.6},
		{-0.5, 0.1},
		{-0.8, 0.3},
		{-0.8, 0.6},
		{-1.0, 0.6},
		{0.0, -0.3},
		{0.5, -0.5},
		{0.7, -0.2}
	};

	for (int i = 0; i < 11; i++)
	{
		glVertex2f(consell[i][0], consell[i][1]);
	}
	//for (int i = 0; i < 11; i++)
	//{
	//	glVertex2i(consell2[i][0] / WIDTH, consell2[i][1] / HEIGHT);
	//}

	glEnd();
}
void moving(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		my+= 0.1;
		cout << y << endl;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		my -= 0.1;
		cout << y << endl;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		mx-= 0.1;
		cout << x << endl;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		mx += 0.1;
		cout << x << endl;
		glutPostRedisplay();
		break;
	}
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	glLineWidth(3);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(1.1f, 1.0f);
	glVertex2f(1.0f, 0.8f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(-0.4f, 0.6f);
	glVertex2f(-0.8f, 0.6f);
	glVertex2f(-1.0f, 0.6f);
	glVertex2f(-0.8f, 0.3f);
	glVertex2f(-0.5f, 0.1f);
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.7f, -0.2f);
	glVertex2f(1.0f, 0.8f);


	glEnd();

	glPointSize(10);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 0.0f);
	float consell[11][2] =
	{
		{0.0f, 0.5f},
		{1.0f, 0.8f},
		{1.1f, 1.0f},
		{-0.4f, 0.6f},
		{-0.5f, 0.1f},
		{-0.8f, 0.3f},
		{-0.8f, 0.6f},
		{-1.0f, 0.6f},
		{0.0f, -0.3f},
		{0.5f, -0.5f},
		{0.7f, -0.2f}
	};
	for (int i = 0; i < 11; i++)
	{
		glVertex2f(consell[i][0], consell[i][1]);
	}
	glEnd();

	glPointSize(20);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.1f+mx, -0.1f+my);    // x, y
	glVertex2f(0.1f+mx, -0.1f+my);
	glVertex2f(0.1f+mx, 0.1f+my);
	glVertex2f(-0.1f+mx, 0.1f+my);
	glEnd();


	glFlush();  // Render now
}
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix

	glLoadIdentity();             // Reset the projection matrix

	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
		gluOrtho2D(-1.5 * aspect, 1.5 * aspect, -1.5, 1.5);
	}
	else {
		// aspect < 1, set the width to -1 to 1, with larger height
		gluOrtho2D(-1.5, 1.5, -1.5 / aspect, 1.5 / aspect);
	}
}


void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glClearColor(0.0f, 0.0f, 1.0f, 0.0f); // 도형은 안지워지고 배경색만 변경됨.
		exit(0);
	}
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutInitWindowSize(1000, 800);   // Set the window's initial width & height - non-square
	glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
	glutCreateWindow("Constellation");  // Create window with the given title
	
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);


	glutSpecialFunc(moving);
	glutMouseFunc(mouse);

	initGL();                       // Our own OpenGL initialization

	glutMainLoop();   
	
	

	return 0;
}