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

int randint(int a, int b){
    double r, x, R = RAND_MAX;
    int i;
    r = rand();
    x = r / (R + 1);
    i = (int) (x * (b - a + 1));
    return a + i;
}

celula *Minimo(celula *lst){
    celula *p, *p_min;
    int min;
    p = p_min = lst->seg;
    if (p != NULL)
        min = p->conteudo;
    while (p != NULL) {
        if (p->conteudo < min) {
            p_min = p;
            min = p->conteudo;
        }
        p = p->seg;
    }
    return p_min;
}

int main(void){
    int i;
    celula *lst;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;

    srand(time(NULL));
    for (i = 0; i < 10; i++)
        Insere(randint(10, 100), lst);
    Imprima(lst);
    printf("Minimo %d\n", Minimo(lst)->conteudo);

    system("pause");
}
