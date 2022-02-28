#include <stdio.h>
#include "step2_overload.h"

int OverLoad::Add(int a, int b) {
	return a + b;
}

int OverLoad::Add(int a, int b, int c) {
	return a + b + c;
}

double OverLoad::Add(double a, double b) {
	return a + b;
}
