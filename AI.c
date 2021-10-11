//
// Created by ankylotech on 11.10.21.
//

#include<stdio.h>
#include<stdlib.h>
#include"game_type.h"

int main(){
    game_state game;

    init_game(0,&game);
    print_state(game);

    while(1){
        char* move = malloc(sizeof(char));
        scanf("%c",&move[0]);
        make_move(&game,move);
        print_state(game);
    }

    return 0;
}