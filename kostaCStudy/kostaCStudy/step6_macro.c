// ��ó���� 
#include <stdio.h>
#define INCH 2.54

void inch() 
{
	int size1 = 42;
	int size2 = 30;
	printf("%d��ġ ������� ũ�� : %.0fcm\n", size1, size1 * INCH);
	printf("%d��ġ ������� ũ�� : %.0fcm\n", size1, size1 * INCH);
}

#define DUBAE(a) a+a
#define JEGOP(a) (a*a)
#include <cursor.h>
#define putsxy(x, y, s) {gotoxy(x,y); puts(s);}

void macroFunction()
{
	printf("%d\n", DUBAE(3));
	printf("%d\n", JEGOP(3));
	int a = 3;
	printf("%d\n", JEGOP(a++));
}

void drawBox()
{
	for (int i = 0; i < 15; i++) putch('-');
	puts("");
	printf("|�ȳ��ϼ���. |\n");
	for (int i = 0; i < 15; i++) putch('-');
	puts("");
	
	for (int i = 0; i < 25; i++) putch('-');
	puts("");
	printf("| ��ſ� �Ϸ� ��������. |\n");
	for (int i = 0; i < 25; i++) putch('-');
	puts("");
}

void OutBoxMessage(char *str)
{
	int len = strlen(str);
	for (int i = 0; i < len + 4; i++) {
		putch('-');
	}
	puts("");
	printf("| %s |\n", str);

	for (int i = 0; i < len+4; i++)
	{
		putch('-');
	}
	puts("");
}

void putchs(int ch, int n)
{
	for (int i = 0; i < n; i++)
	{
		putch(ch);
	}
	puts("");
}

void OutBoxMessgae1(char *str)
{
	int len = strlen(str);
	putchs('-', len + 4);
	printf("| %s |\n", str);
	putchs('-', len + 4);
}

