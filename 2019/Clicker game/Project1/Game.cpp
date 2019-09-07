#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DxLib.h"


#define SCREEN_W	800		// 画面の横幅
#define SCREEN_H	800		// 画面の縦幅

int Key[256];	//キー押されてるか判定
int gpUpdateKey() {
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		}
		else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}


int gold[27][30] = { 0 };
int i, j, a, m = 0;
int sh = 0;

int level[20][5] = { 0 };
int le_s, le_k = 0;

int GC[27][3] = { 0 };
int GC_s, GC_c = 0;

int kakeru = 0;
int ka_ka = 0;

int senntaku_x = 0;		//選択画面ｘ
int senntaku_y = 100;	//選択画面y
int modoru_x = 70;		//戻るx
int modoru_y = 40;		//戻るy
int Gold_x = 0;	//ＧＯＬＤ表記座標ｘ
int Gold_y = 0;	//ＧＯＬＤ表記座標ｙ
int shop_i_x = 50;	//ショップアイテム座標ｘ
int shop_i_y = 150;	//ショップアイテム座標ｙ
int SU_a_x = 340;		//音量
int SU_b_x = 340;		//音量

int time_a, time_b = 0;
int x, y, Mouse, osu, spe;
int hack_i, hack_n, key = 0;
int ha_i, ha_n, ha_y = 0;
int basyo = 0;
int END = 0;
int BGM = 0;
int BGM_a, BGM_b;
int BGM_V = 70;
int SU_kettei;
int SU_V = 70;
int SU_V_K = 0;

int SU_kurikku_a;
int SU_kurikku_b;
int SU_kau;
int SU_sippai;

int shop_x_x = 750;
int shop_x_y = 750;
int shop_x_t = 0;
int shop_m = 0;
int shop_m_t = 0;
int shop_h = 0;
int shop_h_t = 0;
int shop_u_hyouzi = 0;
int shop_u_hyouzi_t = 0;

int R_a_a, G_a_a, B_a_a = 0;
int R_a_a_T, G_a_a_T, B_a_a_T = 0;
int R_b_a, G_b_a, B_b_a = 0;
int R_b_a_T, G_b_a_T, B_b_a_T = 0;
int R_c_a, G_c_a, B_c_a = 0;
int R_c_a_T, G_c_a_T, B_c_a_T = 0;
int R_d_a, G_d_a, B_d_a = 0;
int R_d_a_T, G_d_a_T, B_d_a_T = 0;
int R_e_a, G_e_a, B_e_a = 0;
int R_e_a_T, G_e_a_T, B_e_a_T = 0;
int R_f_a, G_f_a, B_f_a = 0;
int R_f_a_T, G_f_a_T, B_f_a_T = 0;

int R, G, B = 0;
int R_T, G_T, B_T = 0;
int R_a, G_a, B_a = 0;
int R_a_T, G_a_T, B_a_T = 0;
int R_b, G_b, B_b = 0;
int R_b_T, G_b_T, B_b_T = 0;
int R_c, G_c, B_c = 0;
int R_c_T, G_c_T, B_c_T = 0;
int R_d, G_d, B_d = 0;
int R_d_T, G_d_T, B_d_T = 0;
int R_e, G_e, B_e = 0;
int R_e_T, G_e_T, B_e_T = 0;
int R_f, G_f, B_f = 0;
int R_f_T, G_f_T, B_f_T = 0;
int R_g, G_g, B_g = 0;
int R_g_T, G_g_T, B_g_T = 0;

int shop_u_a = 0;
int shop_u_a_t = 0;
int shop_u_b = 0;
int shop_u_b_t = 0;
int shop_u_c = 0;
int shop_u_c_t = 0;
int shop_u_d = 0;
int shop_u_d_t = 0;
int shop_u_e = 0;
int shop_u_e_t = 0;
int shop_u_f = 0;
int shop_u_f_t = 0;
int shop_u_g = 0;
int shop_u_g_t = 0;

int mozi = 60;
int hk = 0;

int k = 0;


//gold整理
void seiri() {
	for (j = 0; j < 30; j++) {
		for (i = 0; i < 27; i++) {
			if (gold[i][j] >= 100000000) {
				gold[i][j] = gold[i][j] - 100000000;
				gold[i + 1][j] = gold[i + 1][j] + 1;
			}
		}
	}
}

//leve整理
void lr_seri() {
	for (le_s = 0; le_s < 20; le_s++) {
		for (le_k = 0; le_k < 5; le_k++) {
			if (level[le_s][le_k] >= 100000000) {
				level[le_s][le_k] = level[le_s][le_k] - 100000000;
				level[le_s + 1][le_k] = level[le_s + 1][le_k] + 1;
			}
		}
	}
}

//購入時GOLDマイナス
void goldmainasu() {
	m = 0;
	for (i = 0; i < 27; i++) {
		gold[i][1] = gold[i][0];
	}
	for (i = 0; i < 27; i++) {
		if (i < 26) {
			gold[i + 1][1] = gold[i + 1][1] - 1;
			gold[i][1] = gold[i][1] + 100000000;
		}
		gold[i][1] = gold[i][1] - gold[i][sh];
		if (gold[i][1] >= 100000000) {
			gold[i][1] = gold[i][1] - 100000000;
			gold[i + 1][1] = gold[i + 1][1] + 1;
		}
	}
	for (i = 0; i < 27; i++) {
		if (gold[i][1] < 0) {
			m = 1;
		}
	}
}

//クリックして増えるGold
void M_GOLD() {
	for (i = 0; i < 27; i++) {
		gold[i][0] = gold[i][0] + gold[i][2];
	}
	seiri();

	kakeru = rand() % 1000;
	if (kakeru <= level[6][0] * 10) {
		for (i = 0; i < 27; i++) {
			gold[i][0] = gold[i][0] + gold[i][2];
		}
		seiri();
	}
	kakeru = 0;
}

//1秒あたりに増えるGold
void F_GOLD() {
	for (i = 0; i < 27; i++) {
		gold[i][0] = gold[i][0] + gold[i][3];
	}
	seiri();

	kakeru = rand() % 1000;
	if (kakeru <= level[7][0] * 10) {
		for (i = 0; i < 27; i++) {
			gold[i][0] = gold[i][0] + gold[i][3];
		}
		seiri();
	}
	kakeru = 0;

	kakeru = rand() % 1000;
	if (kakeru <= level[8][0] * 10) {
		for (ka_ka = 0; ka_ka < 10; ka_ka++) {
			for (i = 0; i < 27; i++) {
				gold[i][0] = gold[i][0] + gold[i][3];
			}
			seiri();
		}
	}
	kakeru = 0;

	kakeru = rand() % 1000;
	if (kakeru <= level[9][0] * 10) {
		for (ka_ka = 0; ka_ka < 100; ka_ka++) {
			for (i = 0; i < 27; i++) {
				gold[i][0] = gold[i][0] + gold[i][3];
			}
			seiri();
		}
	}
	kakeru = 0;

	kakeru = rand() % 1000;
	if (kakeru <= level[10][0] * 10) {
		for (ka_ka = 0; ka_ka < 1000; ka_ka++) {
			for (i = 0; i < 27; i++) {
				gold[i][0] = gold[i][0] + gold[i][3];
			}
			seiri();
		}
	}
	kakeru = 0;

	kakeru = rand() % 1000;
	if (kakeru <= level[11][0] * 10) {
		for (ka_ka = 0; ka_ka < 10000; ka_ka++) {
			for (i = 0; i < 27; i++) {
				gold[i][0] = gold[i][0] + gold[i][3];
			}
			seiri();
		}
	}
	kakeru = 0;
}

//Gold表示
void GOLD() {

	SetFontSize(mozi);                    //文字サイズをmoziに変更

	if (gold[26][hk] > 0) {
		DrawFormatString(Gold_x, Gold_y, GetColor(GC[26][0], GC[26][1], GC[26][2]), "%9d Z GOLD", gold[26][hk]);
	}
	else if (gold[26][hk] == 0) {
		if (gold[25][hk] > 0) {
			DrawFormatString(Gold_x, Gold_y, GetColor(GC[25][0], GC[25][1], GC[25][2]), "%9d Y GOLD", gold[25][hk]);
		}
		else if (gold[25][hk] == 0) {
			if (gold[24][hk] > 0) {
				DrawFormatString(Gold_x, Gold_y, GetColor(GC[24][0], GC[24][1], GC[24][2]), "%9d X GOLD", gold[24][hk]);
			}
			else if (gold[24][hk] == 0) {
				if (gold[23][hk] > 0) {
					DrawFormatString(Gold_x, Gold_y, GetColor(GC[23][0], GC[23][1], GC[23][2]), "%9d W GOLD", gold[23][hk]);
				}
				else if (gold[23][hk] == 0) {
					if (gold[22][hk] > 0) {
						DrawFormatString(Gold_x, Gold_y, GetColor(GC[22][0], GC[22][1], GC[22][2]), "%9d V GOLD", gold[22][hk]);
					}
					else if (gold[22][hk] == 0) {
						if (gold[21][hk] > 0) {
							DrawFormatString(Gold_x, Gold_y, GetColor(GC[21][0], GC[21][1], GC[21][2]), "%9d U GOLD", gold[21][hk]);
						}
						else if (gold[21][hk] == 0) {
							if (gold[20][hk] > 0) {
								DrawFormatString(Gold_x, Gold_y, GetColor(GC[20][0], GC[20][1], GC[20][2]), "%9d T GOLD", gold[20][hk]);
							}
							else if (gold[20][hk] == 0) {
								if (gold[19][hk] > 0) {
									DrawFormatString(Gold_x, Gold_y, GetColor(GC[19][0], GC[19][1], GC[19][2]), "%9d S GOLD", gold[19][hk]);
								}
								else if (gold[19][hk] == 0) {
									if (gold[18][hk] > 0) {
										DrawFormatString(Gold_x, Gold_y, GetColor(GC[18][0], GC[18][1], GC[18][2]), "%9d R GOLD", gold[18][hk]);
									}
									else if (gold[18][hk] == 0) {
										if (gold[17][hk] > 0) {
											DrawFormatString(Gold_x, Gold_y, GetColor(GC[17][0], GC[17][1], GC[17][2]), "%9d Q GOLD", gold[17][hk]);
										}
										else if (gold[17][hk] == 0) {
											if (gold[16][hk] > 0) {
												DrawFormatString(Gold_x, Gold_y, GetColor(GC[16][0], GC[16][1], GC[16][2]), "%9d P GOLD", gold[16][hk]);
											}
											else if (gold[16][hk] == 0) {
												if (gold[15][hk] > 0) {
													DrawFormatString(Gold_x, Gold_y, GetColor(GC[15][0], GC[15][1], GC[15][2]), "%9d O GOLD", gold[15][hk]);
												}
												else if (gold[15][hk] == 0) {
													if (gold[14][hk] > 0) {
														DrawFormatString(Gold_x, Gold_y, GetColor(GC[14][0], GC[14][1], GC[14][2]), "%9d N GOLD", gold[14][hk]);
													}
													else if (gold[14][hk] == 0) {
														if (gold[13][hk] > 0) {
															DrawFormatString(Gold_x, Gold_y, GetColor(GC[13][0], GC[13][1], GC[13][2]), "%9d M GOLD", gold[13][hk]);
														}
														else if (gold[13][hk] == 0) {
															if (gold[12][hk] > 0) {
																DrawFormatString(Gold_x, Gold_y, GetColor(GC[12][0], GC[12][1], GC[12][2]), "%9d L GOLD", gold[12][hk]);
															}
															else if (gold[12][hk] == 0) {
																if (gold[11][hk] > 0) {
																	DrawFormatString(Gold_x, Gold_y, GetColor(GC[11][0], GC[11][1], GC[11][2]), "%9d K GOLD", gold[11][hk]);
																}
																else if (gold[11][hk] == 0) {
																	if (gold[10][hk] > 0) {
																		DrawFormatString(Gold_x, Gold_y, GetColor(GC[10][0], GC[10][1], GC[10][2]), "%9d J GOLD", gold[10][hk]);
																	}
																	else if (gold[10][hk] == 0) {
																		if (gold[9][hk] > 0) {
																			DrawFormatString(Gold_x, Gold_y, GetColor(GC[9][0], GC[9][1], GC[9][2]), "%9d I GOLD", gold[9][hk]);
																		}
																		else if (gold[9][hk] == 0) {
																			if (gold[8][hk] > 0) {
																				DrawFormatString(Gold_x, Gold_y, GetColor(GC[8][0], GC[8][1], GC[8][2]), "%9d H GOLD", gold[8][hk]);
																			}
																			else if (gold[8][hk] == 0) {
																				if (gold[7][hk] > 0) {
																					DrawFormatString(Gold_x, Gold_y, GetColor(GC[7][0], GC[7][1], GC[7][2]), "%9d G GOLD", gold[7][hk]);
																				}
																				else if (gold[7][hk] == 0) {
																					if (gold[6][hk] > 0) {
																						DrawFormatString(Gold_x, Gold_y, GetColor(GC[6][0], GC[6][1], GC[6][2]), "%9d F GOLD", gold[6][hk]);
																					}
																					else if (gold[6][hk] == 0) {
																						if (gold[5][hk] > 0) {
																							DrawFormatString(Gold_x, Gold_y, GetColor(GC[5][0], GC[5][1], GC[5][2]), "%9d E GOLD", gold[5][hk]);
																						}
																						else if (gold[5][hk] == 0) {
																							if (gold[4][hk] > 0) {
																								DrawFormatString(Gold_x, Gold_y, GetColor(GC[4][0], GC[4][1], GC[4][2]), "%9d D GOLD", gold[4][hk]);
																							}
																							else if (gold[4][hk] == 0) {
																								if (gold[3][hk] > 0) {
																									DrawFormatString(Gold_x, Gold_y, GetColor(GC[3][0], GC[3][1], GC[3][2]), "%9d C GOLD", gold[3][hk]);
																								}
																								else if (gold[3][hk] == 0) {
																									if (gold[2][hk] > 0) {
																										DrawFormatString(Gold_x, Gold_y, GetColor(GC[2][0], GC[2][1], GC[2][2]), "%9d B GOLD", gold[2][hk]);
																									}
																									else if (gold[2][hk] == 0) {
																										if (gold[1][hk] > 0) {
																											DrawFormatString(Gold_x, Gold_y, GetColor(GC[1][0], GC[1][1], GC[1][2]), "%9d A GOLD", gold[1][hk]);
																										}
																										else if (gold[1][hk] == 0) {
																											DrawFormatString(Gold_x, Gold_y, GetColor(GC[0][0], GC[0][1], GC[0][2]), "%9d GOLD", gold[0][hk]);
																										}
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	mozi = 60;
	SetFontSize(mozi);                    //文字サイズを60に変更

}

//戻る
void modoru() {
	LoadGraphScreen(modoru_x, modoru_y, "画像/戻る.png", TRUE); // 画像を描画する
	if (x > modoru_x && x < modoru_x + 60 && y > modoru_y && y < modoru_y + 60) {
		if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
			PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
			osu = 1;
			basyo = 2;
		}
	}
}

//タイトル画面
void Title() {
	LoadGraphScreen(0, 0, "画像/タイトル.png", TRUE); //画像を描画する
		if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
			PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
			osu = 1;
			basyo = 2;
		}
}

//メイン画面
void Mein() {

	/*if (k == 0) {
		gold[1][0] = 99999999;
		k = 1;
	}*/

	shop_x_x = 750;
	shop_x_y = 750;

	LoadGraphScreen(000, 000, "画像/メイン画面1.png", TRUE); // 画像を描画する

	LoadGraphScreen(300, 150, "画像/クリック1.png", TRUE); // 画像を描画する
	LoadGraphScreen(150, 000, "画像/数表示.png", TRUE); // 画像を描画する
	LoadGraphScreen(senntaku_x, senntaku_y, "画像/選択肢.png", TRUE); // 画像を描画する

	//gold表示
	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = 000;
		GC[GC_s][1] = 255;
		GC[GC_s][2] = 000;
	}
	GC[26][0] = 255;
	GC[26][1] = 000;
	GC[26][2] = 000;
	GC[25][0] = 000;
	GC[25][1] = 000;
	GC[25][2] = 255;
	mozi = 70;
	hk = 0;
	Gold_x = 180;
	Gold_y = 0;
	GOLD();


	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && spe == 0) {
		PlaySoundMem(SU_kurikku_b, DX_PLAYTYPE_BACK);
		spe = 1;
		M_GOLD();
	}

	if (x > 300 && x < 700 && y > 150 && y < 550) { //画像が押されたら
		if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
			k = rand() % 2;
			if (k == 0) {
				PlaySoundMem(SU_kurikku_a, DX_PLAYTYPE_BACK);
			}
			else if (k == 1) {
				PlaySoundMem(SU_kurikku_b, DX_PLAYTYPE_BACK);
			}
			osu = 1;
			M_GOLD();
			
		}
	}

	if (x > senntaku_x && x < senntaku_x + 200) {
		if (y > senntaku_y && y < senntaku_y + 100) {	//ショップ
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				basyo = 3;
			}
		}
		else if (y > senntaku_y + 100 && y < senntaku_y + 200) {	//セーブ
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				basyo = 4;
			}
		}
		else if (y > senntaku_y + 200 && y < senntaku_y + 300) {	//ロード
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				basyo = 5;
			}
		}
		else if (y > senntaku_y + 300 && y < senntaku_y + 400) {	//設定
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				basyo = 6;
			}
		}
		else if (y > senntaku_y + 400 && y < senntaku_y + 500) {	//ゲーム終了
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				END = 1;
			}
		}
	}

}

//ショップ
void Shop() {
	LoadGraphScreen(000, 000, "画像/ショップ背景.png", TRUE); // 画像を描画する
	LoadGraphScreen(150, 000, "画像/数表示.png", TRUE); // 画像を描画する
	LoadGraphScreen(530, 735, "画像/右.png", TRUE); // 画像を描画する
	modoru();

	//gold表示
	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = 000;
		GC[GC_s][1] = 255;
		GC[GC_s][2] = 000;
	}
	GC[26][0] = 255;
	GC[26][1] = 000;
	GC[26][2] = 000;
	GC[25][0] = 000;
	GC[25][1] = 000;
	GC[25][2] = 255;
	mozi = 70;
	hk = 0;
	Gold_x = 180;
	Gold_y = 0;
	GOLD();


	if (x > 530 && x < 590 && y > 735 && y < 795) {
		if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
			PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
			shop_x_x = 750;
			shop_x_y = 750;
			osu = 1;
			basyo = 8;
		}
	}


	if (level[17][0] > 0 || level[17][1] > 0 || level[17][2] > 0 || level[17][3] > 0 || level[17][4] > 0) {
		LoadGraphScreen(600, 700, "画像/ショップ01.png", TRUE); // 画像を描画する
		LoadGraphScreen(shop_x_x, shop_x_y, "画像/ショップX.png", TRUE); // 画像を描画する
		shop_x_t = 1;
		if (x > 600 && x < 800 && y > 750 && y < 800) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				shop_x_x = 750;
				shop_x_y = 750;
				osu = 1;
				basyo = 7;
			}
		}
	}

	if (shop_x_x > 700 && shop_x_y > 700 && shop_x_t == 1) {
		shop_x_x = shop_x_x - 1;
		shop_x_y = shop_x_y - 1;
		shop_x_t = 0;
	}

	LoadGraphScreen(shop_i_x, shop_i_y, "画像/ショップアイテム1.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/ショップアイテム2.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/ショップアイテム3.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/ショップアイテム4.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/ショップアイテム5.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/ショップアイテム6.png", TRUE); // 画像を描画する

	
	for (GC_s = 0; GC_s < 27; GC_s++) {
			GC[GC_s][0] = 255;
			GC[GC_s][1] = 000;
			GC[GC_s][2] = 000;
	}
	hk = 10;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 155;
	GOLD();

	hk = 11;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 255;
	GOLD();

	hk = 12;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 355;
	GOLD();

	hk = 13;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 455;
	GOLD();
	
	hk = 14;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 555;
	GOLD();

	hk = 15;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 655;
	GOLD();


	SetFontSize(30);                    //文字サイズを30に変更
	if (level[0][4] > 0) {
		DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dD  +1", level[0][4]);
	}
	else if (level[0][4] == 0) {
		if (level[0][3] > 0) {
			DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dC  +1", level[0][3]);
		}
		else if (level[0][3] == 0) {
			if (level[0][2] > 0) {
				DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dB  +1", level[0][2]);
			}
			else if (level[0][2] == 0) {
				if (level[0][1] > 0) {
					DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dA  +1", level[0][1]);
				}
				else if (level[0][1] == 0) {
						DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5d   +1", level[0][0]);
				}
			}
		}
	}

	if (level[1][4] > 0) {
		DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dD  +10", level[1][4]);
	}
	else if (level[1][4] == 0) {
		if (level[1][3] > 0) {
			DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dC  +10", level[1][3]);
		}
		else if (level[1][3] == 0) {
			if (level[1][2] > 0) {
				DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dB  +10", level[1][2]);
			}
			else if (level[1][2] == 0) {
				if (level[1][1] > 0) {
					DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dA  +10", level[1][1]);
				}
				else if (level[1][1] == 0) {
					DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5d   +10", level[1][0]);
				}
			}
		}
	}

	if (level[2][4] > 0) {
		DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dD  +100", level[2][4]);
	}
	else if (level[2][4] == 0) {
		if (level[2][3] > 0) {
			DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dC  +100", level[2][3]);
		}
		else if (level[2][3] == 0) {
			if (level[2][2] > 0) {
				DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dB  +100", level[2][2]);
			}
			else if (level[2][2] == 0) {
				if (level[2][1] > 0) {
					DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dA  +100", level[2][1]);
				}
				else if (level[2][1] == 0) {
					DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5d   +100", level[2][0]);
				}
			}
		}
	}

	if (level[3][4] > 0) {
		DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dD  +1000", level[3][4]);
	}
	else if (level[3][4] == 0) {
		if (level[3][3] > 0) {
			DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dC  +1000", level[3][3]);
		}
		else if (level[3][3] == 0) {
			if (level[3][2] > 0) {
				DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dB  +1000", level[3][2]);
			}
			else if (level[3][2] == 0) {
				if (level[3][1] > 0) {
					DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dA  +1000", level[3][1]);
				}
				else if (level[3][1] == 0) {
					DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5d   +1000", level[3][0]);
				}
			}
		}
	}

	if (level[4][4] > 0) {
		DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dD  +10000", level[4][4]);
	}
	else if (level[4][4] == 0) {
		if (level[4][3] > 0) {
			DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dC  +10000", level[4][3]);
		}
		else if (level[4][3] == 0) {
			if (level[4][2] > 0) {
				DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dB  +10000", level[4][2]);
			}
			else if (level[4][2] == 0) {
				if (level[4][1] > 0) {
					DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dA  +10000", level[4][1]);
				}
				else if (level[4][1] == 0) {
					DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5d   +10000", level[4][0]);
				}
			}
		}
	}

	if (level[5][4] > 0) {
		DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dD  +100000", level[5][4]);
	}
	else if (level[5][4] == 0) {
		if (level[5][3] > 0) {
			DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dC  +100000", level[5][3]);
		}
		else if (level[5][3] == 0) {
			if (level[5][2] > 0) {
				DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dB  +100000", level[5][2]);
			}
			else if (level[5][2] == 0) {
				if (level[5][1] > 0) {
					DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dA  +100000", level[5][1]);
				}
				else if (level[5][1] == 0) {
					DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5d   +100000", level[5][0]);
				}
			}
		}
	}
	SetFontSize(60);                    //文字サイズを60に変更

	if (x > 50 && x < 750) {
		if (y > 150 && y < 230) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 10;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[0][2] = gold[0][2] + 1;
					gold[0][10] = gold[0][10] + 10;
					level[0][0] = level[0][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 250 && y < 330) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 11;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[0][3] = gold[0][3] + 10;
					gold[0][11] = gold[0][11] + 100;
					level[1][0] = level[1][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 350 && y < 430) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 12;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[0][3] = gold[0][3] + 100;
					gold[0][12] = gold[0][12] + 1000;
					level[2][0] = level[2][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 450 && y < 530) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 13;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[0][3] = gold[0][3] + 1000;
					gold[0][13] = gold[0][13] + 10000;
					level[3][0] = level[3][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 550 && y < 630) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 14;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[0][3] = gold[0][3] + 10000;
					gold[0][14] = gold[0][14] + 100000;
					level[4][0] = level[4][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 650 && y < 730) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 15;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[0][3] = gold[0][3] + 100000;
					gold[0][15] = gold[0][15] + 1000000;
					level[5][0] = level[5][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}

	}
}

//ショップ１
void shop_i() {
	LoadGraphScreen(000, 000, "画像/ショップ背景.png", TRUE); // 画像を描画する
	LoadGraphScreen(150, 000, "画像/数表示.png", TRUE); // 画像を描画する
	LoadGraphScreen(230, 735, "画像/左.png", TRUE); // 画像を描画する
	modoru();

	//gold表示
	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = 000;
		GC[GC_s][1] = 255;
		GC[GC_s][2] = 000;
	}
	GC[26][0] = 255;
	GC[26][1] = 000;
	GC[26][2] = 000;
	GC[25][0] = 000;
	GC[25][1] = 000;
	GC[25][2] = 255;
	mozi = 70;
	hk = 0;
	Gold_x = 180;
	Gold_y = 0;
	GOLD();


	if (x > 230 && x < 290 && y > 735 && y < 795) {
		if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
			PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
			shop_x_x = 750;
			shop_x_y = 750;
			osu = 1;
			basyo = 3;
		}
	}

	if (level[17][0] > 0 || level[17][1] > 0 || level[17][2] > 0 || level[17][3] > 0 || level[17][4] > 0) {
		LoadGraphScreen(600, 700, "画像/ショップ01.png", TRUE); // 画像を描画する
		LoadGraphScreen(shop_x_x, shop_x_y, "画像/ショップX.png", TRUE); // 画像を描画する
		shop_x_t = 1;
		if (x > 600 && x < 800 && y > 750 && y < 800) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				shop_x_x = 750;
				shop_x_y = 750;
				osu = 1;
				basyo = 7;
			}
		}
	}

	if (shop_x_x > 700 && shop_x_y > 700 && shop_x_t == 1) {
		shop_x_x = shop_x_x - 1;
		shop_x_y = shop_x_y - 1;
		shop_x_t = 0;
	}


	LoadGraphScreen(shop_i_x, shop_i_y, "画像/ショップアイテム7.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/ショップアイテム8.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/ショップアイテム9.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/ショップアイテム10.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/ショップアイテム11.png", TRUE); // 画像を描画する
	LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/ショップアイテム12.png", TRUE); // 画像を描画する


	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = 255;
		GC[GC_s][1] = 000;
		GC[GC_s][2] = 000;
	}
	hk = 4;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 155;
	GOLD();

	hk = 5;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 255;
	GOLD();

	hk = 6;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 355;
	GOLD();

	hk = 7;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 455;
	GOLD();

	hk = 8;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 555;
	GOLD();

	hk = 9;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 655;
	GOLD();


	SetFontSize(30);                    //文字サイズを30に変更
	if (level[12][4] > 0) {
		DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dD  +1A", level[12][4]);
	}
	else if (level[12][4] == 0) {
		if (level[12][3] > 0) {
			DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dC  +1", level[12][3]);
		}
		else if (level[12][3] == 0) {
			if (level[12][2] > 0) {
				DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dB  +1A", level[12][2]);
			}
			else if (level[12][2] == 0) {
				if (level[12][1] > 0) {
					DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5dA  +1A", level[12][1]);
				}
				else if (level[12][1] == 0) {
					DrawFormatString(445, 195, GetColor(255, 000, 000), "LV.%5d   +1A", level[12][0]);
				}
			}
		}
	}

	if (level[13][4] > 0) {
		DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dD  +1B", level[13][4]);
	}
	else if (level[13][4] == 0) {
		if (level[13][3] > 0) {
			DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dC  +1B", level[13][3]);
		}
		else if (level[13][3] == 0) {
			if (level[13][2] > 0) {
				DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dB  +1B", level[13][2]);
			}
			else if (level[13][2] == 0) {
				if (level[13][1] > 0) {
					DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5dA  +1B", level[13][1]);
				}
				else if (level[13][1] == 0) {
					DrawFormatString(445, 295, GetColor(255, 000, 000), "LV.%5d   +1B", level[13][0]);
				}
			}
		}
	}

	if (level[14][4] > 0) {
		DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dD  +1C", level[14][4]);
	}
	else if (level[14][4] == 0) {
		if (level[14][3] > 0) {
			DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dC  +1C", level[14][3]);
		}
		else if (level[14][3] == 0) {
			if (level[14][2] > 0) {
				DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dB  +1C", level[14][2]);
			}
			else if (level[14][2] == 0) {
				if (level[14][1] > 0) {
					DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5dA  +1C", level[14][1]);
				}
				else if (level[14][1] == 0) {
					DrawFormatString(445, 395, GetColor(255, 000, 000), "LV.%5d   +1C", level[14][0]);
				}
			}
		}
	}

	if (level[15][4] > 0) {
		DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dD  +1D", level[15][4]);
	}
	else if (level[15][4] == 0) {
		if (level[3][3] > 0) {
			DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dC  +1D", level[15][3]);
		}
		else if (level[15][3] == 0) {
			if (level[15][2] > 0) {
				DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dB  +1D", level[15][2]);
			}
			else if (level[15][2] == 0) {
				if (level[15][1] > 0) {
					DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5dA  +1D", level[15][1]);
				}
				else if (level[15][1] == 0) {
					DrawFormatString(445, 495, GetColor(255, 000, 000), "LV.%5d   +1D", level[15][0]);
				}
			}
		}
	}

	if (level[16][4] > 0) {
		DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dD  +1E", level[16][4]);
	}
	else if (level[16][4] == 0) {
		if (level[16][3] > 0) {
			DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dC  +1E", level[16][3]);
		}
		else if (level[16][3] == 0) {
			if (level[16][2] > 0) {
				DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dB  +1E", level[16][2]);
			}
			else if (level[16][2] == 0) {
				if (level[16][1] > 0) {
					DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5dA  +1E", level[16][1]);
				}
				else if (level[16][1] == 0) {
					DrawFormatString(445, 595, GetColor(255, 000, 000), "LV.%5d   +1E", level[16][0]);
				}
			}
		}
	}

	if (level[17][4] > 0) {
		DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dD  +1F", level[17][4]);
	}
	else if (level[17][4] == 0) {
		if (level[17][3] > 0) {
			DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dC  +1F", level[17][3]);
		}
		else if (level[17][3] == 0) {
			if (level[17][2] > 0) {
				DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dB  +1F", level[17][2]);
			}
			else if (level[17][2] == 0) {
				if (level[17][1] > 0) {
					DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5dA  +1F", level[17][1]);
				}
				else if (level[17][1] == 0) {
					DrawFormatString(445, 695, GetColor(255, 000, 000), "LV.%5d   +1F", level[17][0]);
				}
			}
		}
	}
	SetFontSize(60);                    //文字サイズを60に変更

	if (x > 50 && x < 750) {
		if (y > 150 && y < 230) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 4;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[1][2] = gold[1][3] + 1;
					gold[1][4] = gold[1][4] + 1;
					level[12][0] = level[12][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 250 && y < 330) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 5;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[2][3] = gold[2][3] + 1;
					gold[2][5] = gold[2][5] + 10;
					level[13][0] = level[13][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 350 && y < 430) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 6;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[3][3] = gold[3][3] + 1;
					gold[3][6] = gold[3][6] + 100;
					level[14][0] = level[14][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 450 && y < 530) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 7;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[4][3] = gold[4][3] + 1;
					gold[4][7] = gold[4][7] + 1000;
					level[15][0] = level[15][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 550 && y < 630) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 8;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[5][3] = gold[5][3] + 1;
					gold[5][8] = gold[5][8] + 10000;
					level[16][0] = level[16][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}
		else if (y > 650 && y < 730) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				osu = 1;
				sh = 9;
				goldmainasu();
				if (m == 0) {
					for (i = 0; i < 27; i++) {
						gold[i][0] = gold[i][1];
					}
					gold[6][3] = gold[6][3] + 1;
					gold[6][9] = gold[6][9] + 100000;
					level[17][0] = level[17][0] + 1;
					seiri();
					lr_seri();
					PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
				}
				else if (m != 0) {
					m = 0;
					PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
				}
			}
		}

	}
}

//ショップ２
void shop_n() {

	//背景
	if (shop_h_t == 0) {
		shop_h = rand() % 10;
		shop_h_t = rand() % 20;
	}

	if (shop_h == 1) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景1.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 2) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景2.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 3) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景3.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 4) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景4.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 5) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景5.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 6) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景6.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 7) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景7.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 8) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景8.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 9) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景9.png", TRUE); // 画像を描画する
	}
	else if (shop_h == 0) {
		LoadGraphScreen(000, 000, "画像/裏ショップ用/背景10.png", TRUE); // 画像を描画する
	}


	//戻るボタン
	if (shop_m_t == 0) {
		shop_m = rand() % 10;
		shop_m_t = rand() % 20;
	}

	if (shop_m == 1) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る1.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 2) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る2.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 3) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る3.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 4) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る4.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 5) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る5.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 6) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る6.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 7) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る7.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 8) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る8.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 9) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る9.png", TRUE); // 画像を描画する
	}
	else if (shop_m == 0) {
		LoadGraphScreen(modoru_x, modoru_y, "画像/裏ショップ用/戻る10.png", TRUE); // 画像を描画する
	}

	if (x > modoru_x && x < modoru_x + 60 && y > modoru_y && y < modoru_y + 60) {
		if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
			PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
			shop_x_x = 750;
			shop_x_y = 750;
			osu = 1;
			basyo = 3;
		}
	}


	//数表示
	if (shop_u_hyouzi_t == 0) {
		shop_u_hyouzi = rand() % 10;
		shop_u_hyouzi_t = rand() % 20;
	}

	if (shop_u_hyouzi == 1) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 2) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 3) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 4) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 5) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 6) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 7) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 8) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 9) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_hyouzi == 0) {
		LoadGraphScreen(150, 000, "画像/裏ショップ用/数表示0.png", TRUE); // 画像を描画する
	}



	if (level[11][0] == 100) {
		LoadGraphScreen(600, 700, "画像/ショップ01.png", TRUE); // 画像を描画する
		LoadGraphScreen(shop_x_x, shop_x_y, "画像/ショップX.png", TRUE); // 画像を描画する
		shop_x_t = 1;
		if (x > 600 && x < 800 && y > 750 && y < 800) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				shop_x_x = 750;
				shop_x_y = 750;
				osu = 1;
				basyo = 7;
			}
		}
	}

	if (shop_x_x > 700 && shop_x_y > 700 && shop_x_t == 1) {
		shop_x_x = shop_x_x - 1;
		shop_x_y = shop_x_y - 1;
		shop_x_t = 0;
	}


	//アイテム1
	if (shop_u_a_t == 0) {
		shop_u_a = rand() % 10;
		shop_u_a_t = rand() % 20;
	}

	if (shop_u_a == 1) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 2) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 3) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 4) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 5) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 6) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 7) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 8) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 9) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_a == 0) {
		LoadGraphScreen(shop_i_x, shop_i_y, "画像/裏ショップ用/アイテム1-0.png", TRUE); // 画像を描画する
	}


	//アイテム2
	if (shop_u_b_t == 0) {
		shop_u_b = rand() % 10;
		shop_u_b_t = rand() % 20;
	}

	if (shop_u_b == 1) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 2) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 3) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 4) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 5) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 6) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 7) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 8) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 9) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_b == 0) {
		LoadGraphScreen(shop_i_x, shop_i_y + 100, "画像/裏ショップ用/アイテム2-0.png", TRUE); // 画像を描画する
	}


	//アイテム3
	if (shop_u_c_t == 0) {
		shop_u_c = rand() % 10;
		shop_u_c_t = rand() % 20;
	}

	if (shop_u_c == 1) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 2) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 3) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 4) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 5) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 6) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 7) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 8) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 9) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_c == 0) {
		LoadGraphScreen(shop_i_x, shop_i_y + 200, "画像/裏ショップ用/アイテム3-0.png", TRUE); // 画像を描画する
	}


	//アイテム4
	if (shop_u_d_t == 0) {
		shop_u_d = rand() % 10;
		shop_u_d_t = rand() % 20;
	}

	if (shop_u_d == 1) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 2) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 3) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 4) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 5) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 6) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 7) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 8) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 9) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_d == 0) {
		LoadGraphScreen(shop_i_x, shop_i_y + 300, "画像/裏ショップ用/アイテム4-0.png", TRUE); // 画像を描画する
	}


	//アイテム5
	if (shop_u_e_t == 0) {
		shop_u_e = rand() % 10;
		shop_u_e_t = rand() % 20;
	}

	if (shop_u_e == 1) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 2) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 3) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 4) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 5) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 6) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 7) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 8) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 9) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_e == 0) {
		LoadGraphScreen(shop_i_x, shop_i_y + 400, "画像/裏ショップ用/アイテム5-0.png", TRUE); // 画像を描画する
	}


	//アイテム6
	if (shop_u_f_t == 0) {
		shop_u_f = rand() % 10;
		shop_u_f_t = rand() % 20;
	}

	if (shop_u_f == 1) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-1.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 2) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-2.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 3) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-3.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 4) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-4.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 5) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-5.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 6) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-6.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 7) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-7.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 8) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-8.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 9) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-9.png", TRUE); // 画像を描画する
	}
	else if (shop_u_f == 0) {
		LoadGraphScreen(shop_i_x, shop_i_y + 500, "画像/裏ショップ用/アイテム6-0.png", TRUE); // 画像を描画する
	}


	//gold表示
	if (R_T == 0) {
		R = rand() % 255;
		R_T = rand() % 20;
	}
	if (G_T == 0) {
		G = rand() % 255;
		G_T = rand() % 20;
	}
	if (B_T == 0) {
		B = rand() % 255;
		B_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R;
		GC[GC_s][1] = G;
		GC[GC_s][2] = B;
	}
	mozi = 70;
	hk = 0;
	Gold_x = 184;
	Gold_y = 0;
	GOLD();

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = 000;
		GC[GC_s][1] = 255;
		GC[GC_s][2] = 000;
	}
	GC[26][0] = 255;
	GC[26][1] = 000;
	GC[26][2] = 000;
	GC[25][0] = 000;
	GC[25][1] = 000;
	GC[25][2] = 255;
	mozi = 70;
	hk = 0;
	Gold_x = 180;
	Gold_y = 0;
	GOLD();


	if (R_a_T == 0) {
		R_a = rand() % 255;
		R_a_T = rand() % 20;
	}
	if (G_a_T == 0) {
		G_a = rand() % 255;
		G_a_T = rand() % 20;
	}
	if (B_a_T == 0) {
		B_a = rand() % 255;
		B_a_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R_a;
		GC[GC_s][1] = G_a;
		GC[GC_s][2] = B_a;
	}
	hk = 16;
	mozi = 40;
	Gold_x = 404;
	Gold_y = 155;
	GOLD();

	if (R_b_T == 0) {
		R_b = rand() % 255;
		R_b_T = rand() % 20;
	}
	if (G_b_T == 0) {
		G_b = rand() % 255;
		G_b_T = rand() % 20;
	}
	if (B_b_T == 0) {
		B_b = rand() % 255;
		B_b_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R_b;
		GC[GC_s][1] = G_b;
		GC[GC_s][2] = B_b;
	}
	hk = 17;
	mozi = 40;
	Gold_x = 404;
	Gold_y = 255;
	GOLD();

	if (R_c_T == 0) {
		R_c = rand() % 255;
		R_c_T = rand() % 20;
	}
	if (G_c_T == 0) {
		G_c = rand() % 255;
		G_c_T = rand() % 20;
	}
	if (B_c_T == 0) {
		B_c = rand() % 255;
		B_c_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R_c;
		GC[GC_s][1] = G_c;
		GC[GC_s][2] = B_c;
	}
	hk = 18;
	mozi = 40;
	Gold_x = 404;
	Gold_y = 355;
	GOLD();

	if (R_d_T == 0) {
		R_d = rand() % 255;
		R_d_T = rand() % 20;
	}
	if (G_d_T == 0) {
		G_d = rand() % 255;
		G_d_T = rand() % 20;
	}
	if (B_d_T == 0) {
		B_d = rand() % 255;
		B_d_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R_d;
		GC[GC_s][1] = G_d;
		GC[GC_s][2] = B_d;
	}
	hk = 19;
	mozi = 40;
	Gold_x = 404;
	Gold_y = 455;
	GOLD();

	if (R_e_T == 0) {
		R_e = rand() % 255;
		R_e_T = rand() % 20;
	}
	if (G_e_T == 0) {
		G_e = rand() % 255;
		G_e_T = rand() % 20;
	}
	if (B_e_T == 0) {
		B_e = rand() % 255;
		B_e_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R_e;
		GC[GC_s][1] = G_e;
		GC[GC_s][2] = B_e;
	}
	hk = 20;
	mozi = 40;
	Gold_x = 404;
	Gold_y = 555;
	GOLD();

	if (R_f_T == 0) {
		R_f = rand() % 255;
		R_f_T = rand() % 20;
	}
	if (G_f_T == 0) {
		G_f = rand() % 255;
		G_f_T = rand() % 20;
	}
	if (B_f_T == 0) {
		B_f = rand() % 255;
		B_f_T = rand() % 20;
	}

	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = R_f;
		GC[GC_s][1] = G_f;
		GC[GC_s][2] = B_f;
	}
	hk = 21;
	mozi = 40;
	Gold_x = 404;
	Gold_y = 655;
	GOLD();



	for (GC_s = 0; GC_s < 27; GC_s++) {
		GC[GC_s][0] = 255;
		GC[GC_s][1] = 000;
		GC[GC_s][2] = 000;
	}
	hk = 16;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 155;
	GOLD();

	hk = 17;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 255;
	GOLD();

	hk = 18;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 355;
	GOLD();

	hk = 19;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 455;
	GOLD();

	hk = 20;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 555;
	GOLD();

	hk = 21;
	mozi = 40;
	Gold_x = 400;
	Gold_y = 655;
	GOLD();

	SetFontSize(30);                    //文字サイズを30に変更
	
	if (R_a_a_T == 0) {
		R_a_a = rand() % 255;
		R_a_a_T = rand() % 20;
	}
	if (G_a_a_T == 0) {
		G_a_a = rand() % 255;
		G_a_a_T = rand() % 20;
	}
	if (B_a_a_T == 0) {
		B_a_a = rand() % 255;
		B_a_a_T = rand() % 20;
	}

	if (R_b_a_T == 0) {
		R_b_a = rand() % 255;
		R_b_a_T = rand() % 20;
	}
	if (G_b_a_T == 0) {
		G_b_a = rand() % 255;
		G_b_a_T = rand() % 20;
	}
	if (B_b_a_T == 0) {
		B_b_a = rand() % 255;
		B_b_a_T = rand() % 20;
	}

	if (R_c_a_T == 0) {
		R_c_a = rand() % 255;
		R_c_a_T = rand() % 20;
	}
	if (G_c_a_T == 0) {
		G_c_a = rand() % 255;
		G_c_a_T = rand() % 20;
	}
	if (B_c_a_T == 0) {
		B_c_a = rand() % 255;
		B_c_a_T = rand() % 20;
	}

	if (R_d_a_T == 0) {
		R_d_a = rand() % 255;
		R_d_a_T = rand() % 20;
	}
	if (G_d_a_T == 0) {
		G_d_a = rand() % 255;
		G_d_a_T = rand() % 20;
	}
	if (B_d_a_T == 0) {
		B_d_a = rand() % 255;
		B_d_a_T = rand() % 20;
	}

	if (R_e_a_T == 0) {
		R_e_a = rand() % 255;
		R_e_a_T = rand() % 20;
	}
	if (G_e_a_T == 0) {
		G_e_a = rand() % 255;
		G_e_a_T = rand() % 20;
	}
	if (B_e_a_T == 0) {
		B_e_a = rand() % 255;
		B_e_a_T = rand() % 20;
	}

	if (R_f_a_T == 0) {
		R_f_a = rand() % 255;
		R_f_a_T = rand() % 20;
	}
	if (G_f_a_T == 0) {
		G_f_a = rand() % 255;
		G_f_a_T = rand() % 20;
	}
	if (B_f_a_T == 0) {
		B_f_a = rand() % 255;
		B_f_a_T = rand() % 20;
	}

	DrawFormatString(448, 195, GetColor(R_a_a, G_a_a, B_a_a), "%3d ％でX2", level[6][0]);
	DrawFormatString(448, 295, GetColor(R_b_a, G_b_a, B_b_a), "%3d ％でX2", level[7][0]);
	DrawFormatString(448, 395, GetColor(R_c_a, G_c_a, B_c_a), "%3d ％でX10", level[8][0]);
	DrawFormatString(448, 495, GetColor(R_d_a, G_d_a, B_d_a), "%3d ％でX100", level[9][0]);
	DrawFormatString(448, 595, GetColor(R_e_a, G_e_a, B_e_a), "%3d ％でX1000", level[10][0]);
	DrawFormatString(448, 695, GetColor(R_f_a, G_f_a, B_f_a), "%3d ％でX10000", level[11][0]);


	DrawFormatString(445, 195, GetColor(255, 000, 000), "%3d ％でX2", level[6][0]);
	DrawFormatString(445, 295, GetColor(255, 000, 000), "%3d ％でX2", level[7][0]);
	DrawFormatString(445, 395, GetColor(255, 000, 000), "%3d ％でX10", level[8][0]);
	DrawFormatString(445, 495, GetColor(255, 000, 000), "%3d ％でX100", level[9][0]);
	DrawFormatString(445, 595, GetColor(255, 000, 000), "%3d ％でX1000", level[10][0]);
	DrawFormatString(445, 695, GetColor(255, 000, 000), "%3d ％でX10000", level[11][0]);
	SetFontSize(60);                    //文字サイズを60に変更


	if (x > 50 && x < 750) {
		if (y > 150 && y < 230) {
			if (level[6][0] < 100) {
				if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
					osu = 1;
					sh = 16;
					goldmainasu();
					if (m == 0) {
						for (i = 0; i < 27; i++) {
							gold[i][0] = gold[i][1];
						}
						gold[7][16] = gold[7][16] + 1000;
						level[6][0] = level[6][0] + 1;
						seiri();
						lr_seri();
						PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
					}
					else if (m != 0) {
						m = 0;
						PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (y > 250 && y < 330) {
			if (level[7][0] < 100) {
				if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
					osu = 1;
					sh = 17;
					goldmainasu();
					if (m == 0) {
						for (i = 0; i < 27; i++) {
							gold[i][0] = gold[i][1];
						}
						gold[8][17] = gold[8][17] + 1000;
						level[7][0] = level[7][0] + 1;
						seiri();
						lr_seri();
						PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
					}
					else if (m != 0) {
						m = 0;
						PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (y > 350 && y < 430) {
			if (level[8][0] < 100) {
				if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
					osu = 1;
					sh = 18;
					goldmainasu();
					if (m == 0) {
						for (i = 0; i < 27; i++) {
							gold[i][0] = gold[i][1];
						}
						gold[9][18] = gold[9][18] + 1000;
						level[8][0] = level[8][0] + 1;
						seiri();
						lr_seri();
						PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
					}
					else if (m != 0) {
						m = 0;
						PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (y > 450 && y < 530) {
			if (level[9][0] < 100) {
				if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
					osu = 1;
					sh = 19;
					goldmainasu();
					if (m == 0) {
						for (i = 0; i < 27; i++) {
							gold[i][0] = gold[i][1];
						}
						gold[10][19] = gold[10][19] + 10000;
						level[9][0] = level[9][0] + 1;
						seiri();
						lr_seri();
						PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
					}
					else if (m != 0) {
						m = 0;
						PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (y > 550 && y < 630) {
			if (level[10][0] < 100) {
				if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
					osu = 1;
					sh = 20;
					goldmainasu();
					if (m == 0) {
						for (i = 0; i < 27; i++) {
							gold[i][0] = gold[i][1];
						}
						gold[11][20] = gold[11][20] + 10000;
						level[10][0] = level[10][0] + 1;
						seiri();
						lr_seri();
						PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
					}
					else if (m != 0) {
						m = 0;
						PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
					}
				}
			}
		}
		else if (y > 650 && y < 730) {
			if (level[11][0] < 100) {
				if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
					osu = 1;
					sh = 21;
					goldmainasu();
					if (m == 0) {
						for (i = 0; i < 27; i++) {
							gold[i][0] = gold[i][1];
						}
						gold[12][21] = gold[12][21] + 10000;
						level[11][0] = level[11][0] + 1;
						seiri();
						lr_seri();
						PlaySoundMem(SU_kau, DX_PLAYTYPE_BACK);
					}
					else if (m != 0) {
						m = 0;
						PlaySoundMem(SU_sippai, DX_PLAYTYPE_BACK);
					}
				}
			}
		}

	}


}

//セーブ
void Save() {
	LoadGraphScreen(000, 000, "画像/セーブ・ロード.png", TRUE); // 画像を描画する

	modoru();
	LoadGraphScreen(50, 150, "画像/セーブファイル1.png", TRUE); // 画像を描画する
	LoadGraphScreen(50, 300, "画像/セーブファイル2.png", TRUE); // 画像を描画する
	LoadGraphScreen(50, 450, "画像/セーブファイル3.png", TRUE); // 画像を描画する
	LoadGraphScreen(50, 600, "画像/セーブファイル4.png", TRUE); // 画像を描画する

	LoadGraphScreen(450, 150, "画像/セーブファイル5.png", TRUE); // 画像を描画する
	LoadGraphScreen(450, 300, "画像/セーブファイル6.png", TRUE); // 画像を描画する
	LoadGraphScreen(450, 450, "画像/セーブファイル7.png", TRUE); // 画像を描画する
	LoadGraphScreen(450, 600, "画像/セーブファイル8.png", TRUE); // 画像を描画する

	if (x > 50 && x < 350) {
		if (y > 150 && y < 250) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ1.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 300 && y < 400) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ2.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 450 && y < 550) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ3.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 600 && y < 700) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ4.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
	}
	else if (x > 450 && x < 750) {
		if (y > 150 && y < 250) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ5.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 300 && y < 400) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ6.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 450 && y < 550) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ7.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 600 && y < 700) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ8.dat", "wb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fwrite(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fwrite(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
	}
}

//ロード
void Load() {
	LoadGraphScreen(000, 000, "画像/セーブ・ロード.png", TRUE); // 画像を描画する

	modoru();
	LoadGraphScreen(50, 150, "画像/セーブファイル1.png", TRUE); // 画像を描画する
	LoadGraphScreen(50, 300, "画像/セーブファイル2.png", TRUE); // 画像を描画する
	LoadGraphScreen(50, 450, "画像/セーブファイル3.png", TRUE); // 画像を描画する
	LoadGraphScreen(50, 600, "画像/セーブファイル4.png", TRUE); // 画像を描画する

	LoadGraphScreen(450, 150, "画像/セーブファイル5.png", TRUE); // 画像を描画する
	LoadGraphScreen(450, 300, "画像/セーブファイル6.png", TRUE); // 画像を描画する
	LoadGraphScreen(450, 450, "画像/セーブファイル7.png", TRUE); // 画像を描画する
	LoadGraphScreen(450, 600, "画像/セーブファイル8.png", TRUE); // 画像を描画する

	if (x > 50 && x < 350) {
		if (y > 150 && y < 250) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ1.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 300 && y < 400) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ2.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 450 && y < 550) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ3.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 600 && y < 700) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ4.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
	}
	else if (x > 450 && x < 750) {
		if (y > 150 && y < 250) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ5.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 300 && y < 400) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ6.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 450 && y < 550) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ7.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
		else if (y > 600 && y < 700) {
			if (Mouse & MOUSE_INPUT_LEFT && osu == 0) { //マウスの左ボタンが押されていたら
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				osu = 1;
				FILE *fp = fopen("セーブデータ/セーブデータ8.dat", "rb");//ファイルを開く
				if (fp == NULL) {//NULLが帰ってきたらエラー発生
					return;
				}
				for (j = 0; j < 30; j++) {
					for (i = 0; i < 27; i++) {
						fread(&gold[i][j], sizeof(int), 1, fp);
					}
				}
				for (le_k = 0; le_k < 5; le_k++) {
					for (le_s = 0; le_s < 20; le_s++) {
						fread(&level[le_s][le_k], sizeof(int), 1, fp);
					}
				}
				fclose(fp);//ファイルを閉じる
			}
		}
	}
}

//設定
void Conf() {
	LoadGraphScreen(000, 000, "画像/設定.png", TRUE); // 画像を描画する
	modoru();
	SetFontSize(60);                    //文字サイズを60に変更
	SetFontThickness(5);                //文字太さを5に変更

	if (Mouse & MOUSE_INPUT_LEFT) { //マウスの左ボタンが押されていたら
		if (y > 200 && y < 260) {
			if (x > 180 && x < 670) {
				SU_a_x = x;
				if (x >= 180 && x <= 200) {
					BGM_V = 0;
				}
				else if (x > 200 && x < 650) {
					BGM_V = (SU_a_x - 200) / 2;
				}
				else if (x >= 650 && x <= 670) {
					BGM_V = 225;
				}

			}
		}
		else if (y > 400 && y < 460) {
			if (x > 180 && x < 670) {
				SU_b_x = x;
				if (x >= 180 && x <= 200) {
					SU_V = 0;
					osu = 1;
					SU_V_K = 1;
				}
				else if (x > 200 && x < 650) {
					SU_V = (SU_b_x - 200) / 2;
					osu = 1;
					SU_V_K = 1;
				}
				else if (x >= 650 && x <= 670) {
					SU_V = 225;
					osu = 1;
					SU_V_K = 1;
				}

			}
		}

	}
	//DrawFormatString(600, 770, GetColor(000, 255, 000), "%d.", BGM_V);	//確認用

	DrawFormatString(100, 140, GetColor(000, 255, 000), "BGM");
	LoadGraphScreen(150, 200, "画像/ボリューム.png", TRUE); // 画像を描画する
	LoadGraphScreen(SU_a_x, 200, "画像/ボリューム玉.png", TRUE); // 画像を描画する

	DrawFormatString(100, 340, GetColor(000, 255, 000), "効果音");
	LoadGraphScreen(150, 400, "画像/ボリューム.png", TRUE); // 画像を描画する
	LoadGraphScreen(SU_b_x, 400, "画像/ボリューム玉.png", TRUE); // 画像を描画する
}

//設定ロード
void S_R() {

	FILE *fp = fopen("セーブデータ/settei.dat", "rb");//ファイルを開く
	if (fp == NULL) {//NULLが帰ってきたらエラー発生
		return;
	}
	fread(&BGM_V, sizeof(int), 1, fp);
	fread(&SU_V, sizeof(int), 1, fp);
	fread(&SU_a_x, sizeof(int), 1, fp);
	fread(&SU_b_x, sizeof(int), 1, fp);
	fclose(fp);//ファイルを閉じる

}

//設定セーブ
void S_S() {

	FILE *fp = fopen("セーブデータ/settei.dat", "wb");//ファイルを開く
	if (fp == NULL) {//NULLが帰ってきたらエラー発生
		return;
	}
	fwrite(&BGM_V, sizeof(int), 1, fp);
	fwrite(&SU_V, sizeof(int), 1, fp);
	fwrite(&SU_a_x, sizeof(int), 1, fp);
	fwrite(&SU_b_x, sizeof(int), 1, fp);
	fclose(fp);//ファイルを閉じる

}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	SetMainWindowText("クリッカーゲーム");	//タイトル設定
	ChangeWindowMode(TRUE); // ウインドウモードに変更
	SetWindowSize(800, 800);		//ウィンドウサイズ
	SetGraphMode(SCREEN_W, SCREEN_H, 32);	// 画面の解像度と色ビット深度を設定
	if (DxLib_Init() == -1)	{	// ＤＸライブラリ初期化処理
		return -1;        // エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);		//描画先裏画面に設定
	SetBackgroundColor(255, 255, 255);	//背景色白に設定
	SetFontSize(60);                    //文字サイズを60に変更
	SetFontThickness(5);                //文字太さを5に変更
	DATEDATA Date;					   //時刻を取得する為の変数

	//設定ロード
	S_R();


	gold[0][2] = 1;
	gold[0][10] = 10;
	gold[0][11] = 1000;
	gold[0][12] = 10000;
	gold[0][13] = 100000;
	gold[0][14] = 1000000;
	gold[0][15] = 10000000;

	gold[1][4] = 1;
	gold[2][5] = 10;
	gold[3][6] = 100;
	gold[4][7] = 1000;
	gold[5][8] = 10000;
	gold[6][9] = 100000;

	gold[7][16] = 1000;
	gold[8][17] = 1000;
	gold[9][18] = 1000;
	gold[10][19] = 10000;
	gold[11][20] = 10000;
	gold[12][21] = 10000;

	//gold[20][0] = 90000000;

	BGM_a = LoadSoundMem("サウンド/BGM1.mp3");
	BGM_b = LoadSoundMem("サウンド/BGM2.mp3");
	SU_kettei = LoadSoundMem("サウンド/戻る.mp3");
	SU_kurikku_a = LoadSoundMem("サウンド/クリック1.mp3");
	SU_kurikku_b = LoadSoundMem("サウンド/クリック2.mp3");
	SU_kau = LoadSoundMem("サウンド/購入.mp3");
	SU_sippai = LoadSoundMem("サウンド/失敗.mp3");


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
		if (END != 0) {	//ゲーム終了
			break;
		}
		Mouse = GetMouseInput();	//マウスの入力状態取得
		GetMousePoint(&x, &y); 		//マウスの座標取得

		GetDateTime(&Date);    //時間取得
		//DrawFormatString(400, 770, GetColor(255, 000, 000), "%02d時%02d分%02d秒", Date.Hour, Date.Min, Date.Sec);

		ChangeVolumeSoundMem(BGM_V * 80 / 100, BGM_a);	//音量設定
		ChangeVolumeSoundMem(BGM_V * 80 / 100, BGM_b);	//音量設定
		ChangeVolumeSoundMem(SU_V * 80 / 100, SU_kettei);	//音量設定
		ChangeVolumeSoundMem(SU_V * 80 / 100, SU_kurikku_a);	//音量設定
		ChangeVolumeSoundMem(SU_V * 80 / 100, SU_kurikku_b);	//音量設定
		ChangeVolumeSoundMem(SU_V * 80 / 100, SU_kau);	//音量設定
		ChangeVolumeSoundMem(SU_V * 80 / 100, SU_sippai);	//音量設定


		seiri();


		if (CheckSoundMem(BGM_a) != 1 && CheckSoundMem(BGM_b) != 1) {
			if (BGM == 0) {
				PlaySoundMem(BGM_a, DX_PLAYTYPE_BACK);
				BGM = 1;
			}
			else if (BGM == 1) {
				PlaySoundMem(BGM_b, DX_PLAYTYPE_BACK);
				BGM = 0;
			}
		}


		//ショップ2エフェクト用
		if (shop_h_t > 0) {
			shop_h_t = shop_h_t - 1;
		}
		if (shop_m_t > 0) {
			shop_m_t = shop_m_t - 1;
		}
		if (shop_u_a_t > 0) {
			shop_u_a_t = shop_u_a_t - 1;
		}
		if (shop_u_b_t > 0) {
			shop_u_b_t = shop_u_b_t - 1;
		}
		if (shop_u_c_t > 0) {
			shop_u_c_t = shop_u_c_t - 1;
		}
		if (shop_u_d_t > 0) {
			shop_u_d_t = shop_u_d_t - 1;
		}
		if (shop_u_e_t > 0) {
			shop_u_e_t = shop_u_e_t - 1;
		}
		if (shop_u_f_t > 0) {
			shop_u_f_t = shop_u_f_t - 1;
		}
		if (shop_u_g_t > 0) {
			shop_u_g_t = shop_u_g_t - 1;
		}
		if (shop_u_hyouzi_t > 0) {
			shop_u_hyouzi_t = shop_u_hyouzi_t - 1;
		}

		if (R_T > 0) {
			R_T = R_T - 1;
		}
		if (G_T > 0) {
			G_T = G_T - 1;
		}
		if (B_T > 0) {
			B_T = B_T - 1;
		}

		if (R_a_T > 0) {
			R_a_T = R_a_T - 1;
		}
		if (G_a_T > 0) {
			G_a_T = G_a_T - 1;
		}
		if (B_a_T > 0) {
			B_a_T = B_a_T - 1;
		}

		if (R_b_T > 0) {
			R_b_T = R_b_T - 1;
		}
		if (G_b_T > 0) {
			G_b_T = G_b_T - 1;
		}
		if (B_b_T > 0) {
			B_b_T = B_b_T - 1;
		}

		if (R_c_T > 0) {
			R_c_T = R_c_T - 1;
		}
		if (G_c_T > 0) {
			G_c_T = G_c_T - 1;
		}
		if (B_c_T > 0) {
			B_c_T = B_c_T - 1;
		}

		if (R_d_T > 0) {
			R_d_T = R_d_T - 1;
		}
		if (G_d_T > 0) {
			G_d_T = G_d_T - 1;
		}
		if (B_d_T > 0) {
			B_d_T = B_d_T - 1;
		}

		if (R_e_T > 0) {
			R_e_T = R_e_T - 1;
		}
		if (G_e_T > 0) {
			G_e_T = G_e_T - 1;
		}
		if (B_e_T > 0) {
			B_e_T = B_e_T - 1;
		}

		if (R_f_T > 0) {
			R_f_T = R_f_T - 1;
		}
		if (G_f_T > 0) {
			G_f_T = G_f_T - 1;
		}
		if (B_f_T > 0) {
			B_f_T = B_f_T - 1;
		}

		if (R_g_T > 0) {
			R_g_T = R_g_T - 1;
		}
		if (G_g_T > 0) {
			G_g_T = G_g_T - 1;
		}
		if (B_g_T > 0) {
			B_g_T = B_g_T - 1;
		}


		if (R_a_a_T > 0) {
			R_a_a_T = R_a_a_T - 1;
		}
		if (G_a_a_T > 0) {
			G_a_a_T = G_a_a_T - 1;
		}
		if (B_a_a_T > 0) {
			B_a_a_T = B_a_a_T - 1;
		}

		if (R_b_a_T > 0) {
			R_b_a_T = R_b_a_T - 1;
		}
		if (G_b_a_T > 0) {
			G_b_a_T = G_b_a_T - 1;
		}
		if (B_b_a_T > 0) {
			B_b_a_T = B_b_a_T - 1;
		}

		if (R_c_a_T > 0) {
			R_c_a_T = R_c_a_T - 1;
		}
		if (G_c_a_T > 0) {
			G_c_a_T = G_c_a_T - 1;
		}
		if (B_c_a_T > 0) {
			B_c_a_T = B_c_a_T - 1;
		}

		if (R_d_a_T > 0) {
			R_d_a_T = R_d_a_T - 1;
		}
		if (G_d_a_T > 0) {
			G_d_a_T = G_d_a_T - 1;
		}
		if (B_d_a_T > 0) {
			B_d_a_T = B_d_a_T - 1;
		}

		if (R_e_a_T > 0) {
			R_e_a_T = R_e_a_T - 1;
		}
		if (G_e_a_T > 0) {
			G_e_a_T = G_e_a_T - 1;
		}
		if (B_e_a_T > 0) {
			B_e_a_T = B_e_a_T - 1;
		}

		if (R_f_a_T > 0) {
			R_f_a_T = R_f_a_T - 1;
		}
		if (G_f_a_T > 0) {
			G_f_a_T = G_f_a_T - 1;
		}
		if (B_f_a_T > 0) {
			B_f_a_T = B_f_a_T - 1;
		}


		if (basyo == 0) {
			basyo = 1;
		}
		else if (basyo == 1) {	//タイトル画面
			Title();
		}
		else if (basyo == 2) {	//メイン画面
			Mein();
		}
		else if (basyo == 3) {	//ショップ
			Shop();
		}
		else if (basyo == 4) {	//セーブ
			Save();
		}
		else if (basyo == 5) {	//ロード
			Load();
		}
		else if (basyo == 6) {	//設定
			Conf();
		}
		else if (basyo == 7) {	//ショップ2
			shop_n();
		}
		else if (basyo == 8) { //ショップ１	
			shop_i();
		}


		time_b = Date.Sec;
		if (time_a != time_b) {		//1秒に一回if文を通る
			time_a = Date.Sec;
			F_GOLD();

		}


		//DrawFormatString(500, 700, GetColor(000, 255, 000), "%d.%d", x, y);	//マウス座標確認用

		if ((Mouse & MOUSE_INPUT_LEFT) != 1 && osu == 1) {	//左クリック放した感知
			osu = 0;
			if (SU_V_K == 1) {
				PlaySoundMem(SU_kettei, DX_PLAYTYPE_BACK);
				SU_V_K = 0;
			}
		}

		if (CheckHitKey(KEY_INPUT_SPACE) != 1 && spe == 1) { //スペースキー放した感知
			spe = 0;
		}


		//on
		if (CheckHitKey(KEY_INPUT_1) == 1 && key == 0 && hack_i == 0) {
			hack_i = 1;
			ha_i = 20;
			key = 1;
		}

		if (ha_i > 0) {
			SetFontSize(40);                    //文字サイズを40に変更
			DrawFormatString(0, 700, GetColor(255, 000, 000), "チートモードがオンになりました");
			ha_i--;
		}


		//kr
		if (CheckHitKey(KEY_INPUT_2) == 1 && key == 0 && hack_i == 1) {
			if (hack_n == 0) {
				hack_n = 1;
				ha_n = 20;
			}
			else if (hack_n == 1) {
				hack_n = 0;
				ha_n = 20;
			}
			key = 1;
		}

		if (hack_n == 0 && ha_n > 0) {
			SetFontSize(40);                    //文字サイズを40に変更
			DrawFormatString(0, 700, GetColor(255, 000, 000), "長押しがオンになりました");
			ha_n--;
		}
		else if (hack_n == 1 && ha_n > 0) {
			SetFontSize(40);                    //文字サイズを40に変更
			DrawFormatString(0, 700, GetColor(255, 000, 000), "長押しがオフになりました");
			ha_n--;
		}

		//+G
		if (CheckHitKey(KEY_INPUT_3) == 1 && key == 0 && hack_i == 1) {
			key = 1;
			gold[23][0] = gold[23][0] + 1;
		}

		//of
		if (CheckHitKey(KEY_INPUT_4) == 1 && key == 0 && hack_i == 1) {
			hack_i = 0;
			hack_n = 0;
			key = 1;
			ha_y = 20;
		}

		if (hack_n == 0 && ha_y > 0) {
			SetFontSize(40);                    //文字サイズを40に変更
			DrawFormatString(0, 700, GetColor(255, 000, 000), "チートモードがオフになりました");
			ha_y--;
		}

		if (CheckHitKey(KEY_INPUT_1) != 1 && CheckHitKey(KEY_INPUT_2) != 1 && CheckHitKey(KEY_INPUT_3) != 1 && CheckHitKey(KEY_INPUT_4) != 1 && key == 1) { //スペースキー放した感知
			key = 0;
		}

		if (hack_n == 1 && osu == 1) {	//左クリック放した感知
			osu = 0;
		}

		if (hack_n == 1 && spe == 1) { //スペースキー放した感知
			spe = 0;
		}

	}

	//設定セーブ
	S_S();


	DxLib_End();		// ＤＸライブラリ使用の終了処理

	return 0;            // ソフトの終了
}