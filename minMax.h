float max(char state[], int size, float alpha, float beta, int tiefe) {
        if(maxTiefe - tiefe > erreichteTiefe) erreichteTiefe = maxTiefe-tiefe;
        if(getEndstate(state) != 10000 || tiefe <= 0) {
                count++;
                return evaluate(state);
        };
        float grenze = alpha;
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

        mergeSort(state,size,states,0,counter-1,1, tiefe-1);

        for(int j = 0; j < counter; j++) {
                int i = states[j];
                state[i] = 1;
                float wert;
                wert = min(state,size,grenze,beta, tiefe-1);

                if(wert > grenze) {
                        grenze = wert;
                }
                state[i] = 0;
                if(grenze >= beta) return grenze;

        }
        return grenze;
}

float min(char state[], int size, float alpha, float beta, int tiefe) {
        if(maxTiefe - tiefe < erreichteTiefe) erreichteTiefe = maxTiefe-tiefe;
        if(getEndstate(state) != 10000 || tiefe <= 0) {
                count++;
                return evaluate(state);
        };
        float grenze = beta;

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

        mergeSort(state,size,states,0,counter-1,1, tiefe-1);

        for(int j = 0; j < counter; j++) {
                int i = states[j];
                state[i] = -1;
                float wert;
                wert = max(state,size,alpha,grenze, tiefe-1);

                if(wert < grenze) {
                        grenze = wert;
                }
                state[i] = 0;
                if(grenze <= alpha) return grenze;

        }
        return grenze;
}
