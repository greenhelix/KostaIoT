﻿#include <stdio.h>
#include "cursor.h"

void whatIsVariable()
{
	// 기본 변수명들의 사용법
	int a = 1;
	int b = 16;
	double c = 32;
	int d = 64;
	char e = 'a';
	char ar[6] = "korea";

	printf("%.1lf\n", 1e6);	    // 지수 형태의 실수를 소수
	printf("%.7lf\n", 3.14e-5);   // 소수점 이하 7자리까지      
	printf("%le\n", 0.0000314);   // 소수점 형태의 실수를 지수까지
	printf("%.2le\n", 0.0000314); // 지수 형태로 소수점 이하
}

void whatIsEnum() {
	// 열거형 enum  일정한 범위의 값만 가능한 타입 
	// enum{멤버, 멤버,...} 변수명;  예) enum{EAST, WEST, SOUTH, NORTH} mark;
	// enum{MAN = 1, WOMAN = 2, GIRL = 2} human; 이렇게 값이 중복은 가능하다.동일한 것으로 인식
	enum origin { EAST, WEST, SOUTH, NORTH };
	enum origin mark = WEST;
	enum origin head = SOUTH;
	static char* oriname[] = { "동", "서", "남", "북" };

	printf("%d에서 %d로 이동합니다. \n이 말은 ", mark, head);
	printf("%s쪽에서 %s쪽으로 이동한다는 말입니다.\n", oriname[mark], oriname[head]);
}

void whatIsPointer() {
	// 변수의 번지를 가리킨다.
	// 변수 선언시 컴파일러가 메모리를 할당해 준다. 
	// & : 변수가 저장된 번지를 구한다.
	// * : 포인터가 가리키는 번지의 값을 읽는다.

	// 포인터를 경유하여 간접적으로 값을 액세스한다.

	int value = 38;
	int *pi;
	pi = &value;

	printf("value의 값은 %d입니다.\n", *pi);

	int value1 = 38, value2;
	int* pii;
	pii = &value1;
	value2 = *pii;

	printf("value1 = %d, value2 = %d \n", value1, value2);


}

void whatIsTypeDef() {
	typedef int jungsoo;
	typedef int* pint;
	typedef enum { EAST, WEST, SOUTH, NORTH } direction;
	typedef int arint[10];
}

// 참 또는 거짓 둘 중의 하나의 값을 기억한다.
// C는 별도의 진위형이 없어 정수를 사용한다.
void whatIsDefine() {
	typedef int BOOL;
	#define TRUE 1 
	#define FALSE 0
}

void whatIsPrintf() {
	// %d, %i   decimal integer 정수형 
	int value = 11;
	char ch = 'D';
	printf("정수는 %d이고 문자는 %c입니다.", value, ch);

	// widthalign
	int value2 = 123;

	printf("###%d###\n", value2);
	printf("###%5d###\n", value2);
	printf("###%05d###\n", value2);
	printf("###%-5d###\n", value2);

}

void whatIsScanf() {
	int age;
	float height;
	char name[32];

	// scanf가 사용이 안된다. overflow발생한다고 한다. 
	// scanf_s를 사용하면 된다.  https://programmerjoon.tistory.com/4

	printf("나이를 입력하세요 : ");
	scanf_s("%d", &age);
	printf("키를 입력하세요 : ");
	scanf_s("%f", &height);
	printf("이름을 입력하세요 : ");
	scanf_s("%s", name, 32);
	printf("안녕하세요. %d살, 키 %.2fcm의 %s님\n", age, height, name);
}

// 콘솔 화면에서 코드의 명령을 통해 커서의 위치까지 변경할 수 있다.
void whatIsCursor() {
	printf("3초 후에 화면을 지웁니다.\n");
	delay(3000);
	clrscr();
	gotoxy(20, 10);
	//COORD Cur = { 20, 10 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	printf("화면 중앙에 문자열을 출력합니다.\n");
}