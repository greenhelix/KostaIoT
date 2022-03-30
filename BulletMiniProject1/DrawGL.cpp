#include "DrawGL.h"

DrawGL::DrawGL() : DrawView() {}

// 바둑판의 크기 맞추기
void DrawGL::glDrawScale() {

	glLoadIdentity();

	glScalef(2.0, 2.0, 0);
	glTranslatef(transf_x, transf_y, 0);

	glClearColor(bR, bG, bB, 1.0f);

}

// 바둑판에 돌위치를 찾아서 원모양의 돌을 그린다.
void DrawGL::glDrawStone(float matrix[15][15][3]) {

	for (int y = 0; y < 15; y++)
		for (int x = 0; x < 15; x++)
		{
			if (matrix[y][x][2] != 0) {

				// 바둑돌의 좌표를 찾아주는 부분
				glMatrixMode(GL_MODELVIEW);

				glLoadIdentity(); // 행렬 생산

				glScalef(2.0, 2.0, 0);

				glTranslatef(transf_x, transf_y, 0);

				glTranslatef(matrix[y][x][0], matrix[y][x][1], 0);

				drawCircle(matrix[y][x][2]);

				glEnd();

				glPopMatrix();

			}
		}
}
