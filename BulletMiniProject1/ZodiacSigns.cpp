#include "ZodiacSigns.h"

void ZodiacSigns::DrawSigns() {
	glPointSize(10);

	glBegin(GL_POINTS);

	//Yellow
	glColor3f(1.0, 1.0, 0.0); 

	// È²µµ 12±Ã 
	float capricorn[11][2] =
	{
		{ 0.0, 0.5 },
		{ 1.0, 0.8 },
		{ 1.1, 1.0 },
		{ -0.4, 0.6 },
		{ -0.5, 0.1 },
		{ -0.8, 0.3 },
		{ -0.8, 0.6 },
		{ -1.0, 0.6 },
		{ 0.0, -0.3 },
		{ 0.5, -0.5 },
		{ 0.7, -0.2 }
	};

	for (int i = 0; i < 11; i++)
	{
		glVertex2f(capricorn[i][0], capricorn[i][1]);
	}

	glEnd();
}
