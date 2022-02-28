#include <stdio.h>
#include <iostream>
using namespace std;

class CppVariable {
public:
	void IsAdult() {
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
};

int main() {
	CppVariable study;
	study.IsAdult();
	study.TagType();
	study.Casting();
	study.NewOperator();
	study.IOprint();
}