#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHAS_DEBUG    20
#define TAM                 10
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

int RandomInteger (int low, int high)
{
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

void gera_vetor(int v[]){
     int i;
     srand (time (NULL));
     for (i = 0; i < TAM; i++)
         v[i] = RandomInteger(10, 90);     
}

void Intercala (int p, int q, int r, int v[]) {
int i, j, k, *w;
     w = malloc ((r-p) * sizeof (int));
     i = p; j = q; k = 0;
     while (i < q && j < r) {
           if (v[i] <= v[j]) w[k++] = v[i++];
           else w[k++] = v[j++];
     }
     while (i < q) w[k++] = v[i++];
     while (j < r) w[k++] = v[j++];
     for (i = p; i < r; i++) v[i] = w[i-p];
     free (w);
}

void Mergesort (int p, int r, int v[]) {
     if (p < r - 1) {
        int q = (p + r)/2;
        printf ("Mergesort(%2d, %2d, v)\n", p, q);
        printf ("Mergesort(%2d, %2d, v)\n", q, r);
        Mergesort (p, q, v);
        Mergesort (q, r, v);
        Intercala (p, q, r, v);
     }
}
void MergesortI (int n, int v[]) {
int p, r, b = 1;
    while (b < n) {
          p = 0;
          while (p + b < n) {
                r = p + 2*b;
                if (r > n) r = n;
                printf ("Intercala(%2d, %2d, %2d, v)\n", p, p + b, r);
                Intercala (p, p + b, r, v);
                p = p + 2*b;
          }
          b = 2*b;
          debug("Inter  ", v);
    }
}

int main (void){
    int v [TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//    int v [TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//    int v[TAM];
    gera_vetor(v);
    debug("Antes: ", v);
//    Mergesort(0, TAM, v);

    MergesortI(TAM, v);
    debug("Final: ", v);
    system ("pause");
}
