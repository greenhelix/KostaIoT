#include <stdio.h>
#pragma warning(disable: 4996)

int count = 0;

class ObjCount {
private:
	int value;
	static int ccount;


public:
	ObjCount() { count++; }
	~ObjCount() { count--; }

	void OutCount() {
		printf("���� ��ü ���� = %d\n", count);
	}
};

int ObjCount::ccount = 0;

int ObjCntMain() {
	ObjCount oc, * poc;

	oc.OutCount();

	poc = new ObjCount;

	poc->OutCount();

	delete poc;

	oc.OutCount();

	printf("ũ�� = %d\n", (int)sizeof(oc));
}