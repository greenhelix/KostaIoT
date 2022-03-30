#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable :4996)

// ����ü�� �Լ� �ۿ� �����ؼ� ����ϱ⵵ �Ѵ�. 
struct MyStruct // ����ü �±׸�
{
	char name[12];
	int age;
	double height;
};  // ����ü ������

void WhatIsStruct()
{
	// �迭�� Ÿ���� ���� ������ ����, ����ü�� Ÿ���� �ٸ� �Ǵ� ���� Ÿ�� ������ ����
	struct MyStruct kim, lee;

	// �̷��Դ� �ȵȴ�.
	//kim.name = "IKHWAN";
	strcpy(kim.name, "IKHWAN");
	kim.age = 31;
	kim.height = 178;
	
	lee = kim;

	printf("�̸� = %s, ���̴� = %d\n", kim.name, kim.age);
	printf("�̸� = %s, ���̴� = %d\n", lee.name, lee.age);
}

struct SBook
{
	char title[20];
	int pages;
	struct MyStruct author;
};

int NestedStruct()
{
	struct SBook api = {
		"�������� API ����", 2100,
		{"�����", 48, 178 }
	};

	printf("���� = %s\n", api.author.name);
}
struct SHuman // ����ü �±׸�
{
	char *name;
	int age;
	double height;
};

void ShallowCopy()
{
	struct SHuman park = { NULL, 30, 160 };
	park.name = (char*)malloc(30);
	strcpy(park.name, "������");

	struct SHuman lee = park;
	strcpy(lee.name, "�̼���");

	printf("%s : %d��, Ű %.2f\n", park.name, park.age, park.height);
	printf("%s : %d��, Ű %.2f\n", lee.name, lee.age, lee.height);

	free(park.name);
	free(lee.name);
}