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

int main(void){
    int v[10]; 
    int k;
    
    for (k = 0; k < 10; k++) {
        v[k] = randint(10, 100);
        printf ("%d ", v[k]);
    }
    putchar('\n');
    celula *lst;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;
    
    for (k = 9; k >= 0; k--) 
         Insere(v[k], lst);

    Imprima(lst);
    system("pause");
}
