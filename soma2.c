#include <stdio.h>
#include <stdlib.h>



int soma(int n){
    if (n <= 9)
        return n;
    else
        return n % 10 + soma(n / 10);
}

int main (void){
    
    printf("Soma = %d\n", soma(123)); 
    system("pause");
}
