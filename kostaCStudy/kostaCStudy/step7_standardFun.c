#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define banollim(x, dig) (floor((x)*pow(10.0, dig)+0.5)/pow(10.0, dig))
#include <stdlib.h>

void floorFunction()
{
	// floor ���� ceil �ø� 
	printf("floor(3.14) = %.2f\n", floor(3.14));
	printf("ceil(3.14) = %.2f\n", ceil(3.14));
	printf("floor(-3.14) = %.2f\n", floor(-3.14));
	printf("ceil(-3.14) = %.2f\n", ceil(-3.14));
}

void castInt()
{
	// cast �����ڴ� �Ҽ��θ� ������ �ڸ���.
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
		printf("%f�� %d�ڸ� �ݿø� = %f \n", x, i, banollim(x, i));
	}
}

void absrange()
{
	int input;
	printf("10~50 ������ ���ڸ� �Է��ϼ���. : ");
	scanf_s("%d", &input);
	if (abs(input -30) <= 20)
	{
		puts("�������� �����Դϴ�.");
	}
	else {
		puts("������ ������ϴ�.");
	}
}

void sinCal()
{
	int angle;
	for (int angle = 0; angle <= 90; angle+15)
	{
		printf("sin(%d��) = %f\n", angle, sin(angle * 3.14 / 180));
	}
}


void whatIsExit() 
{
	// �����ϴ� �������� 0 , ������ ���� 1 
	int input;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d",&input);
	exit(0);
	// �Ʒ��� ��� �κ��� ������� �ʰ� �Լ��� ���� �˴ϴ�.
	printf("exit()�Լ��� ����Ǿ����ϴ�.");
	return 0;
}

void whatIsAbort()
{
	// �ߴ��ϴ�
	int a = 15;
	printf("The value of a : %d\n", a);
	abort();
	printf("Calling of abort()");
}

void whatIsSystem()
{
	// cmd ���� ��ɾ ���
	int re;
	re = system("notepad");
	printf("�޸����� ���Ƚ��ϴ�.: %d\n", re);
	re = system("calc");
	printf("������ ���Ƚ��ϴ�.: %d\n", re);
	re = system("sysdm.cpl");
	printf("�ý��� �Ӽ��� ���Ƚ��ϴ�.: %d\n", re);

	re = system("date");
	printf("�ý��� �Ӽ��� ���Ƚ��ϴ�.: %d\n", re);

	char cmd[30];
	strcpy(cmd, "dir");
	system(cmd);

	strcpy(cmd, "date");
	system(cmd);

	
}