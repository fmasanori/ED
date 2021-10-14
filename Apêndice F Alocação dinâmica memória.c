#include <stdio.h>
#include <stdlib.h>

int main(void){
    int cont = 0;
    while (malloc (1000) != NULL) // alocando 1000 bytes
        if (cont++ == 20000){
            putchar ('.');      // apenas para mostra que estah vivo
            cont = 0;
        }
 
    printf ("\nAcabou a memoria!\n");
    system ("pause");
}
