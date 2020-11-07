#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    printf ("Fib(%d)\n", n);
    if (n == 1 || n == 2) 
        return 1;
    else
        return fib(n-2) + fib(n-1);
}

int main (void){
    printf ("Fib=%d\n", fib(10));
    system ("pause");
}
