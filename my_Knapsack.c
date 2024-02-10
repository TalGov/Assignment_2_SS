#include <stdio.h>
#include "my_mat.h"

#define BACKPACKSIZE 5



int knapSack(int weights[], int values[], int selected_bool[])
{

}


void process_inputs(char items[], int weights[], int values[])
{
    for (int i = 0; i < BACKPACKSIZE; ++i) {
        scanf("%c", items[i]);
        scanf("%i", values[i]);
        scanf("%i", weights[i]);
    }
}



int main(){

    char items[BACKPACKSIZE];
    int weights[BACKPACKSIZE];
    int values[BACKPACKSIZE];


    process_inputs(items, weights, values);
}



