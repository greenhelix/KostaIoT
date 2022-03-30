#include <stdio.h>
#include <malloc.h>
#include <string.h>


// ������ �迭 
void DumpArray(void* array, int length)
{
	for (int i = 0; i < length; i++) {
		printf("%02X ", *((unsigned char*)array + i));
	}
	printf("\n");
}

void ArrayOfArray()
{
	char ar[3][4] = {
		{ 1, 2, 3, 4},
		{ 5, 6, 7, 8},
		{ 9, 10, 11, 12},
	};

	DumpArray(ar, sizeof(ar));
	DumpArray(ar[0], sizeof(ar[0]));
	DumpArray(ar[1], sizeof(ar[1]));
}

// �迭�� ���̴� �������� ����, �������� ���̴� �������� ���� �ȴ�.
void ArrayDefine()
{
	//int len = 32;
	//char name[len]; // �����Ϸ� ���� C2133 : �� �� ���� ũ��
	char* country[] = { "����", "�ѱ�", "����Ʈ���ϸ���", "��ũ���̳�", "���þ�", "�̱�" };
	int size = sizeof(country) / sizeof(char);
	printf("size: %d\n", size);

	for (int i = 0; i < 6; i++)
	{
		printf("%s ", country[i]);
	}
}

// �迭�� ��Ҹ� ���� ���� [] �����ڷ� ÷�� ������ �ȴ�.
// �������� �ڽ��� ���� �̵��ϸ� ���ü�� ���� �� �־� �ӵ��� ������.

