//
// Created by ankylotech on 12.10.21.
//

#include "super_tic_tac_toe.h"
int sttt_game_end_cell(game_state game,int cell){
    int ges = 0;
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
            int x = field[cell*9+i*3+j];
            directionValues[i][0] += x;
            directionValues[j][1] += x;
            if(i == j) directionValues[0][2] += x;
            if(i == 2-j) directionValues[1][2] += x;
            if(x != 0) ges++;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(directionValues[i][j] >= 3) return 1;
            if(directionValues[i][j] <= -3) return 2;
        }
    }
    if(ges == 9) return 0;
    return -1;
}

int sttt_game_end(game_state game){
    int ges = 0;
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
            int x = sttt_game_end_cell(game,i*3+j);
            if(x == 2) x = -1;
            else if(x == -1) x = 0;
            directionValues[i][0] += x;
            directionValues[j][1] += x;
            if(i == j) directionValues[0][2] += x;
            if(i == 2-j) directionValues[1][2] += x;
            if(x != 0) ges++;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(directionValues[i][j] >= 3) return 1;
            if(directionValues[i][j] <= -3) return 2;
        }
    }
    if(ges == 9) return 0;
    return -1;
}

float sttt_evaluate(game_state game){
    int total = 0;
    int ges = 0;
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
            int x = sttt_game_end_cell(game,i*3+j);
            if(x == 2) x = -1;
            else if(x == -1) x = 0;
            directionValues[i][0] += x;
            directionValues[j][1] += x;
            if(i == j) directionValues[0][2] += x;
            if(i == 2-j) directionValues[1][2] += x;
            if(x != 0) ges++;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int value = directionValues[i][j];
            if(value >= 3) return 1;
            if(value <= -3) return -1;
            if(value == 2) total += 2;
            if(value == -2) total += -2;
        }
    }
    if(ges == 9) return 0;
    printf("guessing move as: %f ", total/12.0);
    return (float) (total/12.0);
}

void sttt_symbol(char * ret, int num , int index, int field){
    char val[3];
    switch (num) {
        case 1:
            val[0] = 'X';
            val[1] = ' ';
            val[2] = '\0';
            break;
        case -1:
            val[0] = 'O';
            val[1] = ' ';
            val[2] = '\0';
            break;
        case 0:
            sprintf(val,"%d%d", index, field);
            break;
        default:
            val[0] = '-';
            val[1] = ' ';
            val[2] = '\0';
            break;
    }
    sprintf(ret,"%s", val);
}

int sttt_make_move( game_state* game , const char* move ){
    int index = move[0]-48;
    int board_field = move[1]-48;
    if(index < 0 || index > 8) return 1;
    if (board_field < 0 || board_field > 8 || board_field != game->game_data[81] && game->game_data[81] != -1
        || sttt_game_end_cell(*game, board_field) != -1) {
        return 2;
    }

    int board_index = board_field*9+index;
    int turn = (game->turn) % 2 == 0 ? -1 : 1;
    if(game->game_data[board_index] == 0){
        game->game_data[board_index] = turn;
        (game->turn)++;
        if(sttt_game_end_cell(*game,index) == -1) game->game_data[81] = index;
        else  game->game_data[81] = -1;
        return 0;
    }
    return -1;
}

int sttt_undo_move(game_state* game, const char* move){
    int index = move[0]-48;
    int board_field = move[1]-48;
    int board_index = board_field*9+index;
    game->game_data[board_index] = 0;
    (game->turn)--;
    return 0;
}

char** sttt_move_list( game_state game){
    int num = sttt_move_num(&game);
    int index = 0;
    char** vals = malloc(num * sizeof(char*));
    for(int i = 0; i < num; i++){
        vals[i] = malloc(3);
        vals[i][0] = '0';
        vals[i][1] = '0';
        vals[i][2] = '\0';
    }
    int field = game.game_data[81];
    if(field == -1 || sttt_game_end_cell(game,field) != -1){
        for(int i = 0; i < 9; i++) {
            if(sttt_game_end_cell(game,i) == -1) for (int j = 0; j < 9; j++) {
                if (game.game_data[i*9+j] == 0) {
                    vals[index][0] += j;
                    vals[index][1] += i;
                    index++;
                }
            }
        }
    }else for(int i = 0; i < 9; i++){
        if(game.game_data[field*9 + i] == 0) {
            vals[index][0] += i;
            vals[index][1] += field;
            index++;
        }
    }
    return vals;
}

int sttt_move_num(game_state* game){
    int num = 0;
    int field = game->game_data[81];
    if(field == -1){
        for(int i = 0; i < 81; i++){
            if(game->game_data[i] == 0) {
                num++;
            }
        }
    }else for(int i = 0; i < 9; i++){
        if(game->game_data[field*9 + i] == 0) {
            num++;
        }
    }
    return num;
}

int sttt_print_state(game_state game) {
    int i,j;
    int index;
    static int list[9] = {0,1,2,9,10,11,18,19,20};
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            index = list[i]*3+list[j];
            char str[4] = " - ";
            sttt_symbol(str,game.game_data[index],(j%3)+ (i%3)*3, (j/3)+ (i/3)*3);
            printf(" %s", str);
            if(j < 8) {
                printf("|");
                if (j % 3 == 2) printf("|");
            }
        }
        printf("\n");
        if(i < 8) {
            for (j = 0; j < 9; j++) {
                printf("---");
                if(j < 8) {
                    printf("+");
                    if (j % 3 == 2) printf("+");
                }
            }
            printf("\n");
            if(i % 3 == 2) {
                for (j = 0; j < 9; j++) {
                    printf("---");
                    if(j < 8) {
                        printf("+");
                        if (j % 3 == 2) printf("+");
                    }
                }
                printf("\n");
            }
        }
    }
    printf("\n");
    printf("\n");
    return 0;
}

int sttt_init_game(game_state* game){
    int i;
    game->type = 1;
    game->turn = 1;
    int* array = malloc(82*sizeof(int));
    if(array == NULL) return 1;
    for(i = 0; i < 81; i++){
        array[i] = 0;
    }
    array[81] = -1;
    game->game_data = array;
    return 0;
}

int sttt_copy_game(game_state original, game_state* copy){
    int i;
    copy->type = 0;
    copy->turn = original.turn;
    int* array = malloc(82*sizeof(int));
    if(array == NULL) return 1;
    for(i = 0; i < 82; i++){
        array[i] = original.game_data[i];
    }
    copy->game_data = array;
    return 0;
}

int sttt_ai_depth(int difficulty){
    switch (difficulty) {
        case 1:
            return 18;
        case 2:
            return 27;
        case 3:
            return 81;
        default:
            return 0;
    }
}


