#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"
#include <iostream>
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib/glew32.lib")
#pragma comment(lib, "lib/glfw3.lib")

void display() {
	glBegin(GL_POLYGON);

	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);

	glEnd();

	glFinish();

}
int main() {
	glLineWidth(10.0);
	glBegin(GL_LINES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();
	glFinish();
}