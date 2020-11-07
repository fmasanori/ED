#include <stdio.h>
#include <stdlib.h>

int RemoveZerosR (int v[], int n) {
    int m;
    if (n == 0) return 0;
    m = RemoveZerosR (v, n - 1);
    if (v[n-1] == 0) {
       printf ("zero na pos=%d\n", n-1);
       return m;
    }
    v[m] = v[n-1];
    return m + 1;
}

int RemoveZeros (int v[], int n) {
    int i = 0, j;
    for (j = 0; j < n; j++) 
        if (v[j] != 0) {
           v[i] = v[j];
           i += 1;
        }
 
    return i;
}

int main (void){
    int v[10] = {1, 0, 2, 0, 0, 5, 8};
    int i, k, n = 7;
    for (i=0; i < n; i++)
        printf ("%d ", v[i]);
    putchar('\n');
    printf ("Elementos distintos de zero: %d\n", 
            k = RemoveZeros(v, n));
    for (i=0; i < n; i++)
        printf ("%d ", v[i]);
    system ("pause");
}






