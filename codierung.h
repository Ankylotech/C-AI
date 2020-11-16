
/*Codierung des obersten Spielfelddrittels als einzelne Zahl*/
int top_third_calc(char state[], int size) {
        int ges = 0;
        for(int i = 0; i < (size/3); i++) {
                /*das oberste Spielfeld wird in einer Zahl der Basis 3 mit einem drittel des Feldes (im falle von 4-Gewinnt 14) an Stellen.*/
                int k = state[i]+1;
                ges += k*pow(3,i);
        }
        return ges;
}

/*Der mittlere Teil des Spielfeldes wird auch als Zahl gespeichert*/
int middle_third_calc(char state[], int size) {
        int ges = 0;
        for(int i = 0; i < (size/3); i++) {
                int k = state[size/3 + i]+1;
                ges += k*pow(3,i);
        }
        return ges;
}

/*Der unterste Teil des Spielfeldes wird als eine Zahl gespeichert*/
int bottom_third_calc(char state[], int size) {
        int ges = 0;
        for(int i = 0; i < (size/3); i++) {
                int k = state[2*(size/3) + i]+1;
                ges += k*pow(3,i);
        }
        return ges;
}
