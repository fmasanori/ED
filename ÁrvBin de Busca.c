#include <stdio.h>
#include <stdlib.h>

struct cel {
   int			chave;
   int        	conteudo; /* conteúdo */
   struct cel 	*esq;
   struct cel 	*dir;
};

typedef struct cel no;   /* nó */
typedef no     *arvore;

// Recebe a raiz r de uma árvore binária.
// Imprime a CHAVE dos nós em ordem e-r-d.
// Note que esse erd é diferente do anterior
void erd (arvore r) {
    if (r != NULL) {
       erd (r->esq);
       printf ("%d\n", r->chave);
       erd (r->dir); 
    }
}

no *Busca (arvore r, int k) {
   if (r == NULL || r->chave == k)
   	  return r;
	  if (r->chave > k)
	  	 return Busca (r->esq, k);
      else
	  	 return Busca (r->dir, k);
}

no *Busca_it (arvore r, int k) {
   while (r != NULL && r->chave != k) {
   		 if (r->chave > k) r = r->esq;
		 else r = r->dir;
   }
   return r;
}

no *cria_no (int k){
   no *novo;
   novo = (no *) malloc (sizeof (no));
   novo->chave = k;
   novo->esq = novo->dir = NULL;
   return novo;
}

arvore Insere (arvore r, no *novo) {
    no *f, *p;
	if (r == NULL) return novo;
	f = r;
	while (f != NULL) {
		  p = f;
		  if (f->chave > novo->chave) f = f->esq;
		  else f = f->dir;
    }
	if (p->chave > novo->chave) p->esq = novo;
	else p->dir = novo;
    return r;
}

arvore RemoveRaiz (arvore r) {
    no *p, *q;
	if (r->esq == NULL) q = r->dir;
	else {
		 p = r; q = r->esq;
		 while (q->dir != NULL) {
		 	   p = q; q = q->dir;
         }
		 /* q é o nó anterior a r na ordem e-r-d */
		 /* p é o pai de q */
		 if (p != r) {
		 	   p->dir = q->esq;
			   q->esq = r->esq;
         }
		 q->dir = r->dir;
    }
	free (r);
	return q;
}

int main(void){
    arvore r = NULL;
    
	r = Insere (r, cria_no(50));
	r = Insere (r, cria_no(30));
	r = Insere (r, cria_no(70));
	r = Insere (r, cria_no(20));
	r = Insere (r, cria_no(40));
	r = Insere (r, cria_no(60));
	r = Insere (r, cria_no(80));
	r = Insere (r, cria_no(15));
	r = Insere (r, cria_no(25));
	r = Insere (r, cria_no(35));
	r = Insere (r, cria_no(45));
	r = Insere (r, cria_no(36));
	erd(r);	
	r->esq = RemoveRaiz(Busca(r, 30));
    printf ("Depois de remover o 30\n");
	erd(r);
    system("pause");
}
