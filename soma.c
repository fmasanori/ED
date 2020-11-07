#include <stdio.h>
#include <stdlib.h>

int soma(int n){
    if (n < 10)
        return n;
    else
        return n%10 + soma(n/10);
}

int main (void){
    int n = 123;
    printf ("Soma(%d)=%d\n", n, soma(n));
    system("pause");
}








