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
	// 생성자 생성
	DrawView();

	// 바둑판의 가로 세로 그리기 
	void drawLine();

	// 바둑돌의 원형 그리기 
	void drawCircle(int color);

};

