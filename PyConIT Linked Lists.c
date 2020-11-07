#include <stdio.h>
#include <stdlib.h>

struct cel {
       int cargo;
       struct cel *next;
};

typedef struct cel celula;

void Print (celula *lst) {
    celula *p;
    for (p = lst->next; p != NULL; p = p->next)
        printf ("%d\n", p->cargo);
}

void Insert (int y, celula *p) {
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->cargo = y;
    nova->next = p->next;
    p->next = nova;
}

int main (void){
    celula head;
    celula *lst;
    lst = &head;
    head.next = NULL;    
    Insert (3, lst);
    Insert (2, lst);
    Insert (1, lst);
    Print (lst);
    system ("pause");
}
