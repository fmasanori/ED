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
void Remove (celula *p) {
    celula *lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free (lixo);
}
int randint(int a, int b){
    double r, x, R = RAND_MAX;
    int i;
    r = rand();
    x = r / (R + 1);
    i = (int) (x * (b - a + 1));
    return a + i;
}
celula * libera(celula *lst){
    celula *p, *q;
    p = lst;
    while (p != NULL){
    	q = p->seg;
    	free(p);
        p = q;
    }
    return NULL;
}
int main(void){
    int i;
    celula *lst;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
        Insere(randint(0, 9), lst);
    printf("Antes: ");
    Imprima(lst);
    lst = libera(lst);
    if (lst == NULL)
       printf("Vazia");
    system("pause");
}
