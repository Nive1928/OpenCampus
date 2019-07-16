#define _CRT_SECURE_NO_WARNINGSx

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{


	int com[6];	      	//computer/*main
	int a[6];	  	//　私
	int b[6];            	//player2
	int card[3][13] = {0}; 	//card[0hearts, 1daimons, 2clubs, 3spades][1Ace, 2, 3..., 11Jack, 12Queen, 13King]
	int mark, num;
	int player=3;
	int tarn=0;
	int i;
	
	printf("WELCOME TO POPDING\n");
	printf("\n");
	printf("Popding　は２人以上、１３人以下がやることが出来る\n");
	printf("\n");

	while(tarn<6){
		srand((unsigned)time(NULL));
		i=0;
		while(i<player){
			switch(i){
			case 0:
				
				mark = rand() % 3;
				num = rand() % 13;
				if (card[mark][num] == 1){
					continue;
				}else{
					card[mark][num]=1;
					com[tarn]=mark;
					com[tarn+1]=num + 1;
					
					i++;
					break;
				}
			case 1:	
				
				mark=rand() % 3;
				num=rand() % 13;
				if (card[mark][num]==1){
					continue;
				}else{
					card[mark][num]=1;
					a[tarn]=mark;
					a[tarn+1]=num +1;
					
					i++;
					break;
				}
			case 2:
				mark=rand() % 3;
				num=rand() % 13;
				if (card[mark][num]==1){
					continue;
				}else{
					card[mark][num]=1;
					b[tarn]=mark;
					b[tarn+1]=num + 1;
					
					i++;
					break;
				}
			}
		}
		tarn += 2;                                                // tarn = tarn + 2
	}

	printf("\n");
	printf(" ROUND 1\n");
	printf("\n");

	int j, k, l;	//com, a ,b計算値
	int Jack1=10;	
	int Queen1=10;
	int King1=10;
	int z1 = 0; 	// when z1 == 1, com popding 
	int z2 = 0; 	// when z2 == 1, a popding
	int z3 = 0; 	// when z3 == 1, b popding
	int z11 = 0;	// when z11 == 1, com パス
	int z22 = 0;	// when z22 == 1, a パス
	int z33 = 0;    // when z33 == 1, b パス
	int m, n;	// markを表示
	int comget, aget, bget;	//一枚が欲しい

	if(com[1] == 11 || com[3] == 11 ){com[1]=Jack1; com[3]=Jack1;}
	if(com[1] == 12 || com[3] == 12 ){com[1]=Queen1; com[3]=Queen1;}
	if(com[1] == 13 || com[3] == 13 ){com[1]=King1; com[3]=King1;}

		j=com[1] + com[3];
		j=j%10;	
	if(j == 8 || j == 9){
		printf("comはpopdingで, ");
		z1=1;
		if ((com[0] == com[2]) || (com[1] == com[3])){
			printf("comは2dingで, ");	//2dingはポイントが２倍です。
		}else			
			{		
				printf("comは1dingで, ");                    //1dingは一倍です。
			}
		printf("comは終わり。\n");
		printf("comの手札の数字は%d %d \n", com[1], com[3]);

		m=com[0];
		switch(m){
		case 0:printf("heart\n");break;
		case 1:printf("daimon\n");break;
		case 2:printf("club\n");break;
		case 3:printf("spade\n");break;
		}

		n=com[2];
		switch(n){
		case 0:printf("heart\n");break;
		case 1:printf("daimon\n");break;
		case 2:printf("club\n");break;
		case 3:printf("spade\n");break;
		}
		printf("comは%d \n", j);
	}else
		{
			printf("comは一枚ほしい、または、ほしくない.\n");     //round2がある
			comget=rand()%2;
			if(comget == 0){
				printf("comはパス\n");
				z11=2;
			}else if(comget == 1){
				printf("comは一枚が欲しい\n");
			}
		}

	if(a[1] == 11 || a[3] == 11 ){a[1]=Jack1; a[3]=Jack1;}
	if(a[1] == 12 || a[3] == 12 ){a[1]=Queen1; a[3]=Queen1;}
	if(a[1] == 13 || a[3] == 13 ){a[1]=King1; a[3]=King1;}
	k=a[1] + a[3];
	k=k%10;
	printf("私の手札の数字は%d %d \n", a[1], a[3]);
	if(k == 8 || k == 9){
		printf("私はpopdingで, ");
		z2=1;
		if ((a[0] == a[2]) || (a[1] == a[3])){
			printf("私は2dingで, ");
			
		}else
			{
				printf("私は1dingで, ");
			}
		printf("私は終わり。\n");
	

		m=a[0];
		switch(m){
		case 0:printf("heart\n");break;
		case 1:printf("daimon\n");break;
		case 2:printf("club\n");break;
		case 3:printf("spade\n");break;
		}

		n=a[2];
		switch(n){
		case 0:printf("heart\n");break;
		case 1:printf("daimon\n");break;
		case 2:printf("club\n");break;
		case 3:printf("spade\n");break;
		} 
		printf("私は%d \n", k);
	}else 
		{
		       printf("一枚ほしい、または、ほしくない? (0 パス:1 一枚が欲しい )>");
		       scanf("%d", &aget);
		       if(aget == 0){
			       printf("私はパス\n");
			       z22=2;
		       }else if(aget == 1){
			       printf("私は一枚が欲しい\n");
		       }
		}
       

	if(b[1] == 11 || b[3] == 11 ){b[1]=Jack1; b[3]=Jack1;}
	if(b[1] == 12 || b[3] == 12 ){b[1]=Queen1; b[3]=Queen1;}
	if(b[1] == 13 || b[3] == 13 ){b[1]=King1; b[3]=King1;}
        l=b[1] + b[3];
	l=l%10;
	if(l == 8 || l == 9){
		printf("bはpopdingで, ");
		z3=1;
		if((b[0] == b[2]) || (b[1] == b[3])){
			printf("bは2dingで, ");
		}else
			{
				printf("bは1dingで, ");
			} 
		printf("bは終わり。\n");
		printf("bの手札の数字は%d %d \n", b[1], b[3]);

		m=b[0];
		switch(m){
		case 0:printf("heart\n");break;
		case 1:printf("daimon\n");break;
		case 2:printf("club\n");break;
		case 3:printf("spade\n");break;
		}

		n=b[2];
		switch(n){
		case 0:printf("heart\n");break;
		case 1:printf("daimon\n");break;
		case 2:printf("club\n");break;
		case 3:printf("spade\n");break;
		}
		printf("bは%d \n", l);
	}else 
		{
			printf("bは一枚ほしい、または、ほしくない.\n");
			bget=rand()%2;
			if(bget == 0){
				printf("bはパス\n");
				z33=2;
			}else if(bget == 1){
				printf("bは一枚が欲しい\n");
			}
		}
	
	if((z1 != 1) && (z2 == 1 )){
		printf("私の勝ち\n");
	}
	else if(z1 == 1 && z2 != 1){
                printf("私の負け\n");
        }
	if((z1 != 1) && ( z3 == 1)){
		printf("bの勝ち\n");
	}
	else if(z1 == 1 && z3 != 1){
		printf("bの負け\n");
	} 
	if((z1 == 1) && ((z2 == 1) || (z3 == 1))){
		if(j == 8 && k == 8){
			printf("私はcomと等しい\n");
		}
		else if(j == 8 && k == 9){
			printf("私の勝ち\n");
		}
		else if(j == 9 && k == 8){
			printf("私の負け\n");
		}
		
		if(j == 8 && l == 8){
			printf("bはcomと等しい\n");
		}
		else if(j == 8 && l == 9){
			printf("bの勝ち\n");
		}
		else if(j == 9 && l == 8){
			printf("bの負け\n");
		}
		printf("今回終わり。\n");
	}
	else if(z1 == 1){
		printf("comの勝ち、 ");
		printf("今回終わり。\n");
	}
	else if(z2 == 1 && z3 == 1){
		printf("今回は終わり。\n");
		
	}else{
		

		printf("\n");
		printf("ROUND 2\n");
		printf("\n");

		int Jack2=11;
		int Queen2=12;
		int King2=13;
		int Ace=14;
		int o;		//三枚目のmarkを表示
		int s1 = 0;	// comが順番、pao, falangに使う
		int s2 = 0;	// aが順番、pao, falangに使う
		int s3 = 0;	// bが順番、pao, falangに使う
		int RULE1=0;	// ルール
		int RULE2=0;	// ルール
		int RULE3=0;	// ルール
		

		//com
		if(z1 != 1 && z11 != 2){
			if(com[1] == Jack1 || com[3] == Jack1 ){com[1]=Jack2; com[3]=Jack2;}
			if(com[1] == Queen1 || com[3] == Queen1 ){com[1]=Queen2; com[3]=Queen2;}
			if(com[1] == King1 || com[3] == King1 ){com[1]=King2; com[3]=King2;}
			if(com[1] == 1 || com[3] == 1 || com[5] == 1){com[1]=Ace; com[3]=Ace; com[5]=Ace;}
			
			if((com[0] == com[2]) && (com[0] == com[4]) && (com[2] == com[4])){
				printf("comは3dingです。\n");             	//ポイントが三倍です。
			}	
			if((com[1]+1 == com[3]) && (com[3]+1 == com[5]) || (com[3]+1 == com[1]) && (com[1]+1 == com[5]) || (com[5]+1 == com[1]) && (com[1]+1 == com[3]) || 
			   (com[1]+1 == com[5]) && (com[5]+1 == com[3]) || (com[3]+1 == com[5]) && (com[5]+1 == com[1]) || (com[5]+1 == com[3]) && (com[3]+1 == com[1])){
				printf("comは順番です。\n");               	// 順番はポイントが三倍です。
				s1=1;
			} 	
			else if((com[1] == com[3]) && (com[1] == com[5]) && (com[3] == com[5])){
				printf("comはpaoです。\n");                    //paoは三枚が同じ場合で、ポイントが四倍です。
				s1=2;
			}
			else if((com[1] == 11 || com[1] == 12 || com[1] ==13) && (com[3] == 11 || com[3] == 12 || com[3] == 13) && (com[5] == 11 || com[5] == 12 || com[5] == 13)) {
				printf("comはfalangです。\n");          	// falangはポイントが二倍です。
				s1=3;
			}
			
			RULE1=1;
		}	

		//a
		if(z2 != 1 && z22 != 2){
			if(a[1] == Jack1 || a[3] == Jack1 ){a[1]=Jack2; a[3]=Jack2;}
			if(a[1] == Queen1 || a[3] == Queen1 ){a[1]=Queen2; a[3]=Queen2;}
			if(a[1] == King1 || a[3] == King1 ){a[1]=King2; a[3]=King2;}
			if(a[1] == 1 || a[3] == 1 || a[5] == 1){a[1]=Ace; a[3]=Ace; a[5]=Ace;}
			
			if((a[0] == a[2]) && (a[0] == a[4]) && (a[2] == a[4])){
				printf("私は3dingです。\n");               	//ポイントが三倍です。
			}	
			if((a[1]+1 == a[3]) && (a[3]+1 == a[5]) || (a[3]+1 == a[1]) && (a[1]+1 == a[5]) || (a[5]+1 == a[1]) && (a[1]+1 == a[3]) || 
			   (a[1]+1 == a[5]) && (a[5]+1 == a[3]) || (a[3]+1 == a[5]) && (a[5]+1 == a[1]) || (a[5]+1 == a[3]) && (a[3]+1 == a[1])){
				printf("私は順番です。\n");        		// 順番はポイントが三倍です。
				s2=1;
			} 
			else if((a[1] == a[3]) && (a[1] == a[5]) && (a[3] == a[5])){
				printf("私はpaoです。\n");    			//paoは三枚が同じ場合で、ポイントが四倍です。
				s2=2;
			} 
			else if((a[1] == 11 || a[1] == 12 || a[1] == 13) && (a[3] == 11 || a[3] == 12 || a[3] == 13) && (a[5] == 11 || a[5] == 12 || a[5] == 13)){
				printf("私はfalangです。\n"); 			// falangはポイントが二倍です。
				s2=3;
			}
			
			RULE2=1;
			
		}
		
		//b
		if(z3 != 1 && z33 != 2){
			if(b[1] == Jack1 || b[3] == Jack1 ){b[1]=Jack2; b[3]=Jack2;}
			if(b[1] == Queen1 || b[3] == Queen1 ){b[1]=Queen2; b[3]=Queen2;}
			if(b[1] == King1 || b[3] == King1 ){b[1]=King2; b[3]=King2;}
			if(b[1] == 1 || b[3] == 1 || b[5] == 1){b[1]=Ace; b[3]=Ace; b[5]=Ace;}
			
			if((b[0] == b[2]) && (b[0] == b[4]) && (b[2] == b[4])){
				printf("bは3dingです。\n");           	 	//ポイントが三倍です。
			}	
			if((b[1]+1 == b[3]) && (b[3]+1 == b[5]) || (b[3]+1 == b[1]) && (b[1]+1 == b[5]) || (b[5]+1 == b[1]) && (b[1]+1 == b[3]) || 
			   (b[1]+1 == b[5]) && (b[5]+1 == b[3]) || (b[3]+1 == b[5]) && (b[5]+1 == b[1]) || (b[5]+1 == b[3]) && (b[3]+1 == b[1])){
				printf("bは順番です。\n");           		// 順番はポイントが三倍です。
				s3=1;
			} 
			else if((b[1] == b[3]) && (b[1] == b[5]) && (b[3] == b[5])){
				printf("bはpaoです。\n");     			//paoは三枚が同じ場合で、ポイントが四倍です。
				s3=2;
			} 
			else if((b[1] == 11 || b[1]  == 12 || b[1] == 13) && (b[3] == 11 || b[3] == 12 || b[3] == 13) && (b[5] == 11 || b[5] == 12 || b[5] == 13)) {
				printf("bはfalangです。\n");   			// falangはポイントが二倍です。
				s3=3;
			}

			RULE3=1;
			
		}	
		

		if((RULE1 == 1 || RULE2 == 1) && (z1 != 1 && z2 !=1)){
			
			//comとaの比べ
			if(s1 == 1 && s2 == 1){
				if((com[1] + com[3] + com[5]) == (a[1] + a[3] + a[5])){
					printf("私はcomと等しい\n");
				}
				else if((com[1] + com[3] + com[5]) < (a[1] + a[3] + a[5])){
					printf("私の勝ち\n");
				}
				else if((com[1] + com[3] + com[5]) > (a[1] + a[3] + a[5])){
					printf("私の負け\n");
				}
			}
			else if(s1 == 1 && s2 == 3){
				printf("私の負け\n");
			}
			else if(s1 != 2 && s2 == 2){
				printf("私の勝ち\n");
			}
			else if(s1 == 2 && s2 == 2){
				if(com[1] == a[1]){
					printf("私はcomと等しい\n");
				}
				else if(com[1] < b[1]){
					printf("私の勝ち\n");
				}
				else if(com[1] > b[1]){
					printf("私の負け\n");
				}
			}
			else if(s1 == 2 && s2 != 2){
				printf("私の負け\n");
			}
			if(s1 == 3 && s2 == 3){
				
				//11*11*12=1452
				//11*11*13=1573
				//12*12*11=1584
				//12*12*13=1872
				//13*13*11=1859
				//13*13*12=2028
				
				if((com[1] * com[3] * com[5]) == 1452 && (a[1] * a[3] * a[5]) == 1452){		printf("私はcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1452 && (a[1] * a[3] * a[5]) != 1452){	printf("私の勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1573 && (a[1] * a[3] * a[5]) < 1573){	printf("私の負け\n");		}
				else if((com[1] * com[3] * com[5]) == 1573 && (a[1] * a[3] * a[5]) == 1573){	printf("私はcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1573 && (a[1] * a[3] * a[5]) > 1573){	printf("私の勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1584 && (a[1] * a[3] * a[5]) < 1584){	printf("私の負け\n");		}	
				else if((com[1] * com[3] * com[5]) == 1584 && (a[1] * a[3] * a[5]) == 1584){	printf("aはcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1584 && (a[1] * a[3] * a[5]) > 1584){	printf("私の勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1872 && (a[1] * a[3] * a[5]) == 1859){ 	printf("私の勝ち\n");		}     	//特別
				else if((com[1] * com[3] * com[5]) == 1872 && (a[1] * a[3] * a[5]) < 1859){	printf("私の負け\n");		}      	//特別
				else if((com[1] * com[3] * com[5]) == 1872 && (a[1] * a[3] * a[5]) == 1872){	printf("私はcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1872 && (a[1] * a[3] * a[5]) > 1872){	printf("私の勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1859 && (a[1] * a[3] * a[5]) == 1872){	printf("私の負け\n");		} 	//特別
				else if((com[1] * com[3] * com[5]) == 1859 && (a[1] * a[3] * a[5]) < 1859){	printf("私の負け\n");		}
				else if((com[1] * com[3] * com[5]) == 1859 && (a[1] * a[3] * a[5]) == 1859){	printf("私はcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1859 && (a[1] * a[3] * a[5]) > 1872){	printf("私の勝ち\n");   		}     	//特別
				
				else if((com[1] * com[3] * com[5]) == 2028 && (a[1] * a[3] * a[5]) == 2028){	printf("私はcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 2028 && (a[1] * a[3] * a[5]) != 2028){	printf("私の負け\n");		}
				
			}	
			else if(s1 == 3 && s2 == 1){
				printf("私の勝ち\n");
			}
			else if(s1 == 1 && s2 !=1 && s2 != 2 && s2 != 3){
                                printf("私の負け\n");
			}	
			else if(s1 == 3 && s2 != 1 && s2 != 2 && s2 != 3){
				printf("私の負け\n");
			}
			else if(s1 != 1 && s1 != 2 && s1 != 3 && s2 == 1){
				printf("私の勝ち\n");
			}	
			else if(s1 != 1 && s1 != 2 && s1 != 3 && s2 == 3){
				printf("私の勝ち\n");
			}
		}
		if((RULE1 == 1 || RULE3 == 1) && (z1 != 1 && z3 != 1)){
			
			//comとbの比べ
			if(s1 == 1 && s3 == 1){
				if((com[1] + com[3] + com[5]) == (b[1] + b[3] + b[5])){
					printf("bはcomと等しい\n");
				}
				else if((com[1] + com[3] + com[5]) < (b[1] + b[3] + b[5])){
					printf("bの勝ち\n");
				}
				else if((com[1] + com[3] + com[5]) > (b[1] + b[3] + b[5])){
					printf("bの負け\n");
				}
			}
			else if(s1 == 1 && s3 == 3){
				printf("bの負け\n");
			}
			else if(s1 != 2 && s3 == 2){
				printf("bの勝ち\n");
			}
			else if(s1 == 2 && s3 == 2){
				if(com[1] == b[1]){
					printf("bはcomと等しい\n");
				}
				else if(com[1] < b[1]){
					printf("bの勝ち\n");
				}
				else if(com[1] > b[1]){
					printf("bの負け\n");
				}
			}
			else if(s1 == 2 && s3 != 2){
				printf("bの負け\n");
			}
			else if(s1 == 3 && s3 == 3){
			     	//11*11*12=1452
				//11*11*13=1573
				//12*12*11=1584
				//12*12*13=1872
				//13*13*11=1859
				//13*13*12=2028
				
				if((com[1] * com[3] * com[5] == 1452) && (b[1] * b[3] * b[5]) == 1452){	printf("bはcomと等しい\n");		}
				else if((com[1] * com[3] * com[5] == 1452) && (b[1] * b[3] * b[5]) != 1452){	printf("bの勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1573 && (b[1] * b[3] * b[5]) < 1573){	printf("bの負け\n");		}
				else if((com[1] * com[3] * com[5]) == 1573 && (b[1] * b[3] * b[5]) == 1573){	printf("bはcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1573 && (b[1] * b[3] * b[5]) > 1573){	printf("bの勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1584 && (b[1] * b[3] * b[5]) < 1584){	printf("bの負け\n");		}
				else if((com[1] * com[3] * com[5]) == 1584 && (b[1] * b[3] * b[5]) == 1584){	printf("bはcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1584 && (b[1] * b[3] * b[5]) > 1584){	printf("bの勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1872 && (b[1] * b[3] * b[5]) == 1859){ printf("bの勝ち\n");		} 	//特別
				else if((com[1] * com[3] * com[5]) == 1872 && (b[1] * b[3] * b[5]) < 1859){	printf("bの負け\n");		}     	//特別
				else if((com[1] * com[3] * com[5]) == 1872 && (b[1] * b[3] * b[5]) == 1872){	printf("bはcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1872 && (b[1] * b[3] * b[5]) > 1872){	printf("bの勝ち\n");		}
				
				else if((com[1] * com[3] * com[5]) == 1859 && (b[1] * b[3] * b[5]) == 1872){	printf("bの負け\n");		}      	//特別
				else if((com[1] * com[3] * com[5]) == 1859 && (b[1] * b[3] * b[5]) < 1859){	printf("bの負け\n");		}
				else if((com[1] * com[3] * com[5]) == 1859 && (b[1] * b[3] * b[5]) == 1859){	printf("bはcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 1859 && (b[1] * b[3] * b[5]) > 1872){	printf("bの勝ち\n");		}      	//特別
				
				else if((com[1] * com[3] * com[5]) == 2028 && (b[1] * b[3] * b[5]) == 2028){	printf("bはcomと等しい\n");	}
				else if((com[1] * com[3] * com[5]) == 2028 && (b[1] * b[3] * b[5]) != 2028){	printf("bの負け\n");		}
			}	
			else if(s1 == 3 && s3 == 1){
				printf("bの勝ち\n");
			}
			else if(s1 == 1 && s3 !=1 && s3 != 2 && s3 != 3){
                                printf("bの負け\n");
			}	
			else if(s1 == 3 && s3 != 1 && s3 != 2 && s3 != 3){
				printf("bの負け\n");
			}
			else if(s1 != 1 && s1 != 2 && s1 != 3 && s3 == 1){
				printf("bの勝ち\n");
			}
			else if(s1 != 1 && s1 != 2 && s1 != 3 && s3 == 3){
				printf("bの勝ち\n");
			}
			
		}

		if(RULE1 == 1){
			printf("comの手札の数字は%d %d %d \n", com[1], com[3], com[5]);
			
			m=com[0];
			switch(m){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			
			n=com[2];
			switch(n){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			o=com[4];
			switch(o){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			if(com[1] == 11 || com[1] == 12 || com[1] == 13)com[1]=10;
			if(com[3] == 11 || com[3] == 12 || com[3] == 13)com[3]=10;
			if(com[5] == 11 || com[5] == 12 || com[5] == 13)com[5]=10;
			if(com[1] == Ace || com[3] == Ace || com[5] == Ace){com[1]=1; com[3]=1; com[5]=1;}
			j=com[1] + com[3] + com[5];
			j=j%10;
			printf("comは%d \n", j);
		}	

		if(RULE2 == 1){
			printf("私の手札の数字は%d %d %d \n", a[1], a[3], a[5]);
			
			m=a[0];
			switch(m){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}

			n=a[2];
			switch(n){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			o=a[4];
			switch(o){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			if(a[1] == 11 || a[1] == 12 || a[1] == 13)a[1]=10;
			if(a[3] == 11 || a[3] == 12 || a[3] == 13)a[3]=10;
			if(a[5] == 11 || a[5] == 12 || a[5] == 13)a[5]=10;
			if(a[1] == Ace || a[3] == Ace || a[5] == Ace){a[1]=1; a[3]=1; a[5]=1;}
			k=a[1] + a[3] + a[5];
			k=k%10;
			printf("私は%d \n", k);
		}	
		
		if(RULE3 == 1){
			printf("bの手札の数字は%d %d %d \n", b[1], b[3], b[5]);
			
			m=b[0];
			switch(m){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			
			n=b[2];
			switch(n){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			
			o=b[4];
			switch(o){
			case 0:printf("heart\n");break;
			case 1:printf("daimon\n");break;
			case 2:printf("club\n");break;
			case 3:printf("spade\n");break;
			}
			if(b[1] == 11 || b[1] == 12 || b[1] == 13)b[1]=10;
			if(b[3] == 11 || b[3] == 12 || b[3] == 13)b[3]=10;
			if(b[5] == 11 || b[5] == 12 || b[5] == 13)b[5]=10;
			if(b[1] == Ace || b[3] == Ace || b[5] == Ace){b[1]=1; b[3]=1; b[5]=1;}
			l=b[1] + b[3] + b[5];
			l=l%10;
			printf("bは%d \n", l);
			
		}	

		if((z1 != 1 && z2 != 1) && (s1 != 1 && s1 != 2 && s1 != 3) && (s2 != 1 && s2 != 2 && s2 != 3)){ 
			
			//comとaの比べ
			if(j == k){
				printf("私はcomと等しい\n");
			}	
			else if(j < k){
				printf("私の勝ち\n");
			}
			else if(j > k){
				printf("私の負け\n");
			}
		}
 
		if((z1 != 1 && z3 != 1) && (s1 != 1 && s1 != 2 && s1 != 3) && (s3 != 1 && s3 != 2 && s3 != 3)){
			
			//comとbの比べ
			if(j == l){
				printf("bはcomと等しい\n");
			}	
			else if(j < l){
				printf("bの勝ち\n");
			}
			else if(j > l){
				printf("bの負け\n");
			}	
		}
		
	}
printf("THANK YOU FOR PLAYING POPDING\n");
	return(0);
}
  
