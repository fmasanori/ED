#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    int a, b, cont;
    a = 0;
    b = 1;
    cont = 0;
    while (cont < n){
          a = a + b;
          b = a - b;
          cont++;
    }
    return a;
}

int fib2(int n){
    int m = 0; int f = 1; int j = 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    else{
        while (n > 1){
              m = f;
              f += j;
              j = m;
              n--;
        }
        return f;
    }
}

int main(void){
    int i;
    for (i = 1; i < 10; i++)
        printf("fib2(%d)=%d\n", i, fib2(i));
    system ("pause");
}
