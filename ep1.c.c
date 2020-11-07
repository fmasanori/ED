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

void soma(int a, int b){
    celula *lsta, *lstb;
    lsta = malloc(sizeof(celula));
    lsta->seg = NULL;

    lstb = malloc(sizeof(celula));
    lstb->seg = NULL;

    while (a != 0){
        Insere (a%10, lsta);
        a = a / 10;
    }
    Imprima(lsta); putchar('\n');

    while (b != 0){
        Insere (b%10, lstb);
        b = b / 10;
    }
    Imprima(lstb);
    
}

void copia_vetor_lista(void){
    int k;
    int v[10] = {7, 1, 3, 10, 5, 8, 4, 2, 6, 20};
    celula *lst;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;
    
    for (k = 9; k >= 0; k--)
        Insere(v[k], lst);

    Imprima(lst);
}

void copia_lista_vetor(void){
    int k;
    int v[10];
    celula *lst;
    celula *p;
    lst = malloc(sizeof(celula));
    lst->seg = NULL;
    
    for (k = 0; k < 10; k++)
        Insere(k, lst);

    Imprima(lst);
    p = lst->seg;
    k = 0;
    while (p != NULL){
        v[k] = p->conteudo;
        p = p->seg;
        k = k + 1;
    }
    for (k = 0; k < 10; k++)
        printf("%d ", v[k]);
}

int main(void){
    soma(513, 295);
    
    copia_vetor_lista();

    copia_lista_vetor();
    system("pause");
}


