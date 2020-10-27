#include <stdio.h>

int main() { 
    long N = 100000000000;
    double e = 2.0;
    double facto = 1.0;
    for (long n=2;n<=N;n++){      
        facto *= n;       
        e += 1.0/facto;    
        }    
    printf("e=%.70f\n",e); 

    return 0;
}