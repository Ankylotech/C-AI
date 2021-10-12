//
// Created by ankylotech on 11.10.21.
//

#include "game_type.h"
#include "tic_tac_toe.h"
#include "super_tic_tac_toe.h"

int make_move(game_state* game, char* move){
    if(game->type == 0){
        return ttt_make_move( game, move);
    }else if(game->type == 1){
        return sttt_make_move(game,move);
    }
    return 2;
}

int undo_move(game_state* game, char* move){
    if(game->type == 0){
        return ttt_undo_move( game, move);
    }else if(game->type == 1){
        return sttt_undo_move(game,move);
    }
    return 2;
}

char** move_list(game_state game){
    if(game.type == 0){
        return ttt_move_list(game);
    }else if(game.type == 1){
        return sttt_move_list(game);
    }
    return NULL;
}

int move_num(game_state* game){
    if(game->type == 0){
        return ttt_move_num(game);
    }else if(game->type == 1){
        return sttt_move_num(game);
    }
    return -1;
}


int print_state(game_state game){
    printf("\n");
    if(game.type == 0){
        return ttt_print_state(game);
    }else if(game.type == 1){
        return sttt_print_state(game);
    }

    return 2;
}


int init_game(int type, game_state* game){
    if(type == 0){
        return ttt_init_game(game);
    }else if(type == 1){
        return sttt_init_game(game);
    }

    return 2;
}

int copy_game(game_state original, game_state* copy){
    if(original.type == 0){
        return ttt_copy_game(original, copy);
    } else if(original.type == 1){
        return sttt_copy_game(original,copy);
    }
    return 2;
}

int ai_depth_calc(int type, int difficulty){
    if(type == 0){
        return ttt_ai_depth(difficulty);
    }else if(type == 1){
        return sttt_ai_depth(difficulty);
    }

    return 0;
}

float evaluate(game_state game){
    if(game.type == 0){
        return ttt_evaluate(game);
    } else if(game.type == 1){
        return sttt_evaluate(game);
    }

    return 2;
}


int game_end(game_state game){
    if(game.type == 0){
        return ttt_game_end(game);
    }else if(game.type == 1){
        return sttt_game_end(game);
    }

    return 2;
}