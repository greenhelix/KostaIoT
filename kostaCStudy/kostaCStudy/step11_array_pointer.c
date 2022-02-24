#include <stdio.h>
#include <malloc.h>
#include <string.h>


// 다차원 배열 
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

// 배열의 길이는 정적으로 결정, 포인터의 길이는 동적으로 결정 된다.
void ArrayDefine()
{
	//int len = 32;
	//char name[len]; // 컴파일러 오류 C2133 : 알 수 없는 크기
	char* country[] = { "영국", "한국", "오스트레일리아", "우크라이나", "러시아", "미국" };
	int size = sizeof(country) / sizeof(char);
	printf("size: %d\n", size);

	for (int i = 0; i < 6; i++)
	{
		printf("%s ", country[i]);
	}
}

// 배열의 요소를 읽을 때는 [] 연산자로 첨자 연산이 된다.
// 포인터의 자신이 직접 이동하며 대상체를 읽을 수 있어 속도가 빠르다.

