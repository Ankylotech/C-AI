//
// Created by ankylotech on 11.10.21.
//

#include "game_type.h"
#include "tic_tac_toe.h"

int make_move(game_state* game, char* move){
    if(game->type == 0){
        return ttt_make_move( game, move);
    }
    return 2;
}

int undo_move(game_state* game, char* move){
    if(game->type == 0){
        return ttt_undo_move( game, move);
    }
    return 2;
}

char** move_list(game_state game){
    if(game.type == 0){
        return ttt_move_list(game);
    }
    return NULL;
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

int copy_game(game_state original, game_state* copy){
    if(original.type == 0){
        return ttt_copy_game(original, copy);
    }
    return 2;
}

float evaluate(game_state game){
    if(game.type == 0){
        return ttt_evaluate(game);
    }

    return 2;
}


int game_end(game_state game){
    if(game.type == 0){
        return ttt_game_end(game);
    }

    return 2;
}