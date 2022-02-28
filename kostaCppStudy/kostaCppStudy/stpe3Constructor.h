#pragma once
#include <stdio.h>
#include <string.h>

class CppConstructor
{
private:
	char name[12];
	int age; 
public:
	CppConstructor(const char* aname, int aage);
	void intro();
};

