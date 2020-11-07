#include <stdio.h>
#include <stdlib.h>

int v [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int verifica (int n, int v[]) {
    int i, j, cont = 0;
    for (i = 0; i < n; i++){
        if (i == 0)
            i++;
        else {
            for (j=i; j >= 0; j--) {
                if (v[i] < v[j])
                    cont++;
            }
        }
    }
    if (cont > 0)
        return 0;
    else
        return 1;
}

int main (void)
{
    printf("Crescente = %d\n", verifica(10, v));
    system("pause");
}
