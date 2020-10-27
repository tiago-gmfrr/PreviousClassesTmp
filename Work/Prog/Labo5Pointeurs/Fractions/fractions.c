#include "./fractions.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


frac *fraction_init(int num, int den){
    frac *f = malloc(sizeof(frac));
    f->den = den;
    f->num = num;
    return f;
}

void afficherFraction(frac *f){
    printf("%d / %d \n", f->num, f->den);
    }

int calcPGDC(frac *f){
    int tmp_n = abs(f->num);
    int tmp_m = abs(f->den);

    while (tmp_n % tmp_m > 0) {
    int tmp = tmp_n;
    tmp_n = tmp_m;
    tmp_m = tmp % tmp_m;
    }

    return tmp_m;
}

frac *rendreIrreductible(frac *f){
    int pgdc = calcPGDC(f);
    /*frac res = fraction_init((f->num / pgdc), (f->den / pgdc));
    res.num = f->num / pgdc;
    res.den = f->den / pgdc;
    return &res;*/

    return fraction_init((f->num / pgdc), (f->den / pgdc));
}

frac *calculerPuissance(frac *f, int puissance){
    frac *res;
    if (puissance < 0) {
        puissance *= -1;
        res = fraction_init(pow(f->den, puissance), pow(f->num, puissance));
        /*res.den = pow(f->num, puissance);
        res.num = pow(f->den, puissance);*/
    }else{
        res = fraction_init(pow(f->num, puissance), pow(f->den, puissance));
        /*res.den = pow(f->den, puissance);
        res.num = pow(f->num, puissance);*/
    }

    return rendreIrreductible(res);
}

frac *lireFraction(){

    int num;
    int den;
    do {
    scanf("%d %d", &num, &den);
    }while (num < 0 && den < 0);

    return fraction_init(num, den);
}

frac *fraction_add(frac *a, frac *b){
    frac *res;
    res = fraction_init(a->num * b->den + b->num * a->den, a->den * b->den);

    return rendreIrreductible(res);
}

frac *fraction_sub(frac *a, frac *b){
    frac *res;
    res = fraction_init(a->num * b->den - b->num * a->den, a->den * b->den);

    return rendreIrreductible(res);
}

frac *fraction_mul(frac *a, frac *b){
    frac *res;
    res = fraction_init(a->num * b->num, a->den * b->den);

    return rendreIrreductible(res);
}

frac *fraction_div(frac *a, frac *b){
    frac *res;
    res = fraction_init(a->num * b->den, a->den * b->num);

    return rendreIrreductible(res);
}
frac *fraction_neg(frac *a){
    frac *res;

    res = fraction_init(a->num * -1, a->den);
    return rendreIrreductible(res);
}

double fraction_to_double(frac *a){
    return (double)((a->num *1.0) / (a->den *1.0));
}