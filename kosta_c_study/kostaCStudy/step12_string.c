#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void stringLiteral()
{
	char Name[] = "Kim Ik Hwan";
	printf("This is a String Constant.\n");
	puts(Name);
}

void ArrayAndString()
{
	char str[] = "Smart";
	char* pointer = "Smart";

	puts(str);
	puts(pointer);

	puts(str[4]);
	
}


void StringCopy()
{
	char str1[10] = "abcdefghi";
	char str2[10] = "123456789";
	strcpy(str2, str1);
	puts(str2);  // OUTPUT : abcdefghi
}
void StringNumCopy()
{
	char str1[10] = "abcdefghi";
	char str2[10] = "123456789";
	strncpy(str2, str1, 3);
	puts(str2); // OUTPUT : abc456789

	char str3[10] = "abcdefghi";
	char str4[10] = "123456789";
	//strncpy(str4 + 2, str3 + 3, 3);
	puts(str4); // OUTPUT : 12def6789
}

void StringLength()
{
	char str1[32] = "korea";
	char str2[32] = "대한민국";
	char str3[32] = "대";

	printf("str1 길이 = %d\n", strlen(str1));
	printf("str2 길이 = %d\n", strlen(str2));
	printf("str2 길이 = %d\n", (int)strlen(str3));
	printf("str2 배열 길이 = %d\n", (int)sizeof(str2));
}


void SprintfFun()
{
	char str[128];
	int value = 62;
	char ch = 'K';

	sprintf(str, "정수는 %d이고 문자는 %c이다.", value, ch);

	// 출력 
	puts(str);
}

// memcpy()는 메모리 블록을 한 위치에서 다른 위치로 복사하는 데 사용됩니다.
void mamoryMange()
{
	char str1[] = "Geeks";
	char str2[] = "Quiz";

	puts("str1 before memcpy ");
	puts(str1);

	/* Copies contents of str2 to str1 */
	memcpy(str1, str2, sizeof(str2));

	puts("\nstr1 after memcpy ");
	puts(str1);
}