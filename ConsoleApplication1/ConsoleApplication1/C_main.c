#include <stdio.h>
#include "c���⺻���.h"
// �̷��� ��� �ø��� �������� ������Ƿ� �̷��� �Լ����� ���Ϸ� �������ص�
// ������Ϸ� ������ش�. 
// include�� ���ؼ� �����´�. 

int main()
{
	// �⺻ ��������� ����
	whatIsVariable();

	// ������ enum  ������ ������ ���� ������ Ÿ�� 
	// enum{���, ���,...} ������;  ��) enum{EAST, WEST, SOUTH, NORTH} mark;
	// enum{MAN = 1, WOMAN = 2, GIRL = 2} human; �̷��� ���� �ߺ��� �����ϴ�.������ ������ �ν�
	whatIsEnum();

	// struct ���� �ٸ� �������� ��Ƶ� �� �ִ�. 
	struct {
		char title[10];
		char singer[10];
		double length;
		int size;
	} song;

	// pointer �����͸� �����Ͽ� ���������� ���� �����Ѵ�.
	whatIsPointer();

	// ����� ������
	whatIsTypeDef();

	// ������ Boolean true = 1, false = 0 
	whatIsDefine();
}
