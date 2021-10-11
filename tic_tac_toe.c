//
// Created by ankylotech on 11.10.21.
//

#include "tic_tac_toe.h"

char symbol(int num){
    switch (num) {
        case 1:
            return 'X';
        case -1:
            return 'O';
        default:
            return ' ';
    }
}

int ttt_make_move(game_state* game, char* move){
    if(game->game_data[move[0]] == 0){
        game->game_data[move[0]] = game->turn;
        game->turn = game->turn * -1;
        return 0;
    }
    return 1;
}

int ttt_print_state(game_state game){
    int i,j;
    int index;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            index = i*3+j;
            printf(" %c ",symbol(game.game_data[index]));
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) {
            for (j = 0; j < 3; j++) {
                printf("---");
                if (j < 2) printf("+");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

int ttt_init_game(game_state* game){
    int i;
    game->type = 0;
    game->turn = 1;
    int* array = malloc(9*sizeof(int));
    if(array == NULL) return 1;
    for(i = 0; i < 9; i++){
        array[i] = 0;
    }
    game->game_data = array;
    return 0;
}

float ttt_evaluate(game_state game){

}

