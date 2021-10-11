//
// Created by ankylotech on 11.10.21.
//

#include "game_type.h"
#include "tic_tac_toe.h"

int make_move(game_state* game, char* move){
    if(game->type == 0){
        return ttt_make_move(game, move);
    }
    return 2;
}


int print_state(game_state game){
    if(game.type == 0){
        return ttt_print_state(game);
    }

    return 2;
}


int init_game(int type, game_state* game){
    if(type == 0){
        return ttt_init_game(game);
    }

    return 2;
}

float evaluate(game_state game){
    if(game.type == 0){
        return ttt_evaluate(game);
    }

    return 2;
}