#include <stdio.h>
#include <stdlib.h>

struct cel {
   int         conteudo; /* conteúdo */
   struct cel *esq;
   struct cel *dir;
};
typedef struct cel no;   /* nó */
typedef no     *arvore;

int n;
no * resposta;

// Insere à esquerda de um nó na árvore binária
void Insere_esq (int y, no *p_no) {
    no *novo;
    novo = (no *) malloc (sizeof (no));
    // folha nova não possui filhos
    novo->esq = NULL;
    novo->dir = NULL;
    // atualiza conteúdo e o apontador esquerdo
    novo->conteudo = y;
    p_no->esq = novo;
}

// Insere à direita de um nó na árvore binária
void Insere_dir (int y, no *p_no) {
    no *novo;
    novo = (no *) malloc (sizeof (no));
    // folha nova não possui filhos
    novo->esq = NULL;
    novo->dir = NULL;
    // atualiza conteúdo e o apontador direiro
    novo->conteudo = y;
    p_no->dir = novo;    
}

// Cria raiz com conteúdo y
no * Raiz (int y) {
    no *novo;
    novo = (no *) malloc (sizeof (no));
    // raiz nova não possui filhos
    novo->esq = NULL;
    novo->dir = NULL;
    novo->conteudo = y;
    return novo;   
}

int Altura (arvore r) {
    if (r == NULL)
       return -1; /* a altura de uma árvore vazia é -1 */
    else {
       int he = Altura (r->esq);
       int hd = Altura (r->dir);
       if (he < hd) return hd + 1;
       else return he + 1;
    }
}
// Recebe a raiz r de uma árvore binária.
// Imprime os conteúdos dos nós em ordem e-r-d.
void erd (arvore r) {
    if (r != NULL) {
       erd (r->esq);
       printf ("%d\n", r->conteudo);
       erd (r->dir); 
    }
}
void red (arvore r) {
    if (r != NULL) {
       printf ("%d\n", r->conteudo);
       red (r->esq);
       red (r->dir); 
    }
}

void edr (arvore r) {
    if (r != NULL) {
       edr (r->esq);
       edr (r->dir); 
       printf ("%d\n", r->conteudo);
    }
}

void busca (arvore r, int k) {
    if (r != NULL) {
       busca (r->esq, k);
       if (r->conteudo == k)
            resposta = r;
       busca (r->dir, k); 
    }
}
void conta_nos (arvore r) {
    if (r != NULL) {
       conta_nos (r->esq);
       n++;
       conta_nos (r->dir); 
    }
}
// Recebe a raiz r de uma árvore binária.
// Imprime os conteúdos dos nós em ordem e-r-d.
// Supõe que a árvore não tem mais que 100 nós.
void erd_i (arvore r) {
    no *x, *p[100];
    int t = 0;
    x = r;
    while (x != NULL || t > 0) {
       // a pilha é p[0..t-1]; o índice do topo é t-1
       if (x != NULL) {
          p[t++] = x;
          x = x->esq;
       }
       else {
          x = p[--t];
          printf ("%d\n", x->conteudo);
          x = x->dir;
       }
    }
}

int main(void){
    arvore r;
    no *aux;
    resposta = malloc(sizeof(no *));
    
    r = Raiz(5);
    Insere_esq (3, r);
    Insere_dir (8, r);

    aux = r->esq; // 3
    Insere_esq (1, aux);
    Insere_dir (4, aux);

    aux = aux->esq;   // 1
    Insere_esq (0, aux);
    Insere_dir (2, aux);
    
    aux = r->dir; // 8
    Insere_esq (6, aux);
    Insere_dir (9, aux);
    
    aux = aux->esq;     // 6
    Insere_dir (7, aux);

//    erd_i (r);
    resposta->conteudo = -1;
    busca(r, 7);
    printf ("Achei %d!\n", resposta->conteudo);

    n = 0;
    conta_nos(r);
    printf ("Numero de nos = %d\n", n);
//    erd (r);
//    printf ("Altura = %d\n", Altura (r));
    system("pause");
}
