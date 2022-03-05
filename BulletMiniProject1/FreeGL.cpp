#include "GL/glut.h"
#include <windows.h>
#include <stdio.h>
using namespace std;
#include <iostream>
#include "ZodiacSigns.h"

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
	cout <<"마우스 위치" <<x<< "," << y << endl;

	switch (key) {
	case GLUT_KEY_UP:
		my += 0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		my -= 0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		mx -= 0.1;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		mx += 0.1;
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

	ZodiacSigns a;
	a.DrawSigns();


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


	glPointSize(20);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.05f + mx, -0.05f + my); 
	glVertex2f(0.05f + mx, -0.05f + my);
	glVertex2f(0.05f + mx, 0.05f + my);
	glVertex2f(-0.05f + mx, 0.05f + my);
	glEnd();


	glFlush();
}

//void initGL() {
//	// Set "clearing" or background color
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
//}

void reshape(GLsizei width, GLsizei height) {  
   
	if (height == 0) height = 1;                
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	
	glViewport(0, 0, width, height);
	
	glMatrixMode(GL_PROJECTION);  

	glLoadIdentity();             

	if (width >= height) {
		
		gluOrtho2D(-1.5 * aspect, 1.5 * aspect, -1.5, 1.5);
	}
	else {
		
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

	glutInit(&argc, argv);          
	glutInitWindowSize(1000, 800);   
	glutInitWindowPosition(50, 50); 
	glutCreateWindow("Constellation"); 

	glutDisplayFunc(display);       
	glutReshapeFunc(reshape);

	glutSpecialFunc(moving);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}