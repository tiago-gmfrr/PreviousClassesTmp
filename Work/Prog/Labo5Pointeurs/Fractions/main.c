#include "./fractions.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){

printf("Entrez fraction a \n");
frac *a;
a = lireFraction();

printf("Entrez fraction b \n");
frac *b;
b = lireFraction();

//----------------------------------
printf("Add \n");
frac *c; 
c = fraction_add(a, b);
afficherFraction(c);

printf("Sub \n");
frac *d;
d = fraction_sub(a, b);
afficherFraction(d);

printf("Mul \n");
frac *e;
e = fraction_mul(a, b);
afficherFraction(e);

printf("Div \n");
frac *f;
f = fraction_div(a, b);
afficherFraction(f);

printf("Neg \n");
frac *g;
g = fraction_neg(a);
afficherFraction(g);

printf("2Double \n");
double h = fraction_to_double(a);
printf("h = %lf \n", h);

printf("Pow \n");
frac *t;
t = calculerPuissance(a, 2);
afficherFraction(t);

free(a);
free(b);
free(c);
free(d);
free(e);
free(f);
free(g);

return 0;

}