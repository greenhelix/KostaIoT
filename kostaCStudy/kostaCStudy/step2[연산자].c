#include <stdio.h>

// 연산자
void whatIsOperator() {
	printf("sizeof \n (type) : cast convert 용으로 사용 \n new delete ::, * ->* 메모리 할당에 유용한 연산자 c++이다 \n 증감/ 관계 / 논리 / 비트 / 산술 / 부호 / 등이 많이 사용된다. // 사용하면서 익숙해지는 것이 좋다. ");

}

void whatIsArithmatic() {
	printf("3+2 = %d\n", 3 + 2);
	printf("3-2 = %d\n", 3 - 2);
	printf("3*2 = %d\n", 3 * 2);
	printf("3%2 = %d\n", 3 % 2);
}

void whatIsModular() {
	int value = 386;

	int h = value / 100;
	int d = value / 10 % 10;
	int n = value % 10;

	printf("%d백%d십%d\n", h, d, n);
}

void whatIsPrepost() {
	int a, b;

	a = 3;
	b = ++a;
	printf("전위형으로 썼을 때 : %d\n", b);

	a = 3;
	b = a++;
	printf("후위형으로 썼을 때 : %d\n", b);
}

// 우선순위
void whatIsPriority() {
	int a = 5;
	a = a * 2 + 1;
	printf("a = %d\n", a);

	a = 5;
	a *= 2 + 1;
	printf("a = %d\n", a);
}

// 산술변환
void whatIsConvert() {
	int a = 3;
	double d = 2.41;
	int b = a + d;
	printf("b = %d\n", b);

	short aa = 20000;
	short bb = 30000;
	int c = a + b;
	printf("c = %d\n", c);
}

// 캐스트 연산자
void whatIsCast() {
	int sum = 427;
	int num = 5;

	printf("평균 = %d\n", sum / num);
	printf("Double로 형변환 한 평균 = %f\n", sum / (double)num);

	// int to char 
	int integer = 100;
	int charecter = 100;
	int change = (char)charecter;
	printf("정수형은 문자로 형변환이 될까? \n %d --> %d", integer, (char)charecter);
	printf("cast %d", change);
}