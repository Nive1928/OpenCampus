#include <DxLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int player, enemy, shot;
int px = 288;
int ex = 0, es= 8;
int sx, sy;
int r;
bool sf = false;
int score = 0;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	player = LoadGraph("./game_file/player.bmp");
	enemy = LoadGraph("./game_file/12.bmp");
	shot = LoadGraph("./game_file/redbullet.bmp");

	while (!ProcessMessage()) {
		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_A)) {
			px -= 8;
			if (px < 0) px = 0;
		}
		if (CheckHitKey(KEY_INPUT_D)) {
			px += 8;
			if (px > 640 - 64) px = 640 - 64;
		}
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			if (!sf) {
				sf = true;
				sx = px + 24;
				sy = 400;
			}
		}

		ex += es;
		if (ex <= 0 || ex >= 640 - 64) es = -es;

		if (sf) {
			sy -= 16;
			if (sy < 0) sf = false;
		}

		if (sf) {
			if (sx + 16 > ex && sx < ex + 64 && sy + 16 > 16 && sy < 16 + 64) {
				sf = false;
				r = GetRand( 360 );
				ex = 0;
				es = 8;
				score += 100;
			}
		}


		if (sf) DrawGraph(sx, sy, shot, FALSE);
		DrawGraph(px, 400, player, FALSE);
		DrawGraph(ex, 16, enemy, FALSE);
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SCORE : %d", score);
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}