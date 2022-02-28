#include "step1_var.h"
#include "step2_overload.h"

int main() {
	CppVariable cp1;
	cp1.IsAdult();

	OverLoad cp2;
	cp2.Add(1, 2);
	cp2.Add(1, 2, 3);
	cp2.Add(2.5, 2.5);
	
}