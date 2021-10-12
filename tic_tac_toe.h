//
// Created by ankylotech on 11.10.21.
//

#ifndef C_AI_TIC_TAC_TOE_H
#define C_AI_TIC_TAC_TOE_H

#include <stdlib.h>
#include <stdio.h>
#include "game_type.h"

int ttt_make_move(game_state* game, const char* move);

int ttt_undo_move(game_state* game, const char* move);

char** ttt_move_list(game_state game);

int ttt_move_num(game_state* game);

int ttt_print_state(game_state game);

int ttt_init_game(game_state* game);

int ttt_copy_game(game_state original, game_state* copy);

int ttt_ai_depth(int difficulty);

float ttt_evaluate(game_state game);

int ttt_game_end(game_state game);

#endif //C_AI_TIC_TAC_TOE_H
