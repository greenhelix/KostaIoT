#pragma once
class Time;
class Date
{
	// �����ϴ� ������ �ʹ� �о���
	friend void OutToday(Date&, Time&);
private:
	int year, month, day;
public:
	Date(int y, int m, int d);
};

