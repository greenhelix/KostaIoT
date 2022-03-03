#include <stdio.h>
#pragma warning(disable: 4996)

class StaticObjCount {
private:
	int value = 0;
	static int ccount;


public:
	StaticObjCount() { ccount++; }
	~StaticObjCount() { ccount--; }

	void OutCount() {
		printf("현재 객체 개수 = %d\n", ccount);
	}
};

int StaticObjCount::ccount = 0;

int StaticObjCntMain() {
	StaticObjCount oc, * poc;

	oc.OutCount();

	poc = new StaticObjCount;

	poc->OutCount();

	delete poc;

	oc.OutCount();

	printf("크기 = %d\n", (int)sizeof(oc));
	return 0;

}