#include <stdio.h>
#include <stdlib.h>
void Insercao (int n, int v[]) {
    int i, j, k, x;
    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; i--)
            v[i+1] = v[i];
        v[i+1] = x;
    }
}
int main (void){
    int i;
    int v [8] = {2, 3, 5, 6, 1, 7, 0, 4};
    Insercao (8, v);
    for (i = 0; i < 8; i++)
        printf ("%d", v[i]);
    putchar('\n');
    system ("pause");
}
