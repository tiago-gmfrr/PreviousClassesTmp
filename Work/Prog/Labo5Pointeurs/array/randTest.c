#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int32_t size = 10;
    int32_t tab[size];

    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        tab[i] = 0;
    }

    int tmp;
    for (int i = 0; i < 1000000; i++)
    {
        tmp = rand() % size;

        tab[tmp]++;
        
    }
    
    for (int i = 0; i < size; i++)
    {
        printf(" %d : %d \n", i, tab[i]);
    }
    
    return 0;
}