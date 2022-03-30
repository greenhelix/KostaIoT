#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define banollim(x, dig) (floor((x)*pow(10.0, dig)+0.5)/pow(10.0, dig))
#include <stdlib.h>

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

void banolim()
{
	double x = 123.456789;
	int i; 
	for (int i = -2; i < 5; i++)
	{
		printf("%f의 %d자리 반올림 = %f \n", x, i, banollim(x, i));
	}
}

void absrange()
{
	int input;
	printf("10~50 사이의 숫자를 입력하세요. : ");
	scanf_s("%d", &input);
	if (abs(input -30) <= 20)
	{
		puts("범위안의 숫자입니다.");
	}
	else {
		puts("범위를 벗어났습니다.");
	}
}

void sinCal()
{
	int angle;
	for (int angle = 0; angle <= 90; angle+15)
	{
		printf("sin(%d도) = %f\n", angle, sin(angle * 3.14 / 180));
	}
}


void whatIsExit() 
{
	// 종료하다 정상종료 0 , 비정상 종료 1 
	int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d",&input);
	exit(0);
	// 아래의 출력 부분이 실행되지 않고 함수가 종료 됩니다.
	printf("exit()함수가 실행되었습니다.");
	return 0;
}

void whatIsAbort()
{
	// 중단하다
	int a = 15;
	printf("The value of a : %d\n", a);
	abort();
	printf("Calling of abort()");
}

void whatIsSystem()
{
	// cmd 상의 명령어를 사용
	int re;
	re = system("notepad");
	printf("메모장이 열렸습니다.: %d\n", re);
	re = system("calc");
	printf("계산기이 열렸습니다.: %d\n", re);
	re = system("sysdm.cpl");
	printf("시스템 속성이 열렸습니다.: %d\n", re);

	re = system("date");
	printf("시스템 속성이 열렸습니다.: %d\n", re);

	char cmd[30];
	strcpy(cmd, "dir");
	system(cmd);

	strcpy(cmd, "date");
	system(cmd);

	
}