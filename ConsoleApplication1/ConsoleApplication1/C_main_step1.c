#include <stdio.h>
#include "step1.h"

// �̷��� ��� �ø��� �������� ������Ƿ� �̷��� �Լ����� ���Ϸ� �������ص�
// ������Ϸ� ������ش�. 
// include�� ���ؼ� �����´�. 
void variable() {
	whatIsVariable();

	whatIsEnum();

	struct {
		char title[10];
		char singer[10];
		double length;
		int size;
	} song; // struct ������ - �ٸ� Ÿ���� ���� ����


	int arScore[10]; // array �迭�� -  ���� Ÿ���� ���� ����
	int sum = 0; //for (int i = 0; i < 10; i++) sum += arScore[i];

	whatIsPointer();

	whatIsTypeDef(); // ����� ������

	whatIsDefine(); // ������ Boolean true = 1, false = 0 

	whatIsScanf(); // ��ĳ��

	whatIsCursor(); // Ŀ��
}

int main()
{
	
	//variable();

	// ������
	//whatIsArithmatic(); //���������
	//whatIsModular(); // ������������
	//whatIsPrepost(); // 
	//whatIsPriority();
	//whatIsConvert();
	whatIsCast();
}


