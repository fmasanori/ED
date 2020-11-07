#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHAS_DEBUG    20
#define TAM                 20
int contador = 0;

void debug (char *str, int v[]){
     int i;
     printf ("%s", str);
     for (i = 0; i < TAM; i++)
         printf ("%2d ", v[i]);
     putchar('\n');
     contador++;
     if (contador == MAX_LINHAS_DEBUG){
        system("pause");
        contador = 0;
     }
}

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++)
        if (v[k] <= c) {
           t = v[j], v[j] = v[k], v[k] = t;
           j++;
        }
    v[r] = v[j], v[j] = c;
    debug ("separa ", v);
    printf ("pivo(%d,%d) = %2d\n", p, r, j);
    return j;
}

void Quicksort (int p, int r, int v[]) {
     int j;
     if (p < r) {
        j = Separa (p, r, v);
        Quicksort (p, j - 1, v);
        Quicksort (j + 1, r, v);
     }
}

int RandomInteger (int low, int high)
{
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

void gera_vetor(int v[]){
    int j;
    int i; 
    int k;
    for (i = 0; i< TAM; i++){
         j = RandomInteger (10, 100);
         for (k = 0; k < i; k++)
             if( v[k] == j ) break;
         if(k == i) v[i] = j;
         else i--;}
}

int main (void){
    int v[TAM];
    srand(time(NULL));
    gera_vetor(v);
    Quicksort(0, TAM - 1, v);
    debug("Final: ", v);
    system ("pause");
}
