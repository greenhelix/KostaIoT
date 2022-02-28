#include <stdio.h>
#include <iostream>
using namespace std;
#pragma warning (disable: 4996)


//당장은 레퍼런스가 왜 필요한지 감이 잡기 힘들다. 
//별명이라는 것만 이해하자. 
//클래스가 완전한 타입이 되기 위해서는 기능뿐만 아니라 형식도 기본 타입과 일치시켜야 하는데,
//복사 생성자나 연산자 오버로딩에 레퍼런스가 유용하기 때문이다. 
class CppVariable {
public:

	void IsAdult() 
	{
		int age = 25;
		bool isAdult = age > 19;

		if (isAdult) {
			puts("성인입니다.");
		}
	}

	void TagType()
	{
		enum origin { EAST, WEST, SOUTH, NORTH };
		enum origin mark = WEST;
		printf("%d 방향\n", mark);

		struct SHuman {
			char name[12];
			int age;
			double height;
		};
		struct SHuman kim = { "김익환", 31, 178 };
		printf("이름 = %s, 나이 = %d\n", kim.name, kim.age);
	}

	void Casting()
	{
		int a = 10, b = 5;
		// c: (float)(a+b) 로 캐스팅 해야하지만 cpp에선 안그래도 된다.
		cout << float(a+b) << endl;
	}

	void NewOperator()
	{
		int* pi;
		/*pi = new int;
		*pi = 123;*/
		// 위와 같이 안해도 된다. 바로 한줄로 선언 가능 하다. 
		// 동적할당으로 할 수 있다. c의 malloc()/free()이 단순화 된것이다.
		pi = new int(123);
		cout << *pi << endl;
		delete pi;
		int* ar;
		ar = new int[5];
		for (int i = 0; i < 5; i++) {
			ar[i] = i*10;
		}
		for (int i = 0; i < 5; i++) {
			cout << i << "=" << ar[i] << endl; 
		}
		delete[] ar;
	}

	void IOprint()
	{
		int age;
		cout << "나이를 입력하시오 : ";
		cin >> age;
		cout << "당신은 " << age << "살입니다." << endl;
	}

	void ReferenceVar()
	{
		int i = 3;
		int& refI = i; //refI 정수형 래퍼런스에 i를 넣어서 초기화 한다.
		cout << "i = " << i << ", refI = " << refI << endl;
		printf("i번지 = %p, refI번지 = %p\n", &i, &refI); //주소가 동일한 값이 나온다.
		refI++;
		cout << "i = " << i << ", refI = " << refI << endl;
		printf("i번지 = %p, refI번지 = %p\n", &i, &refI); // 같이 올라간다.
		
		int j = 5;
		int jj = j;
		cout << "j = " << j << ", jj = " << jj << endl;
		printf("j번지 = %p, ii번지 = %p\n", &j, &jj); //주소가 다른다.
		jj++;
		cout << "j = " << j << ", jj = " << jj << endl;
		printf("j번지 = %p, ii번지 = %p\n", &j, &jj); // jj는 따로 올라간다.
		
		int a = 4, b = 9;
		int& refA = a;
		printf("i=%d, ri=%d, j=%d\n", a, refA, b);
		refA = b;
		printf("i=%d, ri=%d, j=%d\n", a, refA, b);

		// 배열은 레퍼런스를 쓸 수 없다. 
		int arI[]{ 1,2,3 };
		for (int i : arI) {
			cout << i << "::" << &i << endl;
		}
		int (&refAr)[3] = arI;
		for (int i : refAr) {
			cout << i <<"::"<< &i << endl;
		}

		// 이중 레퍼런스 쓸 수 없다. 
		int aaa;
		int& ari = aaa;
		//int& aari = &ari; // 불가능
		
		// 포인터에 대한 레퍼런스 쓸 수 없다.
		//int&* pari = &ari; // 불가능
	}

	void InputName(char*& inPut) {
		inPut = (char*)malloc(32);
		strcpy(inPut, "kim ik hwan");
	}

	void InputNameCheck() 
	{
		char* Name;
		InputName(Name);
		printf("이름은 %s입니다.\n", Name);
		free(Name);
	}

	void WhatIsAdvantage(int &a) {
		a += 1;
		printf("이름은 %d입니다.\n", a);
		// 함수 레퍼런스 
		//int& FindMatchRef(char* name, int value, bool bCase);
		//FindMatchRef(...) = Data;
	}

	void WhatIsBeforeInC(int* a) {
		*a += 1;
		printf("이름은 %d입니다.\n", *a);
		// 함수 레퍼런스
		//int FindMatchRef(char* name, int value, bool bCase);
		//arSome[FindMatch(...)] = Data;
	}
};

int main() {
	CppVariable study;

	//study.IsAdult();
	//study.TagType();
	//study.Casting();
	//study.NewOperator();
	//study.IOprint();
	//study.ReferenceVar();
	//study.InputNameCheck();

	int t = 10, tt = 10;  // 똑같은 개념/기능의 함수이다. 
	study.WhatIsAdvantage(t); //좀 더 구분하기 쉽게 바뀐 것이다.
	study.WhatIsBeforeInC(&tt);
}