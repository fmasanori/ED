#include <stdio.h>
#include <stdlib.h>
void troca2 (int p, int q){  // passagem por valor == copia
    int temp;
    temp = p;
    p = q;
    q = temp;
    printf ("@@@@   %d %d\n", p, q);
}
void troca (int *p, int *q){ // passagem por referencia
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
int main(void){
    int a = 33, b = 77;
    printf ("Antes  a=%d, b=%d\n", a, b);
    troca (&a, &b);
    //troca2 (a, b);
    printf ("Depois a=%d, b=%d\n", a, b);

    int *v; // int v[10];
    int i;
    int n;
    scanf("%d", &n);
    v = malloc (n * sizeof (int));
    // note que posso pegar o tamanho em tempo
    // de execucao
    for (i = 0; i < n; i++)
        v[i] = i;

    for (i = 0; i < n; i++)
        printf ("%d ", v[i]);
    putchar ('\n');
    system("pause");
}
