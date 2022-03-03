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
		printf("�̸� : %s, ���� : %d\n", name, age);
	}
};

// �л��� �ΰ� Ŭ������ ��� �޴´�. 
class Student : public Human {
private:
	int stunum;

public:
	// ������ - �����ÿ��� ����� �Ѵ�. ���ϸ� ����� �ǹ̰� ���� �ʳ�.
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void study() {
		printf("���̴� ��, �̻��� ��, �̻� ��\n");
	}
};

int heritMain() {

	// �⺻ �ΰ��� intro�Լ��� ����� ���
	Human kim("����ȯ", 31);
	kim.intro();

	// �л��� �⺻ �ΰ��� intro�Լ��� student�� study�Լ��� ���.. 
	Student han("���Ѱ�", 14, 12345);
	han.intro();
	han.study();
	return 0;
}