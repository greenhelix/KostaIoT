#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

class Human
{
private :
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		strcpy(name, aname);
		age = aage;
	}

	void intro() {
		printf("이름 : %s, 나이 : %d\n", name, age);
	}
};

// 학생이 인간 클래스를 상속 받는다. 
class Student : public Human {
private:
	int stunum;

public:
	// 생성자 - 생성시에도 상속을 한다. 안하면 상속의 의미가 없지 않나.
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

int heritMain() {

	// 기본 인간의 intro함수를 사용한 경우
	Human kim("김익환", 31);
	kim.intro();

	// 학생이 기본 인간의 intro함수와 student의 study함수를 사용.. 
	Student han("김한결", 14, 12345);
	han.intro();
	han.study();
	return 0;
}