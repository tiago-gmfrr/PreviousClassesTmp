#include "./fractions.h"
#include #include
#include



void afficherFraction(frac f){
printf("%d / %d \n", f.num, f.den);
}

int calcPGDC(frac f){
int tmp_n = abs(f.num);
int tmp_m = abs(f.den);

while (tmp_n % tmp_m > 0) {
int tmp = tmp_n;
tmp_n = tmp_m;
tmp_m = tmp % tmp_m;
}

return tmp_m;
}

frac rendreIrreductible(frac f){
int pgdc = calcPGDC(f);
frac res;
res.num = f.num / pgdc;
res.den = f.den / pgdc;
return res;
}

frac calculerPuissance(frac f, int puissance){
frac res;
if (puissance < 0) {
puissance *= -1;
res.den = pow(f.num, puissance);
res.num = pow(f.den, puissance);
}else{
res.den = pow(f.den, puissance);
res.num = pow(f.num, puissance);
}

return rendreIrreductible(res);
}

frac lireFraction(){
frac res;

do {
scanf("%d %d", &res.num, &res.den);
}while (res.den < 0);

return res;
}

frac fraction_add(frac a, frac b){
frac res;
res.num = a.num * b.den + b.num * a.den;
res.den = a.den * b.den;

return rendreIrreductible(res);
}

frac fraction_sub(frac a, frac b){
frac res;
res.num = a.num * b.den - b.num * a.den;
res.den = a.den * b.den;

return rendreIrreductible(res);


}

frac fraction_mul(frac a, frac b){
frac res;
res.num = a.num * b.num;
res.den = a.den * b.den;

return rendreIrreductible(res);
}

frac fraction_div(frac a, frac b){
frac res;
res.num = a.num * b.den;
res.den = a.den * b.num;

return rendreIrreductible(res);
}
frac fraction_neg(frac a){
frac res;

res.num = a.num * -1;
res.den = a.den;

return rendreIrreductible(res);
}
double fraction_to_double(frac a){
return (double)((a.num *1.0) / (a.den *1.0));
}