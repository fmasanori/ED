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

int compara(celula *lst1, celula *lst2){
    celula *p1, *p2;
    p1 = lst1->seg;
    p2 = lst2->seg;
    while (p1->conteudo == p2->conteudo){
		p1 = p1->seg;
		p2 = p2->seg;
		if (p1 == NULL || p2 == NULL)
			return p1 == p2;
    }
    return 0;
}

int main(void){
    int i;
    celula *lst1, *lst2;
    
    lst1 = malloc(sizeof(celula));
    lst1->seg = NULL;
	Insere(3, lst1);
	Insere(2, lst1);
	Insere(1, lst1);

    lst2 = malloc(sizeof(celula));
    lst2->seg = NULL;
	Insere(3, lst2);
	Insere(2, lst2);
	Insere(1, lst2);

    Imprima(lst1);
    Imprima(lst2);
    if (compara(lst1, lst2)) 
		printf("Iguais\n");
	else
		printf("Diferentes\n");
    system("pause");
}
