#include <stdio.h>
#include <iostream>
using namespace std;

class CppVariable {
public:
	void IsAdult() {
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
};

int main() {
	CppVariable study;
	study.IsAdult();
	study.TagType();
	study.Casting();
	study.NewOperator();
	study.IOprint();
}