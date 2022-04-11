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

	// Human 에 있는 name, age를 상속받고자 한다면, private이 아닌 protected로 변경해주면 상속받는 자식들은 가져올 수가 있다.
	void report() { 
		printf("name: %s stunum : %d,age:%d \n", name, stunum, age);
	} 
	// 이 방법 이 별로라면, Student 생성자 함수에서 받아올 수 있다. private 에서 int char[12]를 따로 선언한뒤 가져와줘도 된다.
};

// 연속되는 상속 
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
//	// Graduate class 는 human, student의 모든 함수를 사용가능하다. 
//	Graduate miky("hellomtf", 149, 1327839, "thesis:TitleFUck");
//	miky.intro();
//	miky.study();
//	miky.report();
//	miky.research();
//}