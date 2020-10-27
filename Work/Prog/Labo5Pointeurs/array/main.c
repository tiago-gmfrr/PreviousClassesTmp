#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

void fill_tab(int val_max, int size, int tab[size]);
int find_smallest(int val_max, int size, int tab[size]);
void biggest_to_end(int smallest, int size, int tab[size]);
bool search(int nb_entered, int size, int tab[size]);
double calc_average(int size, int tab[size]);
double calc_variance(double avg, int size, int tab[size]);
void order_tab(int size, int tab[size]);
int find_median(int size, int tab[size]);

int main(){

    printf("Pls enter a size \n");
    

    //1.1
    int32_t size;
    scanf("%d", &size);
    int32_t tab[size];

    int val_max = size / 5;
    printf("val_max = %d \n", val_max);

    //1.2
    fill_tab(val_max, size, tab);
    
    //1.3
    int smallest = find_smallest(val_max, size, tab);
    printf("Smallest : %d \n", smallest);

    //1.4
    biggest_to_end(smallest, size, tab);
    
    //1.5
    printf("Pls enter a number between 0 and %d \n", val_max-1);
    int nb_entered;
    scanf("%d", &nb_entered);
    
    bool aa = search(nb_entered, size, tab);
    
    if (aa)
    {
        printf("%d is in the array \n", nb_entered);
    }else{
        printf("%d is not in the array \n", nb_entered);
    }
    
    //1.6
    double avg = calc_average(size, tab);
    printf("The average is %lf \n", avg);

    //1.7

    double variance = calc_variance(avg, size, tab);
    printf("The variance is %lf \n", variance);

    //1.8
    order_tab(size, tab);

    for (int i = 1; i < size; i++){
        printf("%d | ", tab[i]);
    }

    printf("\n");

    //1.9
    int median = find_median(size, tab);

    printf("median : %d \n", median);
    return 0;
}

void fill_tab(int val_max, int size, int tab[size]){
    //1.2
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        tab[i] = rand() % val_max;
    }
}
int find_smallest(int val_max, int size, int tab[size]){
    //1.3
    int smallest = val_max;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] < smallest)
        {
            smallest = tab[i];
        }
        
    }

    return smallest;
}
void biggest_to_end(int smallest, int size, int tab[size]){
    int biggest = smallest;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] > biggest)
        {
            biggest = tab[i];
        }
        
    }

    int tmp;
    for (int i = 0; i < size; i++)
    {
        if(tab[i] == biggest){
            tmp = tab[size - 1];
            tab[size-1] = biggest;
            tab[i] = tmp;
        }
    }
}
bool search(int nb_entered, int size, int tab[size]){
    bool aa = false;
    for (int i = 0; i < size; i++){
        if (tab[i] == nb_entered)
        {
            aa = true;
            break;
        }
        
    }
    return aa;
}
double calc_average(int size, int tab[size]){
    double avg = 0;
    for (int i = 0; i < size; i++){
        avg += tab[0];
    }
    return avg = avg / size;
}
double calc_variance(double avg, int size, int tab[size]){
    double variance = 0;
    for (int i = 0; i < size; i++){
        variance += pow((tab[i] - avg), 2);
    }

    return variance = (1.0/size) * variance;
}
void order_tab(int size, int tab[size]){
    int tmp = 0;
    bool is_ordered = false;
    bool sorted;
    while(!is_ordered){
        
        sorted = true;
        for (int i = 1; i < size; i++){

            if (tab[i-1] > tab[i])
            {
                tmp = tab[i-1];
                tab[i-1] = tab[i];
                tab[i] = tmp;
                sorted = false;
            }
            
        }

        is_ordered = sorted;
    }
}
int find_median(int size, int tab[size]){
    int median;
    if(size % 2 == 0){
        median = tab[(size-1)/2];
    }else{
        median = (tab[(size-1)/2] + tab[size/2])/2.0;
    }
    return median;
}