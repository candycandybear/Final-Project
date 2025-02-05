#include"func.h"

int32_t get_stock(int32_t player_index){
	if(!is_player_exist(player_index))return 0;
	if(!get_last_card(&player[player_index].hand,&stock)){
		printf("Stock pile have no card.\n");
		printf("Combining stock pile and discard pile.\n");
		printf("Shuffling stock pile.\n");
		shuffling();
		get_last_card(&player[player_index].hand,&stock);
	}
	return 1;
}
