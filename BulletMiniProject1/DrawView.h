#pragma once
#include <GL/glut.h>
#include <GL/GLU.h>
#include <cmath>
#include <iostream>

using namespace std;

class DrawView
{
private:
	float bR = (float)152 / 255;
	float bG = (float)102 / 255;
	float bB = (float)52 / 255;
	float radius = 0.03f;
	float transf_x = -0.47;
	float transf_y = -0.47;
public:
	// ������ ����
	DrawView(){}

	// �ٵ����� ���� ���� �׸��� 
	void drawLine() {

		// ���� ����
		glColor3f(0.0f, 0.0f, 1.0f);

		// ���� ����
		glLineWidth(2.0);

		// ���� ���θ� 15�� �� �׸��� �ݺ���
		for (int i = 0; i < 15; i++)
		{
			// ����
			glBegin(GL_LINES);

			glVertex2f(0.f, (float)i / 15);

			glVertex2f(1.f - 0.065f, (float)i / 15);

			glEnd();

			// ����
			glBegin(GL_LINES);

			glVertex2f((float)i / 15.f, 0.f);

			glVertex2f((float)i / 15.f, 1.0f - 0.065f);

			glEnd();
		}

	}

	// �ٵϵ��� ���� �׸��� 
	void drawCircle(int color) {

		// ���� ���ϱ�
		if (color == 1) {
			glColor3f(0.0f, 0.0f, 0.0f);
		}
		else {
			glColor3f(1.0f, 1.0f, 1.0f);

		}

		// �ٰ������� ������
		glBegin(GL_POLYGON);

		// �������� ������ֱ�
		for (float fAngle = 0.f; fAngle < 360.f; fAngle += 1.0f)
			glVertex2f(cos(fAngle) * radius, sin(fAngle) * radius);

	}

};

