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

void Insere (int y, celula *p) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void BuscaEInsere (int y, int x, celula *lst) {
    celula *p, *q, *nova;
    nova = malloc (sizeof (celula));
    nova->conteudo = y;
    p = lst;
    q = lst->seg;
    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->seg;
    }
    nova->seg = q;
    p->seg = nova;
}

void Remove (celula *p) {
    celula *lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free (lixo);
}

celula *BuscaR (int x, celula *lst) {
    if (lst->seg == NULL)
        return NULL;
    if (lst->seg->conteudo == x)
        return lst->seg;
    return BuscaR (x, lst->seg);
}

celula *Busca (int x, celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL && p->conteudo != x)
        p = p->seg;
    return p;
}

void BuscaERemove (int x, celula *lst) {
    celula *p, *q;
    p = lst;
    q = lst->seg;
    while (q != NULL && q->conteudo != x) {
        p = q;
        q = q->seg;
    }
    if (q != NULL) {
        p->seg = q->seg;
        free (q);
    }
}

int main (void){
    celula cabeca;
    celula *lst;
    celula *p;
    
    lst = &cabeca;
    cabeca.seg = NULL;    
    Insere (10, lst);
    Insere (5, lst);
    Insere (3, lst);
 
    Imprima (lst);

    p = Busca (5, lst);
    if (p != NULL)
        printf ("Buscou %d\n", p->conteudo);

    p = BuscaR (3, lst);
    if (p != NULL)
        printf ("Buscou %d\n", p->conteudo);

    Remove (lst);
    printf ("Apos remover o primeiro = 3\n");
    Imprima (lst);

    BuscaERemove (5, lst);
    printf ("Apos remover elemento 5\n");
    Imprima (lst);

    BuscaEInsere (13, 10, lst);
    printf ("Apos inserir o 13 antes do 10\n");
    Imprima (lst);
    system ("pause");
}
