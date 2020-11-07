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
         printf ("%d", p->conteudo);
     putchar('\n');
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

void concatena(celula *lst1, celula *lst2){
    celula *p;
    p = lst1->seg;
    while (p->seg != NULL)
        p = p->seg;
    
    p->seg = lst2->seg;
    free(lst2);
}

int main(void){
    int i;
    celula *lst1, *lst2;
    lst1 = malloc(sizeof(celula));
    lst1->seg = NULL;
    lst2 = malloc(sizeof(celula));
    lst2->seg = NULL;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        Insere(randint(0, 9), lst1);
        Insere(randint(0, 9), lst2);
    }
    Imprima(lst1);
    Imprima(lst2);
    concatena(lst1, lst2);
    printf("Concatena: ");
    Imprima(lst1);       
    system("pause");
}
