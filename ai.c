//
// Created by ankylotech on 11.10.21.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

float min(game_state game, int tiefe, float alpha, float beta);

float max(game_state game, int tiefe, float alpha, float beta) {
    char** moves = move_list(game);
    int num = move_num(&game);
    if(game_end(game) == 0) return 0;
    else if(game_end(game) == 1) return 1;
    else if(game_end(game) == 2) return -1;
    if (tiefe == 0) {
        return evaluate(game);
    }
    float maxWert = alpha;
    for (int i = 0; i < num; i++) {
        make_move(&game,moves[i]);
        float wert = min(game, tiefe-1,maxWert,beta);
        if (wert > maxWert) {
            maxWert = wert;
            if(maxWert >= beta){
                undo_move(&game,moves[i]);
                break;
            }
        }
        undo_move(&game,moves[i]);
    }
    free(moves);
    return maxWert;
}

float min(game_state game, int tiefe, float alpha, float beta) {
    char** moves = move_list(game);
    int num = move_num(&game);
    if(game_end(game) == 0) return 0;
    else if(game_end(game) == 1) return 1;
    else if(game_end(game) == 2) return -1;
    if (tiefe == 0) {
        return evaluate(game);
    }
    float minWert = beta;
    for (int i = 0; i < num; i++) {
        make_move(&game,moves[i]);
        float wert = max( game ,tiefe-1, alpha, minWert);
        if (wert < minWert) {
            minWert = wert;
            if(minWert <= alpha) {
                undo_move(&game,moves[i]);
                break;
            }
        }
        undo_move(&game,moves[i]);
    }
    free(moves);
    return minWert;
}


char* make_ai_move(game_state* game, int depth){
    if(game_end(*game) != -1) return NULL;
    char** moves = move_list(*game);
    char* move;
    if(moves == NULL) return NULL;
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
            wert = min(copy, depth , grenzWert, 1);
            if (wert > grenzWert) {
                grenzWert = wert;
                index = i;
            }
        }else {
            wert = max(copy, depth , -1, grenzWert);
            if (wert < grenzWert) {
                grenzWert = wert;
                index = i;
            }
        }
        undo_move(&copy,moves[i]);
    }
    make_move(game,moves[index]);
    move = moves[index];
    return move;
}




