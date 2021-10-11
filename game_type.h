//
// Created by ankylotech on 11.10.21.
//

#ifndef C_AI_GAME_TYPE_H
#define C_AI_GAME_TYPE_H


typedef struct game_state__ {
    int type;
    char turn;
    int* game_data;

} game_state;

int make_move(game_state* game, char* move);

int print_state(game_state game);

int init_game(int type, game_state* game);

float evaluate(game_state game);

#endif //C_AI_GAME_TYPE_H
