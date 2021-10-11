//
// Created by ankylotech on 11.10.21.
//

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "ai.h"

int counter = 0;

float min(game_state game, int tiefe, float alpha, float beta);

float max(game_state game, int tiefe, float alpha, float beta) {
    counter++;
    char** moves = move_list(game);
    int num = 10-game.turn;
    if (tiefe == 0 || num == 0) {
        return evaluate(game);
    }
    float maxWert = alpha;
    for (int i = 0; i < num; i++) {
        make_move(&game,moves[i]);
        float wert = min(game, tiefe-1,
                         maxWert, beta);
        if (wert > maxWert) {
            maxWert = wert;
            if (maxWert >= beta)
                break;
        }
        undo_move(&game,moves[i]);
    }
    free(moves);
    return maxWert;
}

float min(game_state game, int tiefe, float alpha, float beta) {
    counter++;
    char** moves = move_list(game);
    int num = 10-game.turn;
    if (tiefe == 0 || num == 0) {
        return evaluate(game);
    }
    float minWert = beta;
    for (int i = 0; i < num; i++) {
        make_move(&game,moves[i]);
        float wert = max( game ,tiefe-1, alpha, minWert);
        if (wert < minWert) {
            minWert = wert;
            if (minWert <= alpha)
                break;
        }
        undo_move(&game,moves[i]);
    }
    free(moves);
    return minWert;
}


int make_ai_move(game_state* game){
    printf("making move\n");
    game_state copy;
    copy_game(*game, &copy);
    char** moves = move_list(*game);
    if(moves == NULL) return -1;
    printf("List created\n");
    int num = 10-game->turn;
    printf("The List has %d members\n",num);
    int index = 1;
    int turn = game->turn %2;
    float grenzWert = (turn == 0) ? -1 : 1;
    for (int i = 0; i < num; i++) {
        printf("betrachte move %d\n",i);
        make_move(&copy,moves[i]);
        if (turn == 1) {
            float wert;
            wert = min(copy, MAX_SEARCH_DEPTH, grenzWert, 1);
            if (wert > grenzWert) {
                grenzWert = wert;
                index = i;
            }
        }else {
            float wert;
            wert = max(copy, MAX_SEARCH_DEPTH, -1, grenzWert);
            if (wert < grenzWert) {
                grenzWert = wert;
                index = i;
            }
        }
        if(counter % 1 == 0) printf("counter : %d\n",counter);
        undo_move(&copy,moves[i]);
    }
    make_move(game,moves[index]);
    for (int i = 1; i < num; i++) {
        free(moves[i]);
    }
    free(moves);
    return 0;
}




