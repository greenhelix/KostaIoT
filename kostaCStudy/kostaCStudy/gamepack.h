#pragma once
#define mapRow 18
#define mapCol 21 // col �� 20�������� �ڿ� \0������ 21������� ����ش�.
#define putchxy(x,y,c) {gotoxy(x,y); _putch(c);}
#define putsxy(x,y,s) {gotoxy(x,y); puts(s);}

int user;
int x, y;
int user_x, user_y;
int move_x, move_y;
char map[mapRow][mapCol];
BOOL theEnd;
enum {ESC = 27,LEFT = 75,RIGHT = 77,UP = 72,DOWN = 80}; // ������ (Ű���� �ƽ�Ű �ڵ�� �����ͼ� �����صд�.)

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
	// ã�Ƶ� ���� ��ġ�� @�־��ֱ� 
	putchxy(user_x, user_y, '@');

	// ���� �̵� 
	user = _getch();
	if (user == 0xE0 || user == 0)
	{
		user = _getch();
		move_x = move_y = 0;
		UserMoving();


		// �̵� �˰��� ���ǹ�
		// ���� �ƴ϶�� �̵��Ѵ�
		if (map[user_y + move_y][user_x + move_x] != '#')
		{

			// ���� �տ� ���� �ִٸ�
			if (map[user_y + move_y][user_x + move_x] == 'O')
			{

				// �̵��ϴ� ���� ĭ�� �����? �ƴϸ� â��? 
				if (map[user_y + move_y * 2][user_x + move_x * 2] == ' ' ||
					map[user_y + move_y * 2][user_x + move_x * 2] == '.')
				{

					// â�� ��ġ��� ��������� ���ų�, â���� �̵��ϰų�
					if (map[user_y + move_y][user_x + move_x] == '.')
					{
						map[user_y + move_y][user_x + move_x] = '.';
					}
					else
					{
						map[user_y + move_y][user_x + move_x] = ' ';
					}

					// ���� �̵��� �ƴ϶��, ���� �̵��Ѵ�.
					map[user_y + move_y * 2][user_x + move_x * 2] = 'O';

				}
				else
				{
					// �� �����δ�.
					move_x = move_y = 0;
				}
			}

			user_x += move_x;
			user_y += move_y;

		}
	}
	else
	{
		// ���� �ƴѰ�� ����ڰ� esc�� ������ ���� ����
		if (user == ESC)
		{
			return 1;
		}
	}
	return 0;
}

void ResultCheck() {
	// ��� �˻�
	for (y = 0; y < 18; y++)
	{
		for (x = 0; x < 20; x++) {
			if (map[y][x] == '.') {
				theEnd = FALSE;
			}
		}
	}
}
