#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;

class CppVariable
{
private: 
	int input;
public:
	void IsAdult();
	void TagType();
	void Casting();
	void NewOperator();
	void IOprint();
	void ReferenceVar();
	void InputName(char*& inPut);
	void InputNameCheck();
	void WhatIsAdvantage(int& a);
	void WhatIsBeforeInC(int* a);
};
