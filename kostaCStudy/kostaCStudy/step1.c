#include <stdio.h>
#include "cursor.h"

void whatIsVariable()
{
	// �⺻ ��������� ����
	int a = 1;
	int b = 16;
	double c = 32;
	void whatIsVariable();
}

void whatIsEnum() {
	// ������ enum  ������ ������ ���� ������ Ÿ�� 
	// enum{���, ���,...} ������;  ��) enum{EAST, WEST, SOUTH, NORTH} mark;
	// enum{MAN = 1, WOMAN = 2, GIRL = 2} human; �̷��� ���� �ߺ��� �����ϴ�.������ ������ �ν�
	enum origin { EAST, WEST, SOUTH, NORTH };
	enum origin mark = WEST;
	enum origin head = SOUTH;
}
void whatIsPointer() {
	// ������ ������ ����Ų��.
	// ���� ����� �����Ϸ��� �޸𸮸� �Ҵ��� �ش�. 
	// & : ������ ����� ������ ���Ѵ�.
	// * : �����Ͱ� ����Ű�� ������ ���� �д´�.

	// �����͸� �����Ͽ� ���������� ���� �׼����Ѵ�.

	int value = 38;
	int* pi;
}
void whatIsScanf() {
	float height;
	char name[32];

	// scanf�� ����� �ȵȴ�. overflow�߻��Ѵٰ� �Ѵ�. 
	// scanf_s�� ����ϸ� �ȴ�.  https://programmerjoon.tistory.com/4
	int age;
	printf("���̸� �Է��ϼ��� : ");
	scanf_s("%d", &age);
	printf("Ű�� �Է��ϼ��� : ");
	scanf_s("%f", &height);
	printf("�̸��� �Է��ϼ��� : ");
	scanf_s("%s", name, 32);
	printf("�ȳ��ϼ���. %d��, Ű %.2fcm�� %s��\n", age, height, name);
}

// �ܼ� ȭ�鿡�� �ڵ��� ����� ���� Ŀ���� ��ġ���� ������ �� �ִ�.
void whatIsCursor() {
	printf("3�� �Ŀ� ȭ���� ����ϴ�.\n");
	delay(3000);
	clrscr();
	gotoxy(20, 10);
	//COORD Cur = { 20, 10 };
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	printf("ȭ�� �߾ӿ� ���ڿ��� ����մϴ�.\n");
}