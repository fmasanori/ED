#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Empilha (int y, celula *p) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->valor = y;
    nova->seg = p->seg;
    p->seg = nova;
}
void Imprima(celula *p){
    for (p = p->seg; p != NULL; p = p->seg)
        printf("%d\n", p->valor);
}
int main(void){
    celula *p;
    p = malloc(sizeof(celula)); 
    p->seg = NULL;
    
    Empilha(4, p);
    Empilha(5, p);
    Imprima(p);
    system("pause");
}
