#include <stdio.h>

// ������
void whatIsOperator() {
	printf("sizeof \n (type) : cast convert ������ ��� \n new delete ::, * ->* �޸� �Ҵ翡 ������ ������ c++�̴� \n ����/ ���� / �� / ��Ʈ / ��� / ��ȣ / ���� ���� ���ȴ�. // ����ϸ鼭 �ͼ������� ���� ����. ");

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

	printf("%d��%d��%d\n", h, d, n);
}

void whatIsPrepost() {
	int a, b;

	a = 3;
	b = ++a;
	printf("���������� ���� �� : %d\n", b);

	a = 3;
	b = a++;
	printf("���������� ���� �� : %d\n", b);
}

// �켱����
void whatIsPriority() {
	int a = 5;
	a = a * 2 + 1;
	printf("a = %d\n", a);

	a = 5;
	a *= 2 + 1;
	printf("a = %d\n", a);
}

// �����ȯ
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

// ĳ��Ʈ ������
void whatIsCast() {
	int sum = 427;
	int num = 5;

	printf("��� = %d\n", sum / num);
	printf("Double�� ����ȯ �� ��� = %f\n", sum / (double)num);

	// int to char 
	int integer = 100;
	int charecter = 100;
	int change = (char)charecter;
	printf("�������� ���ڷ� ����ȯ�� �ɱ�? \n %d --> %d", integer, (char)charecter);
	printf("cast %d", change);
}