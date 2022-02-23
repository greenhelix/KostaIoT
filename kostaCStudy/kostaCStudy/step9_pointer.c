#include <stdio.h>
#include <malloc.h>
#include <string.h>


 //포인터의 연산 
 //뺄셈 가능(포인터끼리 결과는 정수) /  포인터에 정수더하기는 가능 / 
 //실수와 연산할 수 없다. 
 //대입 및 비교 가능 하다. 
 //전치 후치 연산이 가능하다. ++ 
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


// void 형 포인터 
// 대상체를 읽는 기능은 빼고 순수하게 위치만 가리킨다.
void voidPointer()
{
	int ar[] = { 1, 2, 3 };
	void* vp = ar;
	vp = (int*)vp + 1;
	printf("%d\n", *(int*)vp);
}

// malloc 메모리 할당 memory allocation
// calloc 연속 메모리 할당 
// realloc 다시 메모리 할당 
// free 메모리 할당 해제



