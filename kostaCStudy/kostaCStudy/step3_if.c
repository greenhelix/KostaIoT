#include <stdio.h>
#include <conio.h>
#include <cursor.h>
#pragma warning(disable:4996)

// 조건문
void whatIsIf()
{
	int input;

	printf("2 + 3을 입력하세요 : ");
	scanf_s("%d", &input);
	if (input == 5)
		puts("정답입니다.");

	int input2;

	printf("2 + 8을 입력하세요 : ");
	scanf_s("%d", &input2);
	if (input2 == 10) {
		puts("정답입니다.");
		puts("축하합니다.");
	}

	int input3;

	printf("2 + 3을 입력하세요 : ");
	scanf_s("%d", &input3);
	if (input3 == 5)
		puts("정답입니다.");
	else if (input3 == 6)
		puts("곱셈이 아니고 덧셈입니다.");
	else
		puts("틀렸습니다.");
}

// 비교연산
void whatIsComparison()
{
	int attend = 85;
	int point;

	// (attend > 50)이 참일때 1이 되고 거짓이면 0이되서 더해진다.
	point = attend / 10 + (attend > 50);
	printf("point = %d\n", point);
}

// 논리 조건 연산
void whatIsLogical()
{
	// AND
	int blood;
	printf("현재 혈당은 얼마입니까?");
	scanf_s("%d", &blood);

	if (blood >= 70 && blood <= 80) {
		puts("정상 혈당입니다.");
	}
	else {
		puts("혈당 관리가 필요합니다.");
	}

	// 윤년 구하기 leap year
	int year;

	printf("현재 년도를 입력하시오.");
	scanf_s("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		puts("윤년입니다.");
	}
	else {
		puts("윤년이 아닙니다.");
	}
}

// 삼항 조건 연산
void whatIsTernary()
{
	int kim = 182, lee = 174, tall;
	tall = kim > lee ? kim : lee;
	printf("큰 사람 = %d\n", tall);

	int age;
	printf("나이를 입력하세요: ");
	scanf_s("%d", &age);
	printf("%s\n", age > 19 ? "이 사람은 성인이다." : "이 사람은 성인이 아니다.");
	printf("이 사람은 성인이%s다. \n ", age > 19 ? "" : " 아니");

	int num;
	printf("숫자를 입력하세요: ");
	scanf_s("%d", &num);
	printf("%d는 %s수입니다.\n", num, num % 2 == 0 ? "짝" : "홀");

}

void whatIsSwitch()
{
	int num;

	printf("정수를 입력하세요: ");
	scanf_s("%d", &num);

	switch (num) {
	case 1:
		puts("one");
		break;
	case 2:
		puts("two");
		break;
	case 3:
		puts("three");
		break;
	default:
		puts("others");
		break;
	}

	/* break 생략하기
	break를 생략하면 두개 이상의 case를 연이어 실행가능하다. */

	// fall
	printf("토정 비결을 보시겠습니까? (Y/N) ");
	int ch = getch();
	puts("");

	switch (ch) {
	case 'y':
	case 'Y':
		puts("올해는 운수대통할 수 입니다. 책을 열심히 읽고...");
		break;
	case 'n':
	case 'N':
		puts("그려 그려, 점 같은 거 봐서 뭐 하겠니!");
		break;
	}
}

void movesharp()
{
	int x = 40, y = 10;
	int ch;

	clrscr();

	for (;;) {
		gotoxy(x, y);
		putch('#');
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case 75:
				x--;
				break;
			case 77:
				x++;
				break;
			case 72:
				y--;
				break;
			case 80:
				y++;
				break;
			}
		}
		else {
			switch (ch) {
			case ' ':
				clrscr();
				break;
			case 'q':
			case 'Q':
				exit(0);
			}
		}
	}
}