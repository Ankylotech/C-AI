#include "minMax.h"
void makeAITurn(char state[], int size) {
        int index = -1;
        for(int i = 0; i < size; i++){
                if(state[i] == 0) index = i;
        }
        int grenze = -10000 * turn;

        int counter = 0;
        for(int i = 0; i < size; i++) {
                if(zugMoeglich(i,state)) {
                        counter++;
                }
        }
        char states[counter];
        int k = 0;
        for(int i = 0; i < size; i++) {
                if(zugMoeglich(i,state)) {
                        states[k] = i;
                        k++;
                }
        }

        mergeSort(state,size,states,0,counter-1,turn,1);
        for(int j = 0; j < counter; j++) {
                int i = states[j];
                printf("%d %d\n",i, counter);
                state[i] = turn;
                float wert;
                erreichteTiefe = 1;
                if(turn == 1){
                        wert = min(state,size,grenze,10000, maxTiefe);
                        if(wert > grenze) {
                                grenze = wert;
                                index = i;
                        }
                }else {
                        wert = max(state,size,-10000,grenze, maxTiefe);
                        if(wert < grenze) {
                                grenze = wert;
                                index = i;
                        }
                }
                state[i] = 0;

        }
        printf("playing in: %d (= %d)\n", index+1, index%7);
        printf("evaluated %ld positions \n", count);
        state[index] = turn;
        turn *= -1;
}
