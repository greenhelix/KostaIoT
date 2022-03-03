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
		printf("현재 객체 개수 = %d\n", count);
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

	printf("크기 = %d\n", (int)sizeof(oc));
}