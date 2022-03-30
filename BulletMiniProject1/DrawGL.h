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

	// 바둑판의 크기 맞추기
	void glDrawScale();

	// 바둑판에 돌위치를 찾아서 원모양의 돌을 그린다.
	void glDrawStone(float matrix[15][15][3]);

};

