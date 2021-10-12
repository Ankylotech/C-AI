//
// Created by ankylotech on 11.10.21.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

float min(game_state game, int tiefe);

float max(game_state game, int tiefe) {
    char** moves = move_list(game);
    int num = move_num(&game);
    if(game_end(game) == 0) return 0;
    else if(game_end(game) == 1) return 1;
    else if(game_end(game) == 2) return -1;
    if (tiefe == 0) {
        return evaluate(game);
    }
    float maxWert = -1;
    for (int i = 0; i < num; i++) {
        make_move(&game,moves[i]);
        float wert = min(game, tiefe-1);
        if (wert > maxWert) {
            maxWert = wert;
        }
        undo_move(&game,moves[i]);
    }
    free(moves);
    return maxWert;
}

float min(game_state game, int tiefe) {
    char** moves = move_list(game);
    int num = move_num(&game);
    if(game_end(game) == 0) return 0;
    else if(game_end(game) == 1) return 1;
    else if(game_end(game) == 2) return -1;
    if (tiefe == 0) {
        return evaluate(game);
    }
    float minWert = 1;
    for (int i = 0; i < num; i++) {
        make_move(&game,moves[i]);
        float wert = max( game ,tiefe-1);
        if (wert < minWert) {
            minWert = wert;
        }
        undo_move(&game,moves[i]);
    }
    free(moves);
    return minWert;
}


int make_ai_move(game_state* game, int depth){
    if(game_end(*game) != -1) return 1;
    char** moves = move_list(*game);
    if(moves == NULL) return -1;
    int num = move_num(game);
    int index = 0;
    int turn = (game->turn) %2;
    float grenzWert = (turn == 0) ? 1 : -1;
    for (int i = 0; i < num; i++) {
        game_state copy;
        copy_game(*game, &copy);
        make_move(&copy,moves[i]);
        float wert;
        if (turn == 1) {
            wert = min(copy, depth);
            if (wert > grenzWert) {
                grenzWert = wert;
                index = i;
            }
        }else {
            wert = max(copy, depth);
            if (wert < grenzWert) {
                grenzWert = wert;
                index = i;
            }
        }
        undo_move(&copy,moves[i]);
    }
    make_move(game,moves[index]);
    for (int i = 1; i < num; i++) {
        free(moves[i]);
    }
    free(moves);
    return 0;
}




