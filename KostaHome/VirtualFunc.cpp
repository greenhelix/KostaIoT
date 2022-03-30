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
		printf("�̸� = %s, ���� = %d\n", name, age);
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
		printf("%d�й� %s�Դϴ�.\n", stunum, name);
	}
	 virtual void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

void IntroSomeBody(VHuman* pH) {
	pH->intro();
}

int main()
{
	VHuman h("����", 10);
	VStudent s("���л�", 15, 1234567);

	IntroSomeBody(&h);
	IntroSomeBody(&s);
}

