#include <stdio.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable: 4996)
#pragma comment(lib, "user32")

class Human {
private:
	char name[12];
	int age;

public:
	Human(const char* aname, int aage) {
		SetName(aname);
		SetAge(aage);
	}

	void intro() {
		printf("�̸� = %s, ���� = %d\n", name, age);
	}

	char* GetName() { return name; }

	void SetName(const char* aname) {
		if (strlen(aname)<12)
		{
			strcpy(name, aname);
		}
		else {
			strcpy(name, "");
		}
	}

	int GetAge() { return age; }

	void SetAge(int aage) {
		if (aage >= 0 && aage <= 120)
		{
			age = aage;
		}
		else {
			age = 0;
		}
	}
};

int Humanmain() {
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); //�ܼ�â ��üȭ��
	Human kim("����ȯ", 31);
	kim.SetName("Kim Ik Hwan");
	kim.SetAge(145);
	kim.intro();
}