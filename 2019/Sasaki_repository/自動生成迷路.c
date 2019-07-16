#include <stdio.h>	//	コンソールに文字を出力するため
#include <stdlib.h>	//	systemと乱数を使うため
#include <conio.h>	//	キーボードからキーを受け取るためconfig
#include <time.h>	//	乱数を使うため
#include <windows.h>//	カーソルを移動させるため


//	----------マップの限界の広さ----------
//	＊＊＊(Xは奇数にして5 <= X	になるようにする)＊＊＊
//	Aの2乗の広さまでになる

#define A 103

//	--------------------------------

//	マップ生成の変数
int map[A][A];	//	マップデータ
int x = 17;	//	マップの広さ7 <= x <= A

			//			自動生成迷路
			//	カーソルを動かす
void moveCursor(int x, int y) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hCons, pos);
}

void colourMozi(const char mozi[], int colour) {
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	if (colour) {
		SetConsoleTextAttribute(hCons, colour);
	}
	printf("%s", mozi);
	SetConsoleTextAttribute(hCons, 0x07);
}

//	マップを画面に表示
void DispMap(void) {
	moveCursor(0, 0);	//	カーソルを一番左上に持っていく

						//	マップを表示する
	for (int a = 0; a < x; a++) {
		for (int b = 0; b < x; b++) {
			switch (map[a][b]) {
			case 0:
				printf(" ");
				break;
			case 1:
				printf("#");
				break;
			case 2:
				colourMozi("P", 3);
				break;
			case 3:
				colourMozi("G", 13);
				break;
			}
		}
		for (int i = 0; i < (49 - x); i++) {
			printf(" ");
		}
		printf("\n");
	}

	//	操作方法
	colourMozi("     P", 3);
	printf(" : 「プレイヤー」 ");
	colourMozi("G", 13);
	printf(" : 「ゴール」\n");
	printf("     方向キー : 「移動」     スペースキー : 「メニュー」");
}

void SelectMenu(int menu, int *select) {
	select[0] = 0;
	char key = NULL;
	char menu_select[4];
	int i = 0;
	int limit_x = 49;	//	実際の大きさの＋２大きい

	system("cls");
	switch (menu) {
	case 0:
		while (i == 0) {
			moveCursor(0, 0);
			switch (select[0]) {
			case 0:
				menu_select[0] = '>';
				menu_select[1] = ' ';
				menu_select[2] = ' ';
				menu_select[3] = ' ';
				break;
			case 1:
				menu_select[0] = ' ';
				menu_select[1] = '>';
				menu_select[2] = ' ';
				menu_select[3] = ' ';
				break;
			case 2:
				menu_select[0] = ' ';
				menu_select[1] = ' ';
				menu_select[2] = '>';
				menu_select[3] = ' ';
				break;
			case 3:
				menu_select[0] = ' ';
				menu_select[1] = ' ';
				menu_select[2] = ' ';
				menu_select[3] = '>';
				break;
			}

			printf("\n");
			printf("\n");
			colourMozi("  ＊＊＊＊＊ 自動生成迷路 ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊", 2);
			printf("\n");
			printf("\n");
			printf("     %c     マップを作る\n     %c     マップの広さ %d * %d          \n     %c     マップの生成を見る", menu_select[0], menu_select[1], (x - 2), (x - 2), menu_select[2]);
			if (select[1]) {
				printf(" OFF   \n");
			}
			else {
				printf(" ON    \n");
			}
			printf("     %c     終了する", menu_select[3]);

			printf("\n");
			printf("\n");
			printf("     方向キー : 「選択」 スペースキー : 「決定」                  ");
			printf("\n                                                                     ");
			colourMozi("\n  ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊", 2);

			key = _getch();

			switch (key) {	//	何が押されたか
			case 0x48:	//	上の場合
				if (!(select[0] <= 0)) {
					select[0]--;
				}
				else {
					select[0] = 3;
				}
				break;
			case 0x50:	//	下の場合
				if (!(select[0] >= 3)) {
					select[0]++;
				}
				else {
					select[0] = 0;
				}
				break;
			case ' ':
				switch (select[0]) {
				case 0:
					i = 1;
					break;
				case 1:	//	マップの広さを決める
					while (i == 0) {
						moveCursor(0, 0);
						printf("\n");
						printf("\n");
						colourMozi("  ＊＊＊＊＊ 自動生成迷路 ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊", 2);
						printf("\n");
						printf("\n");
						printf("           マップを作る\n     >     マップの広さ %d *(かける) %d  \n           マップの生成を見る", (x - 2), (x - 2));
						if (select[1]) {
							printf(" OFF   \n");
						}
						else {
							printf(" ON    \n");
						}
						printf("           終了する");
						printf("\n");
						printf("\n");
						printf("     方向キー : 「↑ 増やす」「↓ 減らす」 スペースキー : 「決定」");
						printf("\n     ＊マップの広さは最小で 5 *(かける) 5 最大で %d *(かける) %d です", (limit_x - 2), (limit_x - 2));

						key = _getch();
						switch (key) {	//	何が押されたか
						case 0x48:	//	上の場合
							if (x < limit_x) {
								x = x + 2;
							}
							break;
						case 0x50:	//	下の場合
							if (x > 7) {
								x = x - 2;
							}
							break;
						case ' ':
							i = 1;
							break;
						case 0x1b:
							limit_x = A - 2;
							break;
						}
					}
					i = 0;
					break;
				case 2:	//	マップの生成を見るかどうか
					while (i == 0) {
						moveCursor(0, 0);
						printf("\n");
						printf("\n");
						colourMozi("  ＊＊＊＊＊ 自動生成迷路 ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊", 2);
						printf("\n");
						printf("\n");
						printf("           マップを作る\n           マップの広さ %d * %d\n     >     マップの生成を見る", (x - 2), (x - 2));
						if (select[1]) {
							printf(" OFF   \n");
						}
						else {
							printf(" ON   \n");
						}
						printf("           終了する");
						printf("\n");
						printf("\n");
						printf("     方向キー : 「↑ ON」「↓ OFF」 スペースキー : 「決定」");

						key = _getch();
						switch (key) {	//	何が押されたか
						case 0x48:	//	上の場合
							if (select[1] != 0) {
								select[1] = 0;
							}
							break;
						case 0x50:	//	下の場合
							if (select[1] != 1) {
								select[1] = 1;
							}
							break;
						case ' ':
							i = 1;
							break;
						}

					}
					i = 0;
					break;
				case 3:	//	ゲームを終了する
					select[0] = 2;
					i = 1;
					break;
				}
				break;
			}
		}
		return;
		break;

	case 1:
		while (i == 0) {
			moveCursor(0, 0);
			switch (select[0]) {	//	何が選択されたか
			case 0:	//	ゲームに戻る
				menu_select[0] = '>';
				menu_select[1] = ' ';
				menu_select[2] = ' ';
				break;
			case 1:	//	マップを作り直す
				menu_select[0] = ' ';
				menu_select[1] = '>';
				menu_select[2] = ' ';
				break;
			case 2:	//	ゲームを終了する
				menu_select[0] = ' ';
				menu_select[1] = ' ';
				menu_select[2] = '>';
				break;
			}
			printf("\n");
			printf("\n");
			colourMozi("  ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊", 2);
			printf("\n");
			printf("\n");
			printf("     %c     迷路に戻る\n     %c     マップを作り直す\n     %c     終了する", menu_select[0], menu_select[1], menu_select[2]);
			printf("\n");
			printf("\n");
			printf("     方向キー : 「選択」 スペースキー : 「決定」");
			colourMozi("\n\n  ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊", 2);

			key = _getch();
			switch (key) {	//	何が押されたか
			case 0x48:	//	上の場合
				if (!(select[0] <= 0)) {
					select[0]--;
				}
				else {
					select[0] = 2;
				}
				break;
			case 0x50:	//	下の場合
				if (!(select[0] >= 2)) {
					select[0]++;
				}
				else {
					select[0] = 0;
				}
				break;
			case ' ':
				switch (select[0]) {	//	何が決定されたか
				case 0:	//	ゲームに戻る
					system("cls");
					i = 1;
					break;
				case 1:	//	マップを作り直す
					i = 1;
					break;
				case 2:	//	ゲームを終了する
					i = 1;
					break;
				}
				break;
			}
		}
		return;
		break;
	}
}

//	----------マップの生成----------
int DecideDirection(int *saveDirection, int *p_point) {
	int direction = 0;
	srand((*p_point + 1) * (unsigned)time(NULL));	//	乱数の種を生成

	if (saveDirection[4] == 0) {
		direction = rand() % 4 + 1;	//	方向を決める
		saveDirection[5] = 1;
	}
	else {
		if (saveDirection[5]) {
			direction = rand() % 3 + 1;
			if (direction == (((saveDirection[4] + 1) % 4) + 1)) {
				direction = 4;
			}
		}
		else {
			direction = rand() % 2 + 1;

			switch (10 - saveDirection[4] - (((saveDirection[4] + 1) % 4) + 1)) {
			case 5:
				if (saveDirection[4] == 1 || saveDirection[4] == 4) {
					if (direction == 1) {
						direction = 3;
					}
				}
				else if (saveDirection[4] == 2 || saveDirection[4] == 3) {
					if (direction == 2) {
						direction = 4;
					}
				}
				break;
			case 6:
				if (direction == 1) {
					direction = 4;
				}
				break;
			case 4:
				if (direction == 2) {
					direction = 3;
				}
				break;
			case 7:
				if (direction == 1) {
					direction = 3;
				}
				else {
					direction = 4;
				}
				break;
			}
		}
	}
	return direction;
}

int AgainDecideDirection(int *saveDirection, int direction) {
	saveDirection[0] = saveDirection[0] + 1;
	saveDirection[saveDirection[0]] = direction;

	srand((unsigned)time(NULL));
	int random = rand();

	switch (saveDirection[0]) {
	case 1:
		if (saveDirection[5]) {
			return (10 - saveDirection[1] - saveDirection[4] - (((saveDirection[4] + 1) % 4) + 1));
		}
		else {
			switch (10 - saveDirection[1] - (((saveDirection[4] + 1) % 4) + 1)) {
			case 3:
				if (saveDirection[4] == 1 || saveDirection[4] == 2) {
					return saveDirection[4] * 2 % 3;
				}
				else {
					return random % 2 + 1;
				}
				break;
			case 5:
				if (saveDirection[1] == 1 || saveDirection[1] == 4) {
					if (saveDirection[4] == 2 || saveDirection[4] == 3) {
						return (saveDirection[4] - 1) * 3 % 4;
					}
					else {
						return random % 2 + 2;
					}
				}
				else if (saveDirection[1] == 2 || saveDirection[1] == 3) {
					if (saveDirection[4] == 1 || saveDirection[4] == 4) {
						return 4 * saveDirection[4] % 15;
					}
					else {
						return (random % 2 + 1) * (random % 2 + 1);
					}
				}
				break;
			case 4:
				if (saveDirection[4] == 1 || saveDirection[4] == 3) {
					return (saveDirection[4] * saveDirection[4] + 3) % 11;
				}
				else {
					return (random % 2 + 1) * (random % 2 + 1) - (random % 2);
				}
			case 6:
				if (saveDirection[4] == 2 || saveDirection[4] == 4) {
					return saveDirection[4] * saveDirection[4] % 15;
				}
				else {
					return (random % 2 + 2) + random % 2;
				}
				break;
			case 7:
				if (saveDirection[4] == 3 || saveDirection[4] == 4) {
					return (saveDirection[4] - 2) * 4 % 5;
				}
				else {
					return random % 2 + 3;
				}
			}
			break;
		}
	case 2:
		return (10 - saveDirection[1] - saveDirection[2] - (((saveDirection[4] + 1) % 4) + 1));
		break;
	}
	return saveDirection[1];
}

void InBranchPoint(int direction, int *p_point, int *Branch, int *branchpoint) {
	switch (direction) {
	case 1:	//	上の場合
		branchpoint[0] = Branch[(*p_point - 1)] - 2;
		branchpoint[1] = Branch[(*p_point - 1) + ((A - 2) * (A - 2))];
		break;
	case 2:	//	右の場合
		branchpoint[0] = Branch[(*p_point - 1)];
		branchpoint[1] = Branch[(*p_point - 1) + ((A - 2) * (A - 2))] + 2;
		break;
	case 3:	//	下の場合
		branchpoint[0] = Branch[(*p_point - 1)] + 2;
		branchpoint[1] = Branch[(*p_point - 1) + ((A - 2) * (A - 2))];
		break;
	case 4: //	左の場合
		branchpoint[0] = Branch[(*p_point - 1)];
		branchpoint[1] = Branch[(*p_point - 1) + ((A - 2) * (A - 2))] - 2;
		break;
	default:	//	初回の場合
		while (1) {
			srand((unsigned)time(NULL));	//	乱数の種を生成

			branchpoint[0] = (rand() % ((x - 1) / 2 - 2) + 2) * 2;
			branchpoint[1] = (rand() % ((x - 1) / 2 - 2) + 2) * 2;

			if ((branchpoint[0] % 2) == 0 && (branchpoint[1] % 2) == 0) {
				map[branchpoint[0]][branchpoint[1]] = 0;
				break;
			}
		}
	}
}

int DigDirection(int direction, int *p_point, int *select, int *Branch) {	//	掘る方向を決める
	int branchpoint[2] = { 0, 0 };	//	マップの座標
	int saveDirection[6] = { 0,0,0,0,direction, 0 };

	//	前回の座標を入れる
	InBranchPoint(direction, p_point, Branch, branchpoint);

	direction = DecideDirection(saveDirection, p_point);

	while (1) {
		switch (direction) {
		case 1:	//	上の場合
			if (map[branchpoint[0] - 2][branchpoint[1]] == 0) {	//	2マス上が空白だった場合
				direction = AgainDecideDirection(saveDirection, direction);
			}
			else {
				Branch[*p_point] = branchpoint[0];	//	分岐点の座標を
				Branch[*p_point + ((A - 2) * (A - 2))] = branchpoint[1];	//	Branchに入れる
				*p_point = *p_point + 1;	//	曲がった回数 + 1
				return direction;
			}
			break;
		case 2:	//	右の場合
			if (map[branchpoint[0]][branchpoint[1] + 2] == 0) {	//	2マス右が空白だった場合
				direction = AgainDecideDirection(saveDirection, direction);
			}
			else {
				Branch[*p_point] = branchpoint[0];	//	分岐点の座標を
				Branch[*p_point + ((A - 2) * (A - 2))] = branchpoint[1];	//	Branchに入れる
				*p_point = *p_point + 1;	//	曲がった回数 + 1
				return direction;
			}
			break;
		case 3:	//	下の場合
			if (map[branchpoint[0] + 2][branchpoint[1]] == 0) {	//	2マス下が空白だった場合
				direction = AgainDecideDirection(saveDirection, direction);
			}
			else {
				Branch[*p_point] = branchpoint[0];	//	分岐点の座標を
				Branch[*p_point + ((A - 2) * (A - 2))] = branchpoint[1];	//	Branchに入れる
				*p_point = *p_point + 1;	//	曲がった回数 + 1
				return direction;
			}
			break;
		case 4:	//	左の場合
			if (map[branchpoint[0]][branchpoint[1] - 2] == 0) {	//	2マス左が空白だった場合
				direction = AgainDecideDirection(saveDirection, direction);
			}
			else {
				Branch[*p_point] = branchpoint[0];	//	分岐点の座標を
				Branch[*p_point + ((A - 2) * (A - 2))] = branchpoint[1];	//	Branchに入れる
				*p_point = *p_point + 1;	//	曲がった回数 + 1
				return direction;
			}
			break;
		}



		if (saveDirection[0] == 3) {	//	どの方向にも行けなかったら
			if (*p_point > 0) {
				*p_point = *p_point - 1;	//	前回曲がった回数にする
				branchpoint[0] = Branch[*p_point];	//	座標を
				branchpoint[1] = Branch[*p_point + ((A - 2) * (A - 2))];	//	前回のにする
				direction = DecideDirection(saveDirection, p_point);	//	方向を決めなおす
				saveDirection[4] = direction;
				saveDirection[0] = 0;
			}
			else {
				return 0;	//	マップ生成を終了する
			}
		}

	}

}

int Dig(int direction, int *p_point, int *select, int *Branch) {	//	掘る
	int a = Branch[(*p_point - 1)];	//	現在の座標を
	int b = Branch[(*p_point - 1) + ((A - 2) * (A - 2))];	//	入れる

	switch (direction) {
	case 1:	//	上の場合
		map[a - 1][b] = 0;	//	上二つを
		map[a - 2][b] = 0;	//	空白にする
		break;
	case 2:	//	右の場合
		map[a][b + 1] = 0;	//	右二つを
		map[a][b + 2] = 0;	//	空白にする
		break;
	case 3:	//	下の場合
		map[a + 1][b] = 0;	//	下二つを
		map[a + 2][b] = 0;	//	空白にする
		break;
	case 4:	//	左の場合
		map[a][b - 1] = 0;	//	左二つを
		map[a][b - 2] = 0;	//	空白にする
		break;
	}

	if (!select[1]) {
		DispMap();	//	迷路の生成をプレイヤーに見せる
		colourMozi("\n     ＊＊＊スキップする場合はスペースキーを押してください＊＊＊", 0x0c);
	}
	return direction;
}

void ClearMap(int *Branch) {
	//	Branchの初期化
	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < (x * x); b++) {
			Branch[(a * ((A - 2) * (A - 2))) + b] = 0;
		}
	}
	//	mapの初期化
	for (int a = 0; a < x; a++) {
		for (int b = 0; b < x; b++) {
			if (a == 0 || b == 0 || b == (x - 1) || a == (x - 1)) {	//	マップの外側を空白にする
				map[a][b] = 0;
			}
			else {	//	マップ初期化
				map[a][b] = 1;
			}
		}
	}
}

void GenerateMap(int *select, int *Branch) {	//マップの初期化と生成の実行
	system("cls");
	//	マップの初期化
	ClearMap(Branch);
	//	マップの生成

	int direction = 0;	//	曲がる方向
	int point = 0;	//	曲がった回数

	while (1) {
		//	掘る方向を決める
		direction = DigDirection(direction, &point, select, Branch);
		//	掘る
		direction = Dig(direction, &point, select, Branch);

		if (_kbhit() && _getch() == ' ') {	//	スペースキーを押したか確認
			select[1] = 2;	//	プレイヤーにマップの生成を見せるのをやめる
		}

		if (direction == 0) {	//	マップが完成したらループを抜ける
			if (select[1]) {
				select[1] = 0;
			}
			break;
		}
	}
}

//	プレイヤーの移動
int Player(int *p_a, int *p_b) {
	char key;

	while (1) {
		key = _getch();
		switch (key) {
		case 0x48:	//	上の場合
			if (map[*p_a - 1][*p_b] != 1) {
				map[*p_a][*p_b] = 0;
				*p_a = *p_a - 1;
				map[*p_a][*p_b] = 2;
				return 0;
			}
			break;
		case 0x4D:	//	右の場合
			if (map[*p_a][*p_b + 1] != 1) {
				map[*p_a][*p_b] = 0;
				*p_b = *p_b + 1;
				map[*p_a][*p_b] = 2;
				return 0;
			}
			break;
		case 0x4B:	//	左の場合
			if (map[*p_a][*p_b - 1] != 1) {
				map[*p_a][*p_b] = 0;
				*p_b = *p_b - 1;
				map[*p_a][*p_b] = 2;
				return 0;
			}
			break;
		case 0x50:	//	下の場合
			if (map[*p_a + 1][*p_b] != 1) {
				map[*p_a][*p_b] = 0;
				*p_a = *p_a + 1;
				map[*p_a][*p_b] = 2;
				return 0;
			}
			break;
		case ' ':
			return 1;
			break;
		}
	}
}

//	ゴールを決める
void Goal(int *p_Ga, int *p_Gb, int *Branch) {
	srand((unsigned)time(NULL));	//	乱数の種を生成
	while (1) {
		*p_Ga = rand() % x;
		*p_Gb = rand() % x;
		if (map[*p_Ga][*p_Gb] == 0 && *p_Ga != Branch[0] && *p_Gb != Branch[((A - 2) * (A - 2))]) {	//	そこが空白でプレイヤーの初期位置じゃなかったら
																									//	マップの一番外側だったら
			if (*p_Gb == 2 || *p_Gb == (x - 3)) {
				if (Branch[0] <= (x / 2) && *p_Ga >= (x / 2) && *p_Ga == (x - 3)) {
					map[*p_Ga][*p_Gb] = 3;	//	ゴールを作る
					break;
				}
				else if (Branch[0] >= (x / 2) && *p_Ga <= (x / 2) && *p_Ga == 2) {
					map[*p_Ga][*p_Gb] = 3;	//	ゴールを作る
					break;
				}
			}
		}
	}
}

//	プレイヤーのいる場所がゴールかどうか
int IsThereGoal(int *p_Ga, int *p_Gb, int *p_a, int *p_b) {
	if (*p_a == *p_Ga && *p_b == *p_Gb) {
		return 1;
	}
	return 0;
}

//	実行部分
int main(void) {
	int Branch[2][((A - 2) * (A - 2))];	//	分岐点の記録
	int select[2] = { 0, 0 };
	char key = NULL;

	for (int i = 0; i < 2;) {
		SelectMenu(0, select);
		i = select[0];
		if (i < 2) {
			//	マップの生成
			GenerateMap(select, Branch[0]);
			DispMap();
			printf("\n                                                               ");

			int a = Branch[0][0];	//	プレイヤー
			int b = Branch[1][0];	//	の座標
			int Ga, Gb = 0;	//	ゴールの座標

			map[a][b] = 2;
			//	ゴールを作る
			Goal(&Ga, &Gb, Branch[0]);

			while (i == 0) {
				//	画面にマップを表示
				DispMap();
				//	プレイヤーの移動
				if (Player(&a, &b)) {
					SelectMenu(1, select);
					i = select[0];
				}

				if (IsThereGoal(&Ga, &Gb, &a, &b)) {	//	プレイヤーがゴールについたかどうか
					colourMozi("\n\n     GOAL!     ＊＊＊メニューに戻るにはスペースキーを押します＊＊＊", 2);
					key = NULL;
					while (key != ' ') {
						key = _getch();
					}
					i = 1;
				}

			}
		}
	}
	return (0);
}
