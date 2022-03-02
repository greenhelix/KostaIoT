#pragma once
class Time;
class Date
{
	// 위험하다 범위가 너무 넓어짐
	friend void OutToday(Date&, Time&);
private:
	int year, month, day;
public:
	Date(int y, int m, int d);
};

