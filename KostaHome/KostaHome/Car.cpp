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
	// ������ 
	Car() { gear = 0; angle = 0; rpm = 0; }

	// ��� ���� �Լ� 
	void ChangeGear(int aGear) {
		if (aGear >= 0 && aGear <= 6)
		{
			gear = aGear;
		}
	}
	
	// �����̴� ���� �Լ�
	void RotateWheel(int Delta) {
		int tAngle = angle + Delta;
		if (tAngle >= -45 && tAngle <= 45) {
			angle = tAngle;
		}
	}

	// ���������� �Լ� rpm ���
	void Accel() {
		rpm = min(rpm + 100, 3000);
	}

	// �극��ũ �Լ� rpm ���
	void Break() {
		rpm = max(rpm - 500, 0); 
	}

	void Run() {
		int Speed;
		char Mes[128];
		gotoxy(10, 13);

		if (gear == 0)
		{
			puts("���� 1~6Ű�� ���� �� �����ÿ�     ");
			return;
		}
		if (gear == 6)
		{
			Speed = rpm / 100; 
		}
		else {
			Speed = gear * rpm / 100; 
		}

		sprintf(Mes, "%d�� �ӵ��� %s�� %d�� �������� %s�� ��    ",
			abs(Speed), (angle >= 0 ? "����" : "��"), abs(angle),
			(gear == 6 ? "��" : "��"));

		puts(Mes);
	}
};

int CarMain() {
	Car C;
	int ch; 

	for (;;) {
		gotoxy(10, 10);
		printf("1~5 : ��� ����, 6: ���� ���, 0: ��� �߸�");
		
		if (kbhit()) // Ű �Է¿��� Ȯ�� ������ 1,������ 0 
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

