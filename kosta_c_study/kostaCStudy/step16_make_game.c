// 소코반 

#include <stdio.h>
#include <conio.h>
#include <cursor.h>
#include "gamepack.h"
#include "header.h"

void Sokoban()
{

	// 게임맵 가져오기( 메모리 복사해서, 커서 숨기기 포함)
	readyMap();

	// 유저 위치 찾아두기
	FindUserPosition();

	// 게임 진행
	clearScreen(); //  화면 깨끗이
	
	// 게임 진행 반복문
	while(UserSetAndMoving() && ResultCheck()) {
		redraw();
	}

	showcursor(TRUE);
}