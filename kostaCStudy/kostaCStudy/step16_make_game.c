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
	
	// ���� ���� �ݺ���
	while(UserSetAndMoving() && ResultCheck()) {
		redraw();
	}

	showcursor(TRUE);
}