#include <stdio.h>
#include <iostream>
using namespace std;
#pragma warning (disable: 4996)


//������ ���۷����� �� �ʿ����� ���� ��� �����. 
//�����̶�� �͸� ��������. 
//Ŭ������ ������ Ÿ���� �Ǳ� ���ؼ��� ��ɻӸ� �ƴ϶� ���ĵ� �⺻ Ÿ�԰� ��ġ���Ѿ� �ϴµ�,
//���� �����ڳ� ������ �����ε��� ���۷����� �����ϱ� �����̴�. 
class CppVariable {
public:

	void IsAdult() 
	{
		int age = 25;
		bool isAdult = age > 19;

		if (isAdult) {
			puts("�����Դϴ�.");
		}
	}

	void TagType()
	{
		enum origin { EAST, WEST, SOUTH, NORTH };
		enum origin mark = WEST;
		printf("%d ����\n", mark);

		struct SHuman {
			char name[12];
			int age;
			double height;
		};
		struct SHuman kim = { "����ȯ", 31, 178 };
		printf("�̸� = %s, ���� = %d\n", kim.name, kim.age);
	}

	void Casting()
	{
		int a = 10, b = 5;
		// c: (float)(a+b) �� ĳ���� �ؾ������� cpp���� �ȱ׷��� �ȴ�.
		cout << float(a+b) << endl;
	}

	void NewOperator()
	{
		int* pi;
		/*pi = new int;
		*pi = 123;*/
		// ���� ���� ���ص� �ȴ�. �ٷ� ���ٷ� ���� ���� �ϴ�. 
		// �����Ҵ����� �� �� �ִ�. c�� malloc()/free()�� �ܼ�ȭ �Ȱ��̴�.
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
		cout << "���̸� �Է��Ͻÿ� : ";
		cin >> age;
		cout << "����� " << age << "���Դϴ�." << endl;
	}

	void ReferenceVar()
	{
		int i = 3;
		int& refI = i; //refI ������ ���۷����� i�� �־ �ʱ�ȭ �Ѵ�.
		cout << "i = " << i << ", refI = " << refI << endl;
		printf("i���� = %p, refI���� = %p\n", &i, &refI); //�ּҰ� ������ ���� ���´�.
		refI++;
		cout << "i = " << i << ", refI = " << refI << endl;
		printf("i���� = %p, refI���� = %p\n", &i, &refI); // ���� �ö󰣴�.
		
		int j = 5;
		int jj = j;
		cout << "j = " << j << ", jj = " << jj << endl;
		printf("j���� = %p, ii���� = %p\n", &j, &jj); //�ּҰ� �ٸ���.
		jj++;
		cout << "j = " << j << ", jj = " << jj << endl;
		printf("j���� = %p, ii���� = %p\n", &j, &jj); // jj�� ���� �ö󰣴�.
		
		int a = 4, b = 9;
		int& refA = a;
		printf("i=%d, ri=%d, j=%d\n", a, refA, b);
		refA = b;
		printf("i=%d, ri=%d, j=%d\n", a, refA, b);

		// �迭�� ���۷����� �� �� ����. 
		int arI[]{ 1,2,3 };
		for (int i : arI) {
			cout << i << "::" << &i << endl;
		}
		int (&refAr)[3] = arI;
		for (int i : refAr) {
			cout << i <<"::"<< &i << endl;
		}

		// ���� ���۷��� �� �� ����. 
		int aaa;
		int& ari = aaa;
		//int& aari = &ari; // �Ұ���
		
		// �����Ϳ� ���� ���۷��� �� �� ����.
		//int&* pari = &ari; // �Ұ���
	}

	void InputName(char*& inPut) {
		inPut = (char*)malloc(32);
		strcpy(inPut, "kim ik hwan");
	}

	void InputNameCheck() 
	{
		char* Name;
		InputName(Name);
		printf("�̸��� %s�Դϴ�.\n", Name);
		free(Name);
	}

	void WhatIsAdvantage(int &a) {
		a += 1;
		printf("�̸��� %d�Դϴ�.\n", a);
		// �Լ� ���۷��� 
		//int& FindMatchRef(char* name, int value, bool bCase);
		//FindMatchRef(...) = Data;
	}

	void WhatIsBeforeInC(int* a) {
		*a += 1;
		printf("�̸��� %d�Դϴ�.\n", *a);
		// �Լ� ���۷���
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

	int t = 10, tt = 10;  // �Ȱ��� ����/����� �Լ��̴�. 
	study.WhatIsAdvantage(t); //�� �� �����ϱ� ���� �ٲ� ���̴�.
	study.WhatIsBeforeInC(&tt);
}