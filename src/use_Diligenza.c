#include"func.h"

void use_Diligenza(int32_t card_index){
	get_card(&discard,&player[PlayerNow].hand,card_index);
	get_stock(PlayerNow);
	printf("Player%d gets a card from stock pile.\n",PlayerNow+1);
	get_stock(PlayerNow);
	printf("Player%d gets a card from stock pile.\n",PlayerNow+1);
}
