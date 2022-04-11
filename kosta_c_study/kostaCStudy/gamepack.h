#pragma once
#define mapRow 18
#define mapCol 21 // col �� 20�������� �ڿ� \0������ 21������� ����ش�.
#define putchxy(x,y,c) {gotoxy(x,y); _putch(c);}
#define putsxy(x,y,s) {gotoxy(x,y); puts(s);}

int user;
int user_x, user_y;
int undoX, undoY;

char map[mapRow][mapCol];
char undoStage[mapRow][mapCol];

enum {ESC = 27, LEFT = 75, RIGHT = 77,UP = 72,DOWN = 80, UNDO = 9 }; // ������ (Ű���� �ƽ�Ű �ڵ�� �����ͼ� �����صд�.)

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
	// ���� �̵� 
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

		// �̵� �˰��� ���ǹ� // ���� �ƴ϶�� �̵��Ѵ�
		if (map[user_y + move_y][user_x + move_x] != '#')
		{

			// ���� �տ� ���� �ִٸ�
			if (map[user_y + move_y][user_x + move_x] == 'O')
			{

				// �̵��ϴ� ���� ĭ�� �����? �ƴϸ� â��? 
				if (map[user_y + move_y * 2][user_x + move_x * 2] == ' ' ||
					map[user_y + move_y * 2][user_x + move_x * 2] == '.')
				{
					//�ǵ�����
					memcpy(undoStage, map, sizeof(map));
					undoX = user_x;
					undoY = user_y;

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
			return 0;
		}
		else if (user == UNDO ) {
			putsxy(45, 6, "�ǵ����⸦ �������ϴ�.");
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
	putsxy(45, 2, "SOKOBAN~~");  // �����ǿ� �۾� �ڱ�
	putsxy(45, 4, "ESC Ű�� ���� �����մϴ�.");
}


int ResultCheck() {
	BOOL theEnd = TRUE;
	// ���Ȯ��
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
		putsxy(10, 10, "�� ���߽��ϴ�.");
		delay(2000);
		return 0;
	}
	return 1;
}
