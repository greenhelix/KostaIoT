#pragma once
#include "DrawView.h"

class DrawGL : public DrawView
{
private:
	float transf_x = -0.47;
	float transf_y = -0.47;
	float bR = (float)152 / 255;
	float bG = (float)102 / 255;
	float bB = (float)52 / 255;

public:
	DrawGL() : DrawView() {}

	// �ٵ����� ũ�� ���߱�
	void glDrawScale() {

		glClearColor(bR, bG, bB, 1.0f);

		glLoadIdentity();

		glScalef(2.0, 2.0, 0);

		glTranslatef(-0.47, -0.47, 0);
	}

	// �ٵ��ǿ� ����ġ�� ã�Ƽ� ������� ���� �׸���.
	void glDrawStone(float matrix[15][15][3]) {

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

};

