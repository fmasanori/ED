#include <stdio.h>
#include <stdlib.h>

int Max (int v[], int n) {
int j, x;
    x = v[0];
    for (j = 1; j < n; j++)
    /* x é um elemento máximo de v[0..j-1] */
        if (x < v[j]) x = v[j];
    return x;
}

int main (void){
    int n = 10;
    int v[10] = {3, 1, 10, 5, 4, -1, 2, 9, 0, 42};

    printf ("Max = %d\n", Max(v, n));
    system ("pause");
}
