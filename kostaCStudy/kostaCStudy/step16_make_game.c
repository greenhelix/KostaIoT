// ���ڹ� 

#include <stdio.h>
#include <conio.h>
#include <cursor.h>
#include "gamepack.h"
#include "header.h"

void Sokoban()
{

	// ���Ӹ� ��������( �޸� �����ؼ�, Ŀ�� ����� ����)
	readyMap();

	// ���� ��ġ ã�Ƶα�
	FindUserPosition();

	// ���� ����
	clearScreen(); //  ȭ�� ������
	putsxy(45, 2,  "SOKOBAN~~");  // �����ǿ� �۾� �ڱ�
	putsxy(45, 4, "ESC Ű�� ���� �����մϴ�.");


	// ���� ���� �ݺ���
	for (;;) {

		// ������ �׸���
		DrawMap();

		// ���� ������ ���� �� ������ ��
		if (UserSetAndMoving()) {
			break;
		}

		theEnd = TRUE;

		// ��� Ȯ��(��ɾȵ�) // �ð��ʳ� ���� �̵� �Ұ� ���¸� �Ǵ��ؾ���.
		ResultCheck();

		if (theEnd) {
			clearScreen();
			putsxy(10, 10, "�� ���߽��ϴ�.");
			delay(2000);
			break;
		}

		showcursor(TRUE);
	} 
}