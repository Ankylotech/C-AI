//
// Created by ankylotech on 11.10.21.
//

#include "tic_tac_toe.h"

char symbol( int num ){
    switch (num) {
        case 1:
            return 'X';
        case -1:
            return 'O';
        default:
            return ' ';
    }
}

int ttt_make_move( game_state* game , const char* move ){
    int index = move[0]-48;
    int turn = (game->turn) % 2 == 0 ? -1 : 1;
    if(game->game_data[index] == 0){
        game->game_data[index] = turn;
        (game->turn)++;
        return 0;
    }
    return 1;
}

int ttt_undo_move(game_state* game, const char* move){
    int index = move[0]-48;
    game->game_data[index] = 0;
    (game->turn)--;
    return 0;
}

char** ttt_move_list( game_state game){
    int num = ttt_move_num(&game);
    int index = 0;
    char** vals = malloc(num * sizeof(char*));
    for(int i = 0; i < num; i++){
        vals[i] = malloc(1);
        vals[i][0] = '0';
    }
    for(int i = 0; i < 9; i++){
        if(game.game_data[i] == 0) {
            vals[index][0] += i;
            index++;
        }
    }
    return vals;
}

int ttt_move_num(game_state* game){
    int num = 0;
    for(int i = 0; i < 9; i++){
        if(game->game_data[i] == 0) {
            num++;
        }
    }
    if(game->turn != 10 - num) game->turn = 10-num;
    return num;
}

int ttt_print_state(game_state game){
    int i,j;
    int index;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            index = i*3+j;
            printf(" %c ",symbol(game.game_data[index]));
            if(j < 2) printf("|");
        }
        printf("\n");
        if(i < 2) {
            for (j = 0; j < 3; j++) {
                printf("---");
                if (j < 2) printf("+");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    return 0;
}

int ttt_init_game(game_state* game){
    int i;
    game->type = 0;
    game->turn = 1;
    int* array = malloc(9*sizeof(int));
    if(array == NULL) return 1;
    for(i = 0; i < 9; i++){
        array[i] = 0;
    }
    game->game_data = array;
    return 0;
}

int ttt_copy_game(game_state original, game_state* copy){
    int i;
    copy->type = 0;
    copy->turn = original.turn;
    int* array = malloc(9*sizeof(int));
    if(array == NULL) return 1;
    for(i = 0; i < 9; i++){
        array[i] = original.game_data[i];
    }
    copy->game_data = array;
    return 0;
}

float ttt_evaluate(game_state game){
    if(game.turn == 9) return 0;
    int* field = game.game_data;
    float total = 0;
    int** directionValues = malloc(3 * sizeof (int*));
    for(int i = 0; i < 3; i++){
        directionValues[i] = malloc(3 * sizeof(int));
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int x = field[i*3+j];
            directionValues[i][0] += x;
            directionValues[j][1] += x;
            if(i == j) directionValues[0][2] += x;
            if(i == 2-j) directionValues[1][2] += x;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int value = directionValues[i][j];
            if(value >= 3) return 1;
            if(value <= -3) return -1;
            if(value == 2) total += 1;
            if(value == -2) total += -1;
        }
    }
    return total/6;

}


int ttt_game_end(game_state game){
    if(game.turn == 9) return 0;
    int* field = game.game_data;
    int** directionValues = malloc(3 * sizeof (int*));
    for(int i = 0; i < 3; i++){
        directionValues[i] = malloc(3 * sizeof(int));
    }
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            directionValues[i][j] = 0;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int x = field[i*3+j];
            directionValues[i][0] += x;
            directionValues[j][1] += x;
            if(i == j) directionValues[0][2] += x;
            if(i == 2-j) directionValues[1][2] += x;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(directionValues[i][j] >= 3) return 1;
            if(directionValues[i][j] <= -3) return 2;
        }
    }
    return -1;
}

