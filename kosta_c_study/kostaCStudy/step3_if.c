#include <stdio.h>
#include <conio.h>
#include <cursor.h>
#pragma warning(disable:4996)

// ���ǹ�
void whatIsIf()
{
	int input;

	printf("2 + 3�� �Է��ϼ��� : ");
	scanf_s("%d", &input);
	if (input == 5)
		puts("�����Դϴ�.");

	int input2;

	printf("2 + 8�� �Է��ϼ��� : ");
	scanf_s("%d", &input2);
	if (input2 == 10) {
		puts("�����Դϴ�.");
		puts("�����մϴ�.");
	}

	int input3;

	printf("2 + 3�� �Է��ϼ��� : ");
	scanf_s("%d", &input3);
	if (input3 == 5)
		puts("�����Դϴ�.");
	else if (input3 == 6)
		puts("������ �ƴϰ� �����Դϴ�.");
	else
		puts("Ʋ�Ƚ��ϴ�.");
}

// �񱳿���
void whatIsComparison()
{
	int attend = 85;
	int point;

	// (attend > 50)�� ���϶� 1�� �ǰ� �����̸� 0�̵Ǽ� ��������.
	point = attend / 10 + (attend > 50);
	printf("point = %d\n", point);
}

// �� ���� ����
void whatIsLogical()
{
	// AND
	int blood;
	printf("���� ������ ���Դϱ�?");
	scanf_s("%d", &blood);

	if (blood >= 70 && blood <= 80) {
		puts("���� �����Դϴ�.");
	}
	else {
		puts("���� ������ �ʿ��մϴ�.");
	}

	// ���� ���ϱ� leap year
	int year;

	printf("���� �⵵�� �Է��Ͻÿ�.");
	scanf_s("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		puts("�����Դϴ�.");
	}
	else {
		puts("������ �ƴմϴ�.");
	}
}

// ���� ���� ����
void whatIsTernary()
{
	int kim = 182, lee = 174, tall;
	tall = kim > lee ? kim : lee;
	printf("ū ��� = %d\n", tall);

	int age;
	printf("���̸� �Է��ϼ���: ");
	scanf_s("%d", &age);
	printf("%s\n", age > 19 ? "�� ����� �����̴�." : "�� ����� ������ �ƴϴ�.");
	printf("�� ����� ������%s��. \n ", age > 19 ? "" : " �ƴ�");

	int num;
	printf("���ڸ� �Է��ϼ���: ");
	scanf_s("%d", &num);
	printf("%d�� %s���Դϴ�.\n", num, num % 2 == 0 ? "¦" : "Ȧ");

}

void whatIsSwitch()
{
	int num;

	printf("������ �Է��ϼ���: ");
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

	/* break �����ϱ�
	break�� �����ϸ� �ΰ� �̻��� case�� ���̾� ���డ���ϴ�. */

	// fall
	printf("���� ����� ���ðڽ��ϱ�? (Y/N) ");
	int ch = getch();
	puts("");

	switch (ch) {
	case 'y':
	case 'Y':
		puts("���ش� ��������� �� �Դϴ�. å�� ������ �а�...");
		break;
	case 'n':
	case 'N':
		puts("�׷� �׷�, �� ���� �� ���� �� �ϰڴ�!");
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