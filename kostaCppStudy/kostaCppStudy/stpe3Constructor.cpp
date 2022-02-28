#include "stpe3Constructor.h"
#pragma warning (disable: 4996)

CppConstructor::CppConstructor(const char* aname, int aage) {
	strcpy(this->name, aname);
	this->age = aage;
}

void CppConstructor::intro() {
	printf("이름 = %s, 나이 = %d\n", name, age);
}

