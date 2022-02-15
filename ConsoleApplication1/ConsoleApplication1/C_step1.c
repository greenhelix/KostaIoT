#include <stdio.h>
void whatIsVariable()
{
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
	enum origin { EAST, WEST, SOUTH, NORTH };
	enum origin mark = WEST;
	enum origin head = SOUTH;
	static char* oriname[] = { "동", "서", "남", "북" };

	printf("%d에서 %d로 이동합니다. \n이 말은 ", mark, head);
	printf("%s쪽에서 %s쪽으로 이동한다는 말입니다.\n", oriname[mark], oriname[head]);
}

void whatIsPointer() {

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