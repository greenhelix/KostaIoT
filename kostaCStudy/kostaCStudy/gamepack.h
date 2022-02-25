#pragma once
#define mapRow 18
#define mapCol 21 // col 은 20개이지만 뒤에 \0때문에 21사이즈로 잡아준다.
#define putchxy(x,y,c) {gotoxy(x,y); _putch(c);}
#define putsxy(x,y,s) {gotoxy(x,y); puts(s);}

int user;
int x, y;
int user_x, user_y;
int move_x, move_y;
char map[mapRow][mapCol];
BOOL theEnd;
enum {ESC = 27,LEFT = 75,RIGHT = 77,UP = 72,DOWN = 80}; // 열거형 (키값을 아스키 코드로 가져와서 선언해둔다.)

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

void clearScreen() {
	clrscr();
}

void readyMap() {
	showcursor(FALSE);
	memcpy(map, mapData, sizeof(mapData));
}

void FindUserPosition() {
	for (y = 0; y < 18; y++) {
		for (x = 0; x < 20; x++) {

			if (map[y][x] == '@') {
				user_x = x;
				user_y = y;
				map[y][x] = ' ';
			}
		}
	}
}

void UserMoving() {
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
}

void DrawMap() {
	for (y = 0; y < 18; y++) {
		putsxy(0, y, map[y]);
	}
}

int UserSetAndMoving()
{
	// 찾아둔 유저 위치에 @넣어주기 
	putchxy(user_x, user_y, '@');

	// 유저 이동 
	user = _getch();
	if (user == 0xE0 || user == 0)
	{
		user = _getch();
		move_x = move_y = 0;
		UserMoving();


		// 이동 알고리즘 조건문
		// 벽이 아니라면 이동한다
		if (map[user_y + move_y][user_x + move_x] != '#')
		{

			// 유저 앞에 짐이 있다면
			if (map[user_y + move_y][user_x + move_x] == 'O')
			{

				// 이동하는 다음 칸이 빈공간? 아니면 창고? 
				if (map[user_y + move_y * 2][user_x + move_x * 2] == ' ' ||
					map[user_y + move_y * 2][user_x + move_x * 2] == '.')
				{

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
			return 1;
		}
	}
	return 0;
}

void ResultCheck() {
	// 결과 검사
	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 20; x++) {
			if (map[y][x] == '.') {
				theEnd = FALSE;
			}
		}
	}
}
