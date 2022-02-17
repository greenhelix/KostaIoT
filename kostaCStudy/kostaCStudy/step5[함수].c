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
		printf("%s\n", num == -1 ? "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ú°ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Úºï¿½ï¿½ï¿½ Å®ï¿½Ï´ï¿½." : "ï¿½ï¿½ï¿½ï¿½Õ´Ï´ï¿?.");
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
	struct tm *pt = localtime(&t);
	return pt->tm_hour;
}

int GetHours()
{
	time_t t;
	time(&t);
	
	time_t base_time = 0;
	struct tm base_date_local;
	char buf[100];
	//ì´? ?‹¨?œ„ ê°’ì„ ì§??—­ ?‹œê°?(DateTime)?„ êµ¬í•œ?‹¤.
	localtime_s(&base_date_local, &base_time);

	struct tm *pt = &base_date_local; //localtime_s(&base_date_local, &t);
	return pt->tm_hour;
}

