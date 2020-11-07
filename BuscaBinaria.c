#include <stdio.h>
#include <stdlib.h>
int cont = 0;
int BuscaSequencial (int x, int n, int v[]) {
    int j = 0;
    while (j < n && v[j] < x) {
        j++;
        cont++;
    }
    return j;
}
int BuscaBinaria (int x, int n, int v[]) {
    int e, m, d; 
    e = -1; d = n;
    while (/*X*/ e < d - 1) {
          m = (e + d)/2;
          if (v[m] < x) e = m;
          else d = m;
          cont++;
    }
    return d;
}
int BuscaBinaria2 (int x, int n, int v[]) {
    return BuscaBinR (x, -1, n, v);
}
int BuscaBinR (int x, int e, int d, int v[]) {
    if (e == d-1) return d;
    else {
         int m = (e + d)/2;
         cont++;
         if (v[m] < x)
            return BuscaBinR (x, m, d, v);
         else
            return BuscaBinR (x, e, m, v);
         }
}
int main (void){
    #define MAX 30000
    int v[MAX]; int i;
    for (i = 0; i < MAX; i++) v[i] = i;
//printf ("Sequencial %d\n", BuscaSequencial(MAX / 2, MAX, v));
  printf ("Binaria %d\n", BuscaBinaria(MAX / 2 - 1, MAX, v));
//printf ("BinRecursiva %d\n", BuscaBinaria2(MAX / 2,  MAX, v));
    printf ("%d passos\n", cont); 
    system ("pause");
}




