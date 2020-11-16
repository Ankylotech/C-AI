#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>



float max(char state[], int size, float alpha, float beta, int tiefe);
float min(char state[], int size, float alpha, float beta, int tiefe);

int game = 0;
int turn = 1;
long count = 0;
int ki = 2;
int erreichteTiefe = 0;
#define maxTiefe 8

#include "gameLogic.h"
#include "stateEvaluation.h"
#include "utility.h"
#include "Ai.h"
#include "IOLogic.h"


int main(int argc, char const *argv[]) {
        do {
                printf("Welches Spiel möchtest du spielen?\n (1) = TicTacToe, (2) = 4-Gewinnt \n");
                scanf("%d",&game);
        } while(game != 1 && game != 2);
        game--;
        do {
                printf("Möchtest du gegen die KI oder einen anderen Spieler spielen?\n (1) = KI, (2) = Spieler \n");
                scanf("%d",&ki);
        } while(ki != 1 && ki != 2);
        if(game == 0){
                char gameState[9];
                for(int i = 0; i < 9; i++){
                        gameState[i] = 0;
                }
                executeGame(gameState);
        }else if(game == 1) {
                char gameState[42];
                for(int i = 0; i < 42; i++){
                        gameState[i] = 0;
                }
                executeGame(gameState);
        }

        return 0;
}
