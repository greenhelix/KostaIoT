#include<stdio.h>
#include<conio.h>

class Date {
protected:
	int year, month, day;
public:
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	void OutDate() { printf("%d :: %d :: %d", year, month, day); }
};

class Time {
protected:
	int hour, min, sec;
public:
	Time(int h, int m, int s) { hour = h; min = m; sec = s; }
	void OutTime() { printf("%d >> %d >> %d", hour, min, sec); }
};

// 다중 상속 - 두개의 클래스를 가져온다. 
class DateTime : public Date, public Time {
private: 
	bool bEngMsg;
	int milisec;
public:
	DateTime(int y, int m, int d, int h, int min, int s, int ms, bool b = false) :Date(y, m, d), Time(h, min, s) {
		milisec = ms;
		bEngMsg = b;
	}
	void OutNow() {
		printf(bEngMsg ? "Now is : " : "FUcking now is: ");
		OutDate();
		_putch(' ');
		OutTime();
		printf(".%d", milisec);
		puts(bEngMsg ? "." : "ahaha");
	}
};

//int main() {
//	DateTime now(2017, 7, 28, 15, 30, 58, 99);
//	now.OutNow();
//}