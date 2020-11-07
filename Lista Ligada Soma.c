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

int soma (celula *lst) {
     int s;
     celula *p;
   
     for (s = 0, p = lst->seg; p != NULL; p = p->seg)
         s = s + p->conteudo;
     return s;
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

int main(void){
    int i;
    celula *lst;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;

    srand(time(NULL));
    for (i = 0; i < 10; i++)
        Insere(randint(10, 100), lst);
    Imprima(lst);
    printf("Soma = %d\n", soma(lst));

    system("pause");
}
