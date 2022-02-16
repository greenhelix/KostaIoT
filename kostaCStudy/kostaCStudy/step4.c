#include <stdio.h>
#include <conio.h>
#include <cursor.h>
#pragma warning(disable:4996)

// 반복문 
void sum100()
{
	/*int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		sum += i;
	}
	printf("1~100의 합 = %d\n", sum);
	*/

	// 등차수열 
	// sum = (n(a1+aN))/2
	long double sum2 = 0; 
	sum2 = (1 + (4000000000 + 1)) / 2;

	printf("1~4000000000의 합 = %p\n", sum2);
}

// # 자동 움직이기
void sharpAni()
{
	clrscr();
	for (int i = 1; i < 30; i++)
	{
		// 이동하는 것처럼 보이게 하는 원리이다.
		// #을 보여줬다가 없어지게 했다를 반복하는 것임.
		gotoxy(i, 10); putch('#');
		gotoxy(i-1, 10); putch(' ');
		delay(100); // 0.1초에 한번 깜빡거리며 이동한다.   
	} // 총 100 * 30 : 3초 정도 지속 된다. 
}

// 이중 루프 실습 
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
	//	// 10 : 밑에서 10번째 
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


// 쉼표 연산자
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
	printf("\n배터리 %d%% 충전 완료\n", battery);

	int sum = 0;
	int i = 1;
	while (i <= 100) {
		sum += i;
		i++;
	}
	printf("1~100까지의 합 = %d\n", sum);
}

void randNum()
{
	int num; 
	int input;

	randomize();
	for (;;) {
		num = random(100) + 1; 
		puts("제가 만든 숫자를 맞춰 보세요.");
		do {
			printf("숫자를 입력하세요(끝날 때는 999) : ");
			scanf_s("%d", &input);

			if (input == 999) {
				exit(0);
			}

			if (input == num) {
				puts("맞췄습니다. \n");
			}
			else if (input > num) {
				puts("입력한 숫자보다 더 작습니다.");
			}
			else {
				puts("입력한 숫자보다 더 큽니다.");
			}
		} while (input != num);
	}
}

