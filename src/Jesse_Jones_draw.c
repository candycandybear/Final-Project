#include"func.h"
#include<stdlib.h>

void Jesse_Jones_draw(){
	int32_t num=0;
	printf("Because Player%d's role is Jesse Jones, his/her first card can draw from stock piles or player's hand cards.\n",PlayerNow+1);
	while(1){
		printf("Which player's card do you want to choose (enter player index, -1 for stock pile): ");
		if(PlayerNow==PlayerHuman){
			if(!num_scanf(&num)||num<1&&num!=-1||num>PlayerNum){
				printf("Error!\n");
				printf("Please enter again!\n\n");
				continue;
			}
			if(num==-1)break;
			num--;
			if(num==PlayerNow){
				printf("You can't choose yourself!\n");
				printf("Please enter again!\n\n");
				continue;
			}else if(player[num].hand.num<1){
				printf("The player you choosed doen't have any hand card!\n");
				printf("Please enter again!\n\n");
				continue;
			}else break;
		}else{
			if(rand()%2){
				num=-1;
				break;
			}
			num=rand()%PlayerNum;
			if(num==PlayerNow||player[num].hand.num<1){
				continue;
			}else break;
		}
	}
	if(num==-1){
		get_stock(PlayerNow);
		printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	}else{
		get_last_card(&player[PlayerNow].hand,&player[num].hand);
		printf("Player%d got a card from Player%d.\n",PlayerNow+1,num+1);
	}
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
}
