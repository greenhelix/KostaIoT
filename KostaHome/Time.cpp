#include "Time.h"
#include "Date.h"
#include "Time.h"
#include "Simple.h"
#include <iostream>

Time::Time(int h, int m, int s) { hour = h; min = m; sec = s; }



void OutToday(Date& d, Time& t);

int classMain()
{
	std::cout << "Hello World!\n";
	Date d(2018, 06, 29);
	Time t(12, 34, 56);
	OutToday(d, t);

	Simple A(1), B(2);
	A.OutValue();
	B.OutValue();
	return 0;
}

void OutToday(Date& d, Time& t)
{
	printf("오늘은 %d년 %d월 %d일이며 지금 시간은 %d:%d:%d입니다.\n",
		d.year, d.month, d.day, t.hour, t.min, t.sec);
}

