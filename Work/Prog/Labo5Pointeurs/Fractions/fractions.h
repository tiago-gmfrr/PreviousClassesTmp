#ifndef _FRACTIONS_H_
#define _FRACTIONS_H_


typedef struct fraction{
int num, den;
}frac;

frac *lireFraction();
void afficherFraction(frac *f);
frac *fraction_add(frac *a, frac *b);
frac *fraction_sub(frac *a, frac *b);
frac *fraction_mul(frac *a, frac *b);
frac *fraction_div(frac *a, frac *b);
frac *fraction_neg(frac *a);
double fraction_to_double(frac *a);
frac *calculerPuissance(frac *f, int puissance);
frac *fraction_init(int num, int den);

#endif