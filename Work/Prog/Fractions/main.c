#include "./fractions.h"
#include #include /* printf(), scanf() */

int main(){

printf("Entrez fraction a \n");
frac a = lireFraction();

printf("Entrez fraction b \n");
frac b = lireFraction();

//----------------------------------
printf("Add \n");
frac c = fraction_add(a, b);
afficherFraction(c);

printf("Sub \n");
frac d = fraction_sub(a, b);
afficherFraction(d);

printf("Mul \n");
frac e = fraction_mul(a, b);
afficherFraction(e);

printf("Div \n");
frac f = fraction_div(a, b);
afficherFraction(f);

printf("Neg \n");
frac g = fraction_neg(a);
afficherFraction(g);

printf("2Double \n");
double h = fraction_to_double(a);
printf("h = %lf \n", h);

printf("Pow \n");
frac t = calculerPuissance(t, 2);

return 0;

}