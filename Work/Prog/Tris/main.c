#include <stdio.h>
#include <stdlib.h>

void swap(int* p_a,int* p_b) { 
   int tmp = *p_a;
   *p_a = *p_b;
   *p_b = tmp;
}

void tri_bulle_step(int size,int tab[size]) {
   for (int i=0;i<size-1;i++) {
      if (tab[i] > tab[i+1]) {
         swap(&tab[i],&tab[i+1]);
      }
   }
}    

// Tri à bulle
void tri_bulle(int size,int tab[size]) {
   for (int sz=size;sz>=2;sz--) {
      tri_bulle_step(sz,tab);
   }
}    

int index_min(int size,int tab[size],int i) {
   int ind_min = i;
   for (int k=i+1;k<size;k++) {
      if (tab[k] < tab[ind_min]) {
         ind_min = k;
      }
   }
   return ind_min;
}

void tri_selection_step(int size,int tab[size],int i) {
   // à compléter
}    

// Tri par sélection
void tri_selection(int size,int tab[size]) {
   for (int i=0;i<size-1;i++) {
      tri_selection_step(size,tab,i);
   }
}
   
int position(int size,int tab[size],int val) {
   int pos = 0;
   while (pos < size && val > tab[pos]) {
      pos++;
   }
   return pos;
}

void shift(int size,int tab[size],int pos) { 
   for (int i = size-1; i < pos; i++)
   {
       tab[i] = tab[i-1];
   }
   
}

// Tri par insertion
void tri_insertion(int size,int tab[size]) {
   
}    

void print(int size,int tab[size]) {
   for (int i=0;i<size;i++) {
      printf("%d ",tab[i]);
   }
}

void random_tab(int size,int tab[size]) {
   for (int i=0;i<size;i++) {
      tab[i] = -50+rand()%100;
   }
}

int main(int argc,char** argv) {
   if (argc != 4) {
      printf("usage: program <size> <seed> <sorting_algo_number>\n");
      exit(EXIT_FAILURE);
   }
   int size = atoi(argv[1]);
   int seed = atoi(argv[2]);
   int choix = atoi(argv[3]);
   srand(seed);
   int res[size];
   random_tab(size,res);
   print(size,res);
   printf("\n");
   switch(choix) {
      case 1: tri_bulle(size,res); break;
      case 2: tri_selection(size,res); break;
      case 3: tri_insertion(size,res); break;
      default: printf("Choix non available\n");
   }

   print(size,res);
   printf("\n");
   return EXIT_SUCCESS;
}












