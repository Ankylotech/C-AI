float evaluate(char state[]) {
        if(getEndstate(state) != 10000) return getEndstate(state);

        if(game == 0) {
                int ges = 0;
                for(int i = 0; i < 9; i++) {
                        ges += state[i];
                }
                if(ges == 1) {
                        return max(state,9,-10000,10000,10);
                }else {
                        return min(state,9,-10000,10000,10);
                }
        }else if(game == 1) {
                float ges = 0;
                for(int i = 0; i < 6; i++){
                        for(int j = 0; j < 7; j++) {
                                int index = i * 7 + j;
                                if(state[index] != 0){
                                        for(int k = 1; k < 4 && j + k < 7; k++) {
                                                if(k < 4 && state[index] != state[index + k] ) {
                                                        if(state[index+k] == 0 && j > 0 && state[index-1] == 0) {
                                                                ges += state[index] * pow(10.0,k);
                                                        }
                                                        break;
                                                }
                                        }

                                        for(int k = 1; k < 4 && index + k * 7 < 42; k++) {
                                                if(k < 4 && state[index] != state[index + k*7] ) {
                                                        if(state[index+k*7] == 0 && i > 0 && state[index-7] == 0 && j > 0) {
                                                                ges += state[index] * pow(10.0,k);
                                                        }
                                                        break;
                                                }
                                        }

                                        for(int k = 1; k < 4 && j + k < 7 && index + k * 8 < 42; k++) {
                                                if(k < 4 && state[index] != state[index + k*8] ){
                                                        if( state[index+k*8] == 0 && i > 0 && state[index-8] == 0 && j > 0) {
                                                                ges += state[index] * pow(10.0,k);
                                                        }
                                                        break;
                                                }

                                        }

                                        for(int k = 1; k < 4 && j - k > 0 && index + k * 6 < 42; k++) {
                                                if(k < 4 && state[index] != state[index + k*6] ){
                                                        if(state[index+k*6] == 0 && i > 0 && state[index-6] == 0 && j > 0) {
                                                                ges += state[index] * pow(10.0,k);
                                                        }
                                                        break;
                                                }
                                        }
                                }
                        }
                }
                return ges / 10000.0;
        }

        return 0;
}
