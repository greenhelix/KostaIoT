#include <stdio.h>
#include <string.h>

class VHuman
{
protected:
	char name[12];
	int age;

public:
	VHuman(const char* aname, int aage) {
		strcpy_s(name, aname);
		age = aage;
	}
	virtual void intro() {
		printf("이름 = %s, 나이 = %d\n", name, age);
	}
};

class VStudent : public VHuman
{
protected:
	int stunum;

public:
	VStudent(const char* aname, int aage, int astunum) : VHuman(aname, aage) {
		stunum = astunum;
	}
	void intro() {
		printf("%d학번 %s입니다.\n", stunum, name);
	}
	 virtual void study() {
		printf("이이는 사, 이삼은 육, 이사 팔\n");
	}
};

void IntroSomeBody(VHuman* pH) {
	pH->intro();
}

int main()
{
	VHuman h("김사람", 10);
	VStudent s("이학생", 15, 1234567);

	IntroSomeBody(&h);
	IntroSomeBody(&s);
}

