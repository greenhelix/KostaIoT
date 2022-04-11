#include <stdio.h>
#include <stdlib.h>
class Circle {

private:
	int cx, cy, r;
public:
	Circle(int x, int y, int ar) {
		cx = x;
		cy = y;
		r = ar;
	}
	Circle(int left, int top, int right, int bottom) {
		cx = (left + right) / 2;
		cy = (top + bottom) / 2;
		r = (abs(left) + right) / 2;
	}
};

class Time {
private:
	int sec, min, hour;
public:
	Time(int asec, int amin, int ahour) {
		sec = asec;
		min = amin;
		hour = ahour; 
	}
	void nowTime() {
		printf("%d:%d:%d", hour, min, sec);
	}
};

//int main() {
//	Time* a;
//	a = new Time(10, 30, 11);
//	a->nowTime();
//	delete a;
//}