#include <stdio.h>
#include <stdlib.h>
int cont = 0;
int BuscaBinaria (int x, int n, int v[]) {
    int e, m, d; 
    e = -1; 
	d = n;
    while (e < d - 1) {
          m = (e + d)/2;
          if (v[m] < x) e = m;
          else d = m;
          cont++;
    }
    return d;
}
int main (void){
    int v[30000]; int i;
    for (i = 0; i < 30000; i++) v[i] = i;
    printf ("Binaria %d\n", BuscaBinaria(15000, 30000, v));
    printf ("%d passos\n", cont); 
    system ("pause");
}




