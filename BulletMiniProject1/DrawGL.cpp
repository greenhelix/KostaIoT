#include "DrawGL.h"

DrawGL::DrawGL() : DrawView() {}

// �ٵ����� ũ�� ���߱�
void DrawGL::glDrawScale() {

	glLoadIdentity();

	glScalef(2.0, 2.0, 0);
	glTranslatef(transf_x, transf_y, 0);

	glClearColor(bR, bG, bB, 1.0f);

}

// �ٵ��ǿ� ����ġ�� ã�Ƽ� ������� ���� �׸���.
void DrawGL::glDrawStone(float matrix[15][15][3]) {

	for (int y = 0; y < 15; y++)
		for (int x = 0; x < 15; x++)
		{
			if (matrix[y][x][2] != 0) {

				// �ٵϵ��� ��ǥ�� ã���ִ� �κ�
				glMatrixMode(GL_MODELVIEW);

				glLoadIdentity(); // ��� ����

				glScalef(2.0, 2.0, 0);

				glTranslatef(transf_x, transf_y, 0);

				glTranslatef(matrix[y][x][0], matrix[y][x][1], 0);

				drawCircle(matrix[y][x][2]);

				glEnd();

				glPopMatrix();

			}
		}
}
