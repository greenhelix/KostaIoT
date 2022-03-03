#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "cursor.h"

class Car {
private:
	int gear;
	int angle;
	int rpm; 

public:
	// 생성자 
	Car() { gear = 0; angle = 0; rpm = 0; }

	// 기어 변속 함수 
	void ChangeGear(int aGear) {
		if (aGear >= 0 && aGear <= 6)
		{
			gear = aGear;
		}
	}
	
	// 움직이는 바퀴 함수
	void RotateWheel(int Delta) {
		int tAngle = angle + Delta;
		if (tAngle >= -45 && tAngle <= 45) {
			angle = tAngle;
		}
	}

	// 엑셀레이터 함수 rpm 계산
	void Accel() {
		rpm = min(rpm + 100, 3000);
	}

	// 브레이크 함수 rpm 계산
	void Break() {
		rpm = max(rpm - 500, 0); 
	}

	void Run() {
		int Speed;
		char Mes[128];
		gotoxy(10, 13);

		if (gear == 0)
		{
			puts("먼저 1~6키를 눌러 기어를 넣으시오     ");
			return;
		}
		if (gear == 6)
		{
			Speed = rpm / 100; 
		}
		else {
			Speed = gear * rpm / 100; 
		}

		sprintf(Mes, "%d의 속도로 %s쪽 %d도 방향으로 %s진 중    ",
			abs(Speed), (angle >= 0 ? "오른" : "왼"), abs(angle),
			(gear == 6 ? "후" : "전"));

		puts(Mes);
	}
};

int CarMain() {
	Car C;
	int ch; 

	for (;;) {
		gotoxy(10, 10);
		printf("1~5 : 기어 변속, 6: 후진 기어, 0: 기어 중립");
		
		if (kbhit()) // 키 입력여부 확인 있으면 1,없으면 0 
		{
			ch = getch();
			if (ch == 0xE0 || ch == 0)
			{
				ch = getch();

				switch (ch)
				{
				case 75: 
					C.RotateWheel(-5);
					break;
				case 77:
					C.RotateWheel(5);
					break;
				case 72:
					C.Accel();
					break;
				case 80:
					C.Break();
					break;
				}
			}
			else {
				if (ch >= '0' && ch <= '6')
				{
					C.ChangeGear(ch - '0');
				}
				else if (ch == 'Q' || ch == 'q') {
					exit(0);
				}
			}
		}
		C.Run();
		delay(10);
	}
}

