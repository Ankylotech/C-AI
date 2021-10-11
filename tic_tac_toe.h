//
// Created by ankylotech on 11.10.21.
//

#ifndef C_AI_TIC_TAC_TOE_H
#define C_AI_TIC_TAC_TOE_H

#include <stdlib.h>
#include <stdio.h>
#include "game_type.h"

int ttt_make_move(game_state* game, char* move);

int ttt_print_state(game_state game);

int ttt_init_game(game_state* game);

float ttt_evaluate(game_state game);

#endif //C_AI_TIC_TAC_TOE_H
