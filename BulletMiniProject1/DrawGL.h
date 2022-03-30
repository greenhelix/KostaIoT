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
	DrawGL();

	// �ٵ����� ũ�� ���߱�
	void glDrawScale();

	// �ٵ��ǿ� ����ġ�� ã�Ƽ� ������� ���� �׸���.
	void glDrawStone(float matrix[15][15][3]);

};

