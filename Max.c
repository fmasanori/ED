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

int MaximoR (int v[], int n) {
    if (n == 1)
        return v[0];
    else {
        int x;
        x = MaximoR (v, n - 1);
        if (x > v[n-1])
            return x;
        else
            return v[n-1];
    }
}

int main(void){
    int n = 5;
    int v[5] = {1, 7, 2, 9, 4};
    printf("Max=%d\n", MaximoR(v, n));
    system("pause");
}
