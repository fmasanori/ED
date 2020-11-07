#include <stdio.h>
#include <stdlib.h>

struct cel {
       int conteudo;
       struct cel *seg; /* seguinte */
};

typedef struct cel celula;

void Imprima2(celula *lst) {
     celula *p;
     for (p = lst; p != NULL; p = p->seg)
         printf ("%d\n", p->conteudo);
}

void Insere2(int y, celula **p){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = y;

    if (*p == NULL) {
        *p = nova;
        nova->seg = NULL;
    } else {
        nova->seg = *p;
        *p = nova;
    }
}

int main(void){
    int i;
    celula *lst; // int a    int *
    lst = NULL;

    for (i = 0; i < 10; i++)
        Insere2(i, &lst);
    Imprima2(lst);
    system("pause");
}
