#include <stdio.h>
#include <conio.h>
#include <cursor.h>
#pragma warning(disable:4996)

// �ݺ��� 
void sum100()
{
	/*int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += i;
	}
	printf("1~100�� �� = %d\n", sum);
	*/

	// �������� 
	// sum = (n(a1+aN))/2
	long double sum2 = 0; 
	sum2 = (1 + (4000000000 + 1)) / 2;

	printf("1~4000000000�� �� = %p\n", sum2);
}

// # �ڵ� �����̱�
void sharpAni()
{
	clrscr();
	for (int i = 1; i < 30; i++)
	{
		// �̵��ϴ� ��ó�� ���̰� �ϴ� �����̴�.
		// #�� ������ٰ� �������� �ߴٸ� �ݺ��ϴ� ����.
		gotoxy(i, 10); putch('#');
		gotoxy(i-1, 10); putch(' ');
		delay(100); // 0.1�ʿ� �ѹ� �����Ÿ��� �̵��Ѵ�.   
	} // �� 100 * 30 : 3�� ���� ���� �ȴ�. 
}

// ���� ���� �ǽ� 
void makeTriangle()
{
	// rect 
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			printf("*");
		}
		puts("");
	}

	puts("---------------------------");

	// triangle -
	/*
	*
	**
	***
	****
	*****
	******
	*******
	********
	*********
	**********
	***********
	*/
	
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <=  i; j++)
		{
			printf("*");
		}
		puts("");
	}

	puts("---------------------------");
	/*
	***********
	**********
	*********
	********
	*******
	******
	*****
	****
	***
	**
	*
	*/
	for (int i = 10; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		puts("");
	}

	puts("---------------------------");
	/*
		       *
			  **
			 ***
			****
		   *****
		  ******
		 *******
		********
	   *********
	  **********
	 ***********
	*/
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10-i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		puts("");
		
	}

	puts("---------------------------");

	for (int a = 0; a <= 10; a++) {
		for (int b = 0; b <= 10; b++)
		{
			printf(" ");
		}

	}

	puts("---------------------------");

	for (int i = 0; i < 70; i++)
	{
		if (i % 10 == 0)
		{
			putch('|');
		}
		else {
			putch('-');
		}
	}

	puts("---------------------------");

	//for (int i = 0; i <= 75; i++)
	//{
	//	// 10 : �ؿ��� 10��° 
	//	gotoxy(i, 10);
	//	if (i%2 == 0)
	//	{
	//		puts(" __@");
	//	}
	//	else {
	//		puts(" ^^@");
	//	}
	//	delay(200);
	//}

	//puts("---------------------------");

	/*for (int i = 10; i >= 0; i++)
	{
		for (int i = 0; i < length; i++)
		{
			puts("*");
		}
		
	}*/

}

void makeDiamond()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40 - y; x++)
		{
			printf(" ");
		}

		for (int k = 0; k <= y*2; k++)
		{
			printf("*");
		}
		puts("");
	}
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < y; x++)
		{
			printf(" ");
		}
		for (int k = 0; k < 2*(40-y)-1; k++) {
			printf("*");
		}
		puts("");
	}

}


// ��ǥ ������
void commaOperator()
{
	int a, b; 
	b = (a = 2, a + 3);
	printf("a = %d, b = %d\n", a, b);
}

void whatIsWhile()
{
	int battery = 34; 
	while (battery < 100) {
		battery += 1; 
		printf(".");
		delay(30);
	}
	printf("\n���͸� %d%% ���� �Ϸ�\n", battery);

	int sum = 0;
	int i = 1;
	while (i <= 100) {
		sum += i;
		i++;
	}
	printf("1~100������ �� = %d\n", sum);
}

void randNum()
{
	int num; 
	int input;

	randomize();
	for (;;) {
		num = random(100) + 1; 
		puts("���� ���� ���ڸ� ���� ������.");
		do {
			printf("���ڸ� �Է��ϼ���(���� ���� 999) : ");
			scanf_s("%d", &input);

			if (input == 999) {
				exit(0);
			}

			if (input == num) {
				puts("������ϴ�. \n");
			}
			else if (input > num) {
				puts("�Է��� ���ں��� �� �۽��ϴ�.");
			}
			else {
				puts("�Է��� ���ں��� �� Ů�ϴ�.");
			}
		} while (input != num);
	}
}

