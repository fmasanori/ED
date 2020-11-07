#include <stdio.h>
#include <stdlib.h>

struct cel {
       int conteudo;
       struct cel *seg; /* seguinte */
};

typedef struct cel celula;

void Imprima (celula *lst) {
     celula *p;
     for (p = lst->seg; p != NULL; p = p->seg)
         printf ("%d\n", p->conteudo);
}

void Insere(int y, celula *p){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

int main(void){
    int i;
    celula *lst;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;

    for (i = 0; i < 10; i++)
        Insere(i, lst);
    Imprima(lst);
    system("pause");
}
