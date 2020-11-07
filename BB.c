#include <stdio.h>
#include <stdlib.h>

int cont = 0;
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
int BuscaBinaria2 (int x, int n, int v[]) {
    return BuscaBinR (x, -1, n, v);
}
int main (void){
    int v[512];
    int i;
    for (i = 0; i < 512; i++)
        v[i] = i;
    BuscaBinaria2 (42, 512, v);
    printf ("Achou em %d passos\n", cont);
    system ("pause");
}
