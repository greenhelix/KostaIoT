#include <stdio.h>
#include <malloc.h>
#include <string.h>


// 포인터의 참조 호출
void InputName(char** pName)
{
    *pName = (char*)malloc(32);
    strcpy(*pName, "kim sang hyung");
}

void PointerExample1()
{
    int a, * b, ** c;
    b = &a;  // b에 a의 주소값을 할당
    c = &b;  // c에 b의 주소값을 할당
    scanf_s("%d", &a);  // a의 값을 입력 받음
    for (int i = 1; i <= *b; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", *b * **c);
        }
        printf("\n");
    }
}




void test()
{
    int var = 789;

    // pointer for var
    int* ptr2;

    // double pointer for ptr2
    int** ptr1;

    // storing address of var in ptr2
    ptr2 = &var;

    // Storing address of ptr2 in ptr1
    ptr1 = &ptr2;

    // Displaying value of var using
    // both single and double pointers
    printf("초기 값 = %d\n", var);
    printf("단일 포인터 사용한 값 = %d\n", *ptr2);
    printf("단일 포인터 사용한 주소 = %p\n", &ptr2);

    printf("이중 포인터 사용한 주소 = %p\n", *ptr1);
    printf("이중 포인터 사용한 주소 = %p\n", &ptr1);
    printf("이중 포인터 사용한 값 = %d\n", *(*ptr1));
    printf("이중 포인터 사용한 값 = %d\n", **ptr1);
    puts("");
}

// 동적 문자열 배열
void dynamicString()
{
   /* int len1 = 32;
    char name[len1];  // 컴파일러 오류 C2133 : 알 수 없는 크기
    */
    puts("---------동적 문자열 배열------------");

    int len2 = 32;
    char* names = (char*)malloc(len2 * sizeof(char));

    printf("names의 크기 : %zd ", sizeof(names));
    free(names);
    puts("");
}

int dynamicString2()
{
    int len = 10, num = 5, i;
    char** name;

    name = (char**)malloc(num * sizeof(char*));
    for (i = 0; i < num; i++) {
        name[i] = (char*)malloc(len * sizeof(char));
    }

    for (i = 0; i < num; i++) {
        sprintf(name[i], "string %d", i);
        puts(name[i]);
    }

    for (i = 0; i < num; i++) {
        free(name[i]);
    }
    free(name);

    return 0;
}

int calcarg(int argc, char** argv)
{
    int a, b, c;
    char op;

    if (argc != 4) {
        printf("계산식을 정확하게 입력해 주십시오.");
        exit(0);
    }

    a = atoi(argv[1]);
    b = atoi(argv[3]);
    op = argv[2][0];

    switch (op) {
    case '+':
        c = a + b;
        break;
    case '-':
        c = a - b;
        break;
    case '*':
        c = a * b;
        break;
    case '/':
        c = a / b;
        break;
    default:
        printf("사칙 연산만 할 수 있습니다.\n");
        exit(0);
    }

    printf("계산 결과 = %d", c);
}
