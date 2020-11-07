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

int main (void){
    celula cabeca, a, b, c;
    celula *lst;
    celula *p;

    lst = &cabeca;
    cabeca.seg = &a;
    a.conteudo = 3;
    a.seg = &b;
    b.conteudo = 5;
    b.seg = &c;
    c.conteudo = 10;
    c.seg = NULL;
 
    Imprima (lst);

    p = Busca (5, lst);
    if (p != NULL)
        printf ("Buscou %d\n", p->conteudo);

    p = BuscaR (3, lst);
    if (p != NULL)
        printf ("Buscou %d\n", p->conteudo);

    Remove (lst);
    Imprima (lst);
    system ("pause");
}
