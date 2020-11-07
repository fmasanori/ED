#include <stdio.h>
#include <stdlib.h>

/* retorna 1 se crescente 0 caso contrario */
int cresce (int v[], int n){
    int i;
    for (i = 0; i < n-1; i++)
        if (v[i] > v[i+1])
            return 0;

    return 1;
}

int main (void) {
    int v [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x [10] = {0, 1, 2, 3, 4, 4, 3, 2, 1, 0};
    printf ("%d\n", cresce (v, 10));
    printf ("%d\n", cresce (x, 10));
    system("pause");
}
