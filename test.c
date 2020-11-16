#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<math.h>

struct evaluiert {
        float evaluation;
        int top_third;
        int middle_third;
        int bottom_third;
	struct evaluiert *next;

};
typedef struct evaluiert* node;


int top_third_calc(int state[], int size) {
        int ges = 0;
        for(int i = 0; i < (size/3); i++) {
                int k = state[i]+1;
                ges += k*pow(3,i);
        }
        return ges;
}
int middle_third_calc(int state[], int size) {
        int ges = 0;
        for(int i = 0; i < (size/3); i++) {
                int k = state[size/3 + i]+1;
                ges += k*pow(3,i);
        }
        return ges;
}

int bottom_third_calc(int state[], int size) {
        int ges = 0;
        for(int i = 0; i < (size/3); i++) {
                int k = state[2*(size/3) + i]+1;
                ges += k*pow(3,i);
        }
        return ges;
}

node insert(node *list, int data[], float eval, int size){
	node new_node = (node) malloc(sizeof(struct evaluiert));
	new_node->bottom_third = bottom_third_calc(data,size);
        new_node->middle_third = middle_third_calc(data,size);
        new_node->top_third = top_third_calc(data,size);
        new_node->evaluation = eval;
        new_node -> next = NULL;
        while( *list != NULL ) {
                list = &(*list)->next;
        }

        *list = new_node;
	return new_node;
}

node search_for(node list, int data[], int size) {
        while (list != NULL) {
                if(list->top_third == top_third_calc(data,size) && list->middle_third == middle_third_calc(data,size) && list->bottom_third == bottom_third_calc(data,size)) return list;
                list = list->next;
        }
        return NULL;
}

node anfang = NULL;

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void clear(node list) {
        node current = list;
        node next = current->next;
        while(next != NULL){
                /*Das nächste Element wird geprüft*/
                float eval = next->evaluation;
                /*Falls das Spiel bis zu einem Ende simuliert wurde, wird das entsprechende */
                if(eval == 0 || eval == 1 || eval == -1) {
                        current = next;
                }else {
                        current->next = next->next;
                }
                next = current->next;
        }
}


int main(int argc, char const *argv[]) {
        int test[42] = {1,3,3,2,2,1,2,3,3,1,2,2,3,1     ,3,3,1,1,3,2,2,1,2,2,1,2,2,2   ,3,1,1,2,1,1,3,2,2,1,2,3,2,3};
        int test2[42] = {1,3,3,2,2,1,2,3,3,1,2,2,3,1     ,3,3,1,1,3,2,2,1,2,2,1,2,2,2   ,3,1,1,2,1,1,3,2,2,1,2,3,2,3};
        for(int i = 0; i < 42; i++) {
                test2[i] -= 2;
                test[i] -= 2;
        }
        for(int i = 0; i < 42; i++) {
                test2[i] = rand()%3;
                test2[i] --;
        }
        insert(&anfang,test2,1,42);
        insert(&anfang,test,0,42);
        for(int i = 0; i < 42; i++) {
                test2[i] = rand()%3;
                test2[i] --;
        }
        insert(&anfang,test2,0.5,42);
        for(int i = 0; i < 42; i++) {
                test2[i] = rand()%3;
                test2[i] --;
        }
        insert(&anfang,test2,0.8,42);
        for(int i = 0; i < 42; i++) {
                test2[i] = rand()%3;
                test2[i] --;
        }
        insert(&anfang,test2,1,42);

        clear(anfang);
        printf("cleared \n");
        node found = search_for(anfang,test,42);
        printf("%d \n", found->top_third);
        printf("%d \n", top_third_calc(test,42));
        return 0;
}
