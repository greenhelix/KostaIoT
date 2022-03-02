#pragma once
class Date;
class Time
{
	friend void OutToday(Date&, Time&);
private:
	int hour, min, sec;
public:
	Time(int h, int m, int s);
};

