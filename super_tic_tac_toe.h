//
// Created by ankylotech on 12.10.21.
//

#ifndef C_AI_SUPER_TIC_TAC_TOE_H
#define C_AI_SUPER_TIC_TAC_TOE_H

#include <stdlib.h>
#include <stdio.h>
#include "game_type.h"

int sttt_make_move(game_state* game, const char* move);

int sttt_undo_move(game_state* game, const char* move);

char** sttt_move_list(game_state game);

int sttt_move_num(game_state* game);

int sttt_print_state(game_state game);

int sttt_init_game(game_state* game);

int sttt_copy_game(game_state original, game_state* copy);

int sttt_ai_depth(int difficulty);

float sttt_evaluate(game_state game);

int sttt_game_end(game_state game);

#endif //C_AI_SUPER_TIC_TAC_TOE_H
