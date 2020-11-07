#include <stdio.h>
#include <stdlib.h>

struct cel {
       int conteudo;
       struct cel *seg; /* seguinte */
};

typedef struct cel celula;

void Imprima2 (celula *lst) {
     celula *p;
     for (p = lst; p != NULL; p = p->seg)
         printf ("%d\n", p->conteudo);
}

celula * inverte (celula *lst){
   celula *p, *p1, *p2;
   p = lst;
   p1 = p->seg; 
   p2 = p->seg;
   p->seg = NULL;
   while (p1 != NULL){
   		 p1 = p1->seg;
   		 p2->seg = p;
   		 p = p2;
   		 p2 = p1;
   }
   return p;
}
celula * Insere3(int y, celula *p){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = p;
    return nova;
}
int main(void){
    int i;
    celula *lst;
    lst = NULL;
    for (i = 0; i < 10; i++)
        lst = Insere3(i, lst);
    printf ("Antes\n");
    Imprima2(lst);
    lst = inverte (lst); 
    printf ("Depois\n");
    Imprima2(lst);
    system ("pause");
}
