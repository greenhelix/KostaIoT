#include <stdio.h>
#include <math.h>

void floorFunction()
{
	// floor 내림 ceil 올림 
	printf("floor(3.14) = %.2f\n", floor(3.14));
	printf("ceil(3.14) = %.2f\n", ceil(3.14));
	printf("floor(-3.14) = %.2f\n", floor(-3.14));
	printf("ceil(-3.14) = %.2f\n", ceil(-3.14));
}

void castInt()
{
	// cast 연산자는 소수부를 강제로 자른다.
	double d = 3.14;
	int i = d;
	printf("%d\n", i);
	d = -3.14;
	i = d;
	printf("%d\n", i);
}

#define banollim(x, dig) (floor((x)*pow(10.0, dig)+0.5)/pow(10.0, dig))
void banolim()
{
	double x = 123.456789;
	int i; 
	for (int i = -2; i < 5; i++)
	{
		printf("%f의 %d자리 반올림 = %f \n", x, i, banollim(x, i));
	}
}