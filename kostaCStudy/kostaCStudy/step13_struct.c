#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable :4996)

// 구조체는 함수 밖에 선언해서 사용하기도 한다. 
struct MyStruct // 구조체 태그명
{
	char name[12];
	int age;
	double height;
};  // 구조체 변수명

void WhatIsStruct()
{
	// 배열은 타입이 같은 변수의 집합, 구조체는 타입이 다른 또는 임의 타입 변수의 집합
	struct MyStruct kim, lee;

	// 이렇게는 안된다.
	//kim.name = "IKHWAN";
	strcpy(kim.name, "IKHWAN");
	kim.age = 31;
	kim.height = 178;
	
	lee = kim;

	printf("이름 = %s, 나이는 = %d\n", kim.name, kim.age);
	printf("이름 = %s, 나이는 = %d\n", lee.name, lee.age);
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
		"윈도우즈 API 정복", 2100,
		{"김상형", 48, 178 }
	};

	printf("저자 = %s\n", api.author.name);
}
struct SHuman // 구조체 태그명
{
	char *name;
	int age;
	double height;
};

void ShallowCopy()
{
	struct SHuman park = { NULL, 30, 160 };
	park.name = (char*)malloc(30);
	strcpy(park.name, "김유신");

	struct SHuman lee = park;
	strcpy(lee.name, "이순신");

	printf("%s : %d세, 키 %.2f\n", park.name, park.age, park.height);
	printf("%s : %d세, 키 %.2f\n", lee.name, lee.age, lee.height);

	free(park.name);
	free(lee.name);
}