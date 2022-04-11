#include <stdio.h>
#include <string.h>

class Human {
protected: char name[12];
	   int age;
public:
	Human(const char* aname, int aage) {
		strcpy_s(name, aname);
		age = aage;
	}
	void intro() {
		printf("name:%s, age: %d\n", name, age);
	}
};

class Student : public Human {
private:
	int stunum;

public:
	Student(const char* aname, int aage, int astunum) : Human(aname, aage) {
		stunum = astunum;
	}
	void study() {
		printf("2*2 = 4, 2*3 = 6, 2*4 = 8\n");
	}

	// Human �� �ִ� name, age�� ��ӹް��� �Ѵٸ�, private�� �ƴ� protected�� �������ָ� ��ӹ޴� �ڽĵ��� ������ ���� �ִ�.
	void report() { 
		printf("name: %s stunum : %d,age:%d \n", name, stunum, age);
	} 
	// �� ��� �� ���ζ��, Student ������ �Լ����� �޾ƿ� �� �ִ�. private ���� int char[12]�� ���� �����ѵ� �������൵ �ȴ�.
};

// ���ӵǴ� ��� 
class Graduate : public Student {
private:
	char thesis[32];
public:
	Graduate(const char* aname, int aage, int astunum, const char* athesis) : Student(aname, aage, astunum) {
		strcpy_s(thesis, athesis);
	}
	void research() {
		printf("%s researching and writhe thesis", thesis);
	}
};

//int main() {
//	Human kim("hiii", 1232);
//	kim.intro();
//
//	Student han("dfhefl", 12, 12345667);
//	han.intro();
//	han.study();
//	han.report();
//
//	// Graduate class �� human, student�� ��� �Լ��� ��밡���ϴ�. 
//	Graduate miky("hellomtf", 149, 1327839, "thesis:TitleFUck");
//	miky.intro();
//	miky.study();
//	miky.report();
//	miky.research();
//}