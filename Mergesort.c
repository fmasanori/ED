#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHAS_DEBUG    20
#define TAM                 16
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
void gera_vetor(int v[]){
    int j, i, k;
    for (i = 0; i< TAM; i++){
         j = RandomInteger (10, 100);
         for (k = 0; k < i; k++)
            if ( v[k] == j ) 
                break;
         if(k == i) 
            v[i] = j;
         else 
            i--;
    }
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
        system ("pause");
        Mergesort (p, q, v); // cpu 1
        Mergesort (q, r, v); // cpu 2
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
                printf ("Intercala(%2d, %2d, %2d, v)\n", 
                        p, p + b, r);
                Intercala (p, p + b, r, v);
                p = p + 2*b;
          }
          b = 2*b;
          debug("Inter  ", v);
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

int main (void){
//    int v [TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
//    int v [TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int v[TAM];
    srand(time(NULL));
    gera_vetor(v);
    debug("Antes: ", v);
	Mergesort(0, TAM, v);

    //MergesortI(TAM, v);
    debug("Final: ", v);
    system ("pause");
}
