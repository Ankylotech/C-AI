//
// Created by ankylotech on 11.10.21.
//

#include<stdio.h>
#include<stdlib.h>
#include"game_type.h"
#include"ai.h"

int main(){
    game_state game;
    int state;
    int game_type;
    int ai_turn;
    int ai_depth = 0;
    int ai_difficulty;

    printf("What game do you want to play?(0 = TicTacToe)\n");
    scanf("%d",&game_type);

    printf("Do you want to play against an AI (0) or with a friend ?\n");
    scanf("%d",&ai_turn);

    if(ai_turn == 0){
        printf("What difficulty do you want the AI to be (1-3)?\n");
        scanf("%d",&ai_difficulty);
        ai_depth = ai_depth_calc(game_type, ai_difficulty);
        printf("Do you want to go first(0) or have the ai go first(1)\n");
        scanf("%d",&ai_turn);
    }else{
        ai_turn = 2;
    }
    getchar();

    printf("ai: %d", ai_turn);

    init_game(game_type,&game);
    printf("\n");
    print_state(game);
    int last_turn = game.turn-1;
    while((state = game_end(game)) == -1){
        int turn = game.turn;
        if (turn % 2 == ai_turn) {
            if (last_turn != turn) printf("Making AI move:\n");
            make_ai_move(&game, ai_depth);
        } else {
            if (last_turn != turn) printf("Make a move:\n");
            int size = 10;
            char *move = malloc(size);
            getline(&move, (size_t *) &size, stdin);
            make_move(&game, move);
        }
        if(turn != game.turn) {
            print_state(game);
        }
        last_turn = turn;
    }
    printf("\n\n\n  GAME OVER!  \n");
    print_state(game);
    if(state == 0){
        printf("The game is a DRAW!\n");
    }else {
        printf("Player %d has WON the game!\n",state);
    }
    return 0;
}