
int getIndex4Gewinnt(int spalte, char state[]) {
        for(int i = 35 + spalte; i >= 0; i-= 7) {
                if(state[i] == 0) return i;
        }
        return -1;
}


int getEndstate(char state[]) {
        if(game == 0){
                int ges = 0;
                int vals[3][3];

                for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                                vals[i][j] = 0;
                        }
                }
                for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                                int index = i*3+j;
                                int x = state[index];
                                vals[i][0] += x;
                                vals[j][1] += x;
                                if(i == j) vals[0][2] += x;
                                if(i == 2-j) vals[1][2] += x;
                                if(x != 0) ges++;
                        }
                }

                for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                                if(vals[i][j] >= 3) return 1;
                                else if(vals[i][j] <= -3) return -1;
                        }
                }
                if(ges == 9) return 0;
        } else if(game == 1) {
                int ges = 0;

                for(int i = 0; i < 6; i++){
                        for(int j = 0; j < 7; j++) {
                                int index = i * 7 + j;
                                if(state[index] != 0){
                                        ges++;
                                        if(j < 4) {
                                                for(int k = 1; k < 5; k++) {
                                                        if(k < 4 && state[index] != state[index + k]) break;
                                                        else if(k == 4) return state[index];
                                                }
                                        }
                                        if(i < 3) {
                                                for(int k = 1; k < 5; k++) {
                                                        if(k < 4 && state[index] != state[index + k*7]) break;
                                                        else if(k == 4) return state[index];
                                                }
                                        }
                                        if(i < 3 && j < 4) {
                                                for(int k = 1; k < 5; k++) {
                                                        if(k < 4 && state[index] != state[index + k*8]) break;
                                                        else if(k == 4) return state[index];
                                                }
                                        }
                                        if(i < 3 && j > 2){
                                                for(int k = 1; k < 5; k++) {
                                                        if(k < 4 && state[index] != state[index + k*6]) break;
                                                        else if(k == 4) return state[index];
                                                }
                                        }
                                }
                        }
                }
                if(ges == 42) return 0;
        }
        return 10000;
}

int zugMoeglich(int index, char state[]) {
        if(game == 0) return state[index] == 0;
        else if(game == 1) return (getIndex4Gewinnt(index%7,state) == index);
        return 1;
}
