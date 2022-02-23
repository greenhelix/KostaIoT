#include <stdio.h>
#include <malloc.h>
#include <string.h>


// �������� ���� ȣ��
void InputName(char** pName)
{
    *pName = (char*)malloc(32);
    strcpy(*pName, "kim sang hyung");
}

void PointerExample1()
{
    int a, * b, ** c;
    b = &a;  // b�� a�� �ּҰ��� �Ҵ�
    c = &b;  // c�� b�� �ּҰ��� �Ҵ�
    scanf_s("%d", &a);  // a�� ���� �Է� ����
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
    printf("�ʱ� �� = %d\n", var);
    printf("���� ������ ����� �� = %d\n", *ptr2);
    printf("���� ������ ����� �ּ� = %p\n", &ptr2);

    printf("���� ������ ����� �ּ� = %p\n", *ptr1);
    printf("���� ������ ����� �ּ� = %p\n", &ptr1);
    printf("���� ������ ����� �� = %d\n", *(*ptr1));
    printf("���� ������ ����� �� = %d\n", **ptr1);
    puts("");
}

// ���� ���ڿ� �迭
void dynamicString()
{
   /* int len1 = 32;
    char name[len1];  // �����Ϸ� ���� C2133 : �� �� ���� ũ��
    */
    puts("---------���� ���ڿ� �迭------------");

    int len2 = 32;
    char* names = (char*)malloc(len2 * sizeof(char));

    printf("names�� ũ�� : %zd ", sizeof(names));
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
        printf("������ ��Ȯ�ϰ� �Է��� �ֽʽÿ�.");
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
        printf("��Ģ ���길 �� �� �ֽ��ϴ�.\n");
        exit(0);
    }

    printf("��� ��� = %d", c);
}
