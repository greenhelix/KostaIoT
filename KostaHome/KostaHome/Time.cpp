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
	printf("������ %d�� %d�� %d���̸� ���� �ð��� %d:%d:%d�Դϴ�.\n",
		d.year, d.month, d.day, t.hour, t.min, t.sec);
}

