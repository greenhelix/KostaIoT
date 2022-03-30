#include "DrawView.h"



// ������ ����
DrawView::DrawView() {}

// �ٵ����� ���� ���� �׸��� 
void DrawView::drawLine() {

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

void DrawView::drawCircle(int color) {

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
