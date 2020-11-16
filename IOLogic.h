
void showState(char state[]) {
        if(game == 0){
                printf("\n-------\n");
                for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                                int index = i*3+j;
                                printf("|");
                                if(state[index] == 1){
                                        printf("X");
                                }else if(state[index] == -1){
                                        printf("O");
                                }else {
                                        printf("%d",index+1);
                                }
                        }
                        printf("|\n-------\n");
                }
                printf("\n\n");
        } else if(game == 1) {
                printf("\n---------------\n");
                for(int i = 0; i < 6; i++){
                        for(int j = 0; j < 7; j++) {
                                int index = i*7 + j;
                                printf("|");
                                if(state[index] == 1){
                                        printf("X");
                                }else if(state[index] == -1){
                                        printf("O");
                                }else if(getIndex4Gewinnt(j,state) == index){
                                        printf("%d",j+1);
                                }else {
                                        printf(" ");
                                }
                        }
                        printf("|\n---------------\n");
                }
        }
}

void getInput(char state[]) {
        int field;
        if(game == 0) {
                do {
                        printf("Wähle ein freies Feld von 1 - 9, in das du deinen Stein setzen möchtest:");
                        scanf("%d",&field);
                } while(field < 1 || field > 9 || state[field-1] != 0);
                state[field-1] = turn;

        }else if(game == 1) {
                do {
                        printf("Wähle ein freies Feld von 1 - 7, in das du deinen Stein setzen möchtest:");
                        scanf("%d",&field);
                } while(field < 1 || field > 8 || getIndex4Gewinnt(field-1,state) == -1);
                state[getIndex4Gewinnt(field-1,state)] = turn;
        }
        turn *= -1;
}

void executeGame(char state[]) {
        while(getEndstate(state) == 10000){
                showState(state);
                if(turn == -1 && ki == 1) {
                        int size = 9;
                        if(game == 1) size = 42;
                        makeAITurn(state,size);
                } else getInput(state);
        }
        showState(state);
        printf("%d \n", getEndstate(state));
        if(getEndstate(state) == 1) {
                printf("Spieler 1 hat gewonnen!\n");
        } else if(getEndstate(state) == -1) {
                printf("Spieler 2 hat gewonnen!\n");
        } else {
                printf("Unentschieden!\n");
        }
}
