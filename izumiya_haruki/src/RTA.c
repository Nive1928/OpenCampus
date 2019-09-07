#include<stdio.h>

int win = 0;

int map[5][5] = {0};

void display(void){
		int x,y;
		for(y=0;y<5;y++){
			for(x=0;x<5;x++){
				switch(map[y][x]){
					case 0:
						printf("# ");
						break;
					case 1:
						printf("R ");
						break;
					case 2:
						printf("B ");
						break;
					}
				}
				puts("");
			}

		}

int input(void){
	int select = 0;
	while(1){
		scanf("%d",&select);
		if(select >= 0 && select < 5){
			break;
		}else{
			printf("いかんでしょ/n");
		}
	}
	return select;
}

void fall_out(int x, int hata){
	int y;
	for(y=0;y<5;y++){
		if(y<4){
			if(map[y+1][x] != 0){
				if(hata == 1){
					map[y][x] = 1;
					break;
				}else if(hata == 2){
					map[y][x] = 2;
					break;
				}
			}
		}else if(y==4){
			if(hata==1){
				map[y][x] = 1;
				break;
			}else if(hata==2){
				map[y][x] = 2;
				break;
			}
		}
	}
}

void kusokurae(int count){
	int select = 0;
	if(count % 2 == 0){
		puts("");
		printf("プレイヤーレッドの番です。");
		select = input();
		fall_out(select, 1);
	}else if(count % 2 == 1){
		puts("");
		printf("プレイヤーブルーの番です。");
		select = input();
		fall_out(select, 2);
	}
}
void chark(int hata){
	int x,y;
	for(y=0;y<5;y++){
		for(x=1;x<4;x++){
			if(map[y][x] == hata && map[y][x+1] == hata && map[y][x-1] == hata){
				win = hata;
				break;
			}
		}
	}
	for(x=0;x<5;x++){
		for(y=0;y<4;y++){
			if(map[y][x] == hata && map[y+1][x] == hata && map[y-1][x] == hata){
				win = hata;
				break;
			}
		}
	}
	for(x=1;x<4;x++){
		for(y=1;y<4;y++){
			if(map[y][x] == hata && map[y-1][x-1] == hata && map[y+1][x+1] == hata ){
				win = hata;
			}else if(map[y][x] == hata && map[y-1][x+1] == hata && map[y+1][x-1] ==  hata){
				win = hata;
				break;
			}
		}
	}
}


int main(void){
	int count = 0;
	while(win == 0){
		display();
		kusokurae(count);
		chark(count % 2 + 1);
		count++;
	}
	if(win==1){
		printf("プレイヤーレッドの勝ち");
	}else if(win==2){
		printf("プレイヤーブルーの勝ち");
	}
	return 0;
}
