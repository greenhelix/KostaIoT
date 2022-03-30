#include "DrawView.h"



// 생성자 생성
DrawView::DrawView() {}

// 바둑판의 가로 세로 그리기 
void DrawView::drawLine() {

	// 줄의 색상
	glColor3f(0.0f, 0.0f, 1.0f);

	// 줄의 굵기
	glLineWidth(2.0);

	// 가로 세로를 15줄 씩 그리는 반복문
	for (int i = 0; i < 15; i++)
	{
		// 가로
		glBegin(GL_LINES);

		glVertex2f(0.f, (float)i / 15);

		glVertex2f(1.f - 0.065f, (float)i / 15);

		glEnd();

		// 세로
		glBegin(GL_LINES);

		glVertex2f((float)i / 15.f, 0.f);

		glVertex2f((float)i / 15.f, 1.0f - 0.065f);

		glEnd();
	}

}

// 바둑돌의 원형 그리기 

void DrawView::drawCircle(int color) {

	// 색상 정하기
	if (color == 1) {
		glColor3f(0.0f, 0.0f, 0.0f);
	}
	else {
		glColor3f(1.0f, 1.0f, 1.0f);

	}

	// 다각형으로 설정후
	glBegin(GL_POLYGON);

	// 원형으로 만들어주기
	for (float fAngle = 0.f; fAngle < 360.f; fAngle += 1.0f)
		glVertex2f(cos(fAngle) * radius, sin(fAngle) * radius);

}
