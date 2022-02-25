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
	putsxy(45, 2,  "SOKOBAN~~");  // 게임판에 글씨 박기
	putsxy(45, 4, "ESC 키를 눌러 종료합니다.");


	// 게임 진행 반복문
	for (;;) {

		// 게임판 그리기
		DrawMap();

		// 유저 시작점 셋팅 및 움직임 논리
		if (UserSetAndMoving()) {
			break;
		}

		theEnd = TRUE;

		// 결과 확인(기능안됨) // 시간초나 짐의 이동 불가 상태를 판단해야함.
		ResultCheck();

		if (theEnd) {
			clearScreen();
			putsxy(10, 10, "참 잘했습니다.");
			delay(2000);
			break;
		}

		showcursor(TRUE);
	} 
}