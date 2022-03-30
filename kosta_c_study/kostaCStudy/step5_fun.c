// 함수 
#include <stdio.h>
#pragma warning(disable:4996)

void whatIsFunction()
{


}

int GetSum(int from, int to)
{
	int num = 0;

	if (from > to)
	{
		printf("%s\n", num == -1 ? "참": "거짓");
		num = -1;
		return num;
	}

	for (int i = from; i <= to; i++)
	{
		num += i;
	}

	return num;
}

#include <time.h>
int GetHour()
{
	time_t t;
	time(&t);
	struct tm* pt = localtime(&t);
	return pt->tm_hour;
}

int GetHours()
{
	time_t t;
	time(&t);

	time_t base_time = 0;
	struct tm base_date_local;
	char buf[100];
	localtime_s(&base_date_local, &base_time);

	struct tm* pt = &base_date_local;
	return pt->tm_hour;
}