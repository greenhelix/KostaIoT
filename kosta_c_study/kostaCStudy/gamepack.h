#pragma once
#define mapRow 18
#define mapCol 21 // col 은 20개이지만 뒤에 \0때문에 21사이즈로 잡아준다.
#define putchxy(x,y,c) {gotoxy(x,y); _putch(c);}
#define putsxy(x,y,s) {gotoxy(x,y); puts(s);}

int user;
int user_x, user_y;
int undoX, undoY;

char map[mapRow][mapCol];
char undoStage[mapRow][mapCol];

enum {ESC = 27, LEFT = 75, RIGHT = 77,UP = 72,DOWN = 80, UNDO = 9 }; // 열거형 (키값을 아스키 코드로 가져와서 선언해둔다.)

char mapData[mapRow][mapCol] = {
	"####################",
	"####################",
	"####################",
	"#####   ############",
	"#####O  ############",
	"#####  O############",
	"###  O O ###########",
	"### # ## ###########",
	"#   # ## #####  ..##",
	"# O  O   @      ..##",
	"##### ### # ##  ..##",
	"#####     ##########",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################",
	"####################"
};



void readyMap() {
	showcursor(FALSE);
	memcpy(map, mapData, sizeof(mapData));
}

void FindUserPosition() {
	for (user_y = 0; user_y < mapRow; user_y++) {
		for (user_x = 0; user_x < mapCol - 1; user_x++) {

			if (map[user_y][user_x] == '@') {
				map[user_y][user_x] = ' ';
				return;
			}
		}
	}
}

void redraw()
{
	for (int y = 0; y < mapRow; y++) {
		putsxy(0, y, map[y]);

	}
	putchxy(user_x, user_y, '@');

}

int UserSetAndMoving()
{
	int move_x = 0, move_y = 0;
	// 유저 이동 
	user = _getch();
	if (user == 0xE0 || user == 0)
	{
		putsxy(45, 7, "    ");
		user = _getch();

		switch (user)
		{
		case LEFT:
			move_x = -1;
			break;
		case RIGHT:
			move_x = 1;
			break;
		case UP:
			move_y = -1;
			break;
		case DOWN:
			move_y = 1;
			break;
		}

		// 이동 알고리즘 조건문 // 벽이 아니라면 이동한다
		if (map[user_y + move_y][user_x + move_x] != '#')
		{

			// 유저 앞에 짐이 있다면
			if (map[user_y + move_y][user_x + move_x] == 'O')
			{

				// 이동하는 다음 칸이 빈공간? 아니면 창고? 
				if (map[user_y + move_y * 2][user_x + move_x * 2] == ' ' ||
					map[user_y + move_y * 2][user_x + move_x * 2] == '.')
				{
					//되돌리기
					memcpy(undoStage, map, sizeof(map));
					undoX = user_x;
					undoY = user_y;

					// 창고 위치라면 빈공간으로 가거나, 창고에서 이동하거나
					if (map[user_y + move_y][user_x + move_x] == '.')
					{
						map[user_y + move_y][user_x + move_x] = '.';
					}
					else
					{
						map[user_y + move_y][user_x + move_x] = ' ';
					}

					// 유저 이동이 아니라면, 짐이 이동한다.
					map[user_y + move_y * 2][user_x + move_x * 2] = 'O';

				}
				else
				{
					// 못 움직인다.
					move_x = move_y = 0;
				}
			}

			user_x += move_x;
			user_y += move_y;

		}
	}
	else
	{
		// 벽이 아닌경우 사용자가 esc를 누르면 강제 종료
		if (user == ESC)
		{
			return 0;
		}
		else if (user == UNDO ) {
			putsxy(45, 6, "되돌리기를 눌렀습니다.");
			memcpy(map, undoStage, sizeof(map));
			user_x = undoX;
			user_y = undoY;
			redraw();
		}
	}
	return 1;
}



void clearScreen() {
	clrscr();
	putsxy(45, 2, "SOKOBAN~~");  // 게임판에 글씨 박기
	putsxy(45, 4, "ESC 키를 눌러 종료합니다.");
}


int ResultCheck() {
	BOOL theEnd = TRUE;
	// 결과확인
	for (int y = 0; y < mapRow; y++)
	{
		for (int x = 0; x < mapCol; x++) {

			if (map[y][x] == '.') {
				theEnd = FALSE;
			}
		}
	}
	if (theEnd) {
		clrscr();
		putsxy(10, 10, "참 잘했습니다.");
		delay(2000);
		return 0;
	}
	return 1;
}
