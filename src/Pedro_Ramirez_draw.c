#include"func.h"
#include<stdlib.h>

void Pedro_Ramirez_draw(){
	int32_t num=0;
	printf("Because Player%d's role is Pedro Ramirez, his/her first card can draw from stock pile or discard pile.\n",PlayerNow+1);
	while(1){
		printf("Which pile do you want to choose (0 for stock pile, 1 for discard pile): ");
		if(PlayerNow==PlayerHuman){
			if(!num_scanf(&num)||num!=0&&num!=1){
				printf("Error!\n");
				printf("Please enter again!\n\n");
				continue;
			}else if(num==0&&stock.num<=0){
				printf("Stock piles have no card!\n");
				printf("Please enter again!\n\n");
				continue;
			}else if(num==1&&discard.num<=0){
				printf("discard piles have no card!\n");
				printf("Please enter again!\n\n");
				continue;
			}else break;
		}else{
			num=rand()%2;
			if(num==0&&stock.num<=0){
				continue;
			}else if(num==1&&discard.num<=0){
				continue;
			}else break;
		}
	}
	if(num==0){
		get_stock(PlayerNow);
		printf("Player%d got a card from stock pile.\n",PlayerNow+1);
	}else{
		get_last_card(&player[PlayerNow].hand,&discard);
		printf("Player%d got a card from discard pile.\n",PlayerNow+1);
	}
	get_stock(PlayerNow);
	printf("Player%d got a card from stock pile.\n",PlayerNow+1);
}
