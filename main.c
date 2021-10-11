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

    init_game(0,&game);
    printf("\n");
    print_state(game);

    while((state = game_end(game)) == -1){
        printf("Calculate Move");
        printf("\n\n\n");
        if((game.turn) % 2 == 0) {
            int size = 10;
            char *move = malloc(size);
            getline(&move, (size_t *) &size, stdin);
            printf("\n");
            printf("accepted input %s\n",move);
            make_move(&game, move);
            printf("Move executed. The Board is now:\n");
        }else {
            printf("AI making move...");
            make_ai_move(&game);
        }
        print_state(game);
    }
    printf("state: %d\n",state);
    if(state == 0){
        printf("The game is a DRAW!\n");
    }else {
        printf("Player %d has WON the game!\n",state);
    }
    return 0;
}