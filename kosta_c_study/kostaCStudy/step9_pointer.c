#include <stdio.h>
#include <malloc.h>
#include <string.h>


 //�������� ���� 
 //���� ����(�����ͳ��� ����� ����) /  �����Ϳ� �������ϱ�� ���� / 
 //�Ǽ��� ������ �� ����. 
 //���� �� �� ���� �ϴ�. 
 //��ġ ��ġ ������ �����ϴ�. ++ 
int pointerMinus()
{
	int ar[] = { 10, 20, 30, 40, 50 };
	int* ptr = &ar[4];

	for (int i = 0; i < 5; i++){
		printf("%d ", *ptr--);
	}
	puts("");

}
// 50 40 30 20 10

int pointerPlus()
{
	int ar[] = { 10, 20, 30, 40, 50 };
	int* ptr = ar;

	for (int i = 0; i < 5; i++) {
		printf("%d ", *ptr++);
	}
	puts("");
}
// 10 20 30 40 50


// void �� ������ 
// ���ü�� �д� ����� ���� �����ϰ� ��ġ�� ����Ų��.
void voidPointer()
{
	int ar[] = { 1, 2, 3 };
	void* vp = ar;
	vp = (int*)vp + 1;
	printf("%d\n", *(int*)vp);
}

// malloc �޸� �Ҵ� memory allocation
// calloc ���� �޸� �Ҵ� 
// realloc �ٽ� �޸� �Ҵ� 
// free �޸� �Ҵ� ����



