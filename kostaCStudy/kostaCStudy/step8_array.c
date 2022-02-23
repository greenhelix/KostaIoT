#include <stdio.h>

int arGlobal[5];

void Array()
{
	int arLocal[5];

	printf("%d\n", arGlobal[0]);
	printf("%d\n", arLocal[0]);
}

void DoubleArray()
{
	int arScore[3][4] = {
		{ 92, 88, 76, 100 },
		{ 88, 74, 98, 50 },
		{ 66, 77, 94, 70 },
	};

	for (int c = 0; c < 3; c++) {
		int sum = 0;
		for (int s = 0; s < 4; s++) {
			sum += arScore[c][s];
		}
		printf("%d¹Ý : ÃÑÁ¡ = %dÁ¡, Æò±Õ = %.2fÁ¡\n", c + 1, sum, sum / 4.0);
	}
}

void WhatIsSizeOf()
{
	int a = 3;

	printf("int = %d\n", sizeof(int));
	printf("int = %d\n", sizeof(a));
	printf("int = %d\n", sizeof(double));
	printf("int = %d\n", sizeof("programming"));
}



