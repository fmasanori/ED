#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int n, m;   // numero de linhas e colunas
#define MAX 100
int A[MAX][MAX];
int n_regioes = 1;
struct cel {
       int l, c;
       struct cel *seg; /* seguinte */
};
typedef struct cel celula;
celula regioes[MAX];
void insere(int r, int l, int c){
    celula *p;
    celula *nova;
    p = &regioes[r];
    nova = malloc(sizeof(celula));
    nova->c = c;
    nova->l = l;
    nova->seg = p->seg;
    p->seg = nova;
}

void imprime(int r){
    celula *p;
    p = &regioes[r];
    printf("R(%d):", r);
    for (p = p->seg; p != NULL; p = p->seg)
        printf("%d %d, ", p->l, p->c);    
    putchar('\n');
}

int ocupado_em_cima(int l, int c){
    if (l == 0)
        return 0;
    return A[l-1][c] == 1;
}

int ocupado_esquerda(int l, int c){
    if (c == 0)
        return 0;
    return A[l][c-1] == 1;
}

int achou(int r, int l, int c){
    celula *p;
    p = &regioes[r];
    p = p->seg;
    while (p != NULL) {
        if (p->l == l && p->c == c)
            return 1;
        p = p->seg;
    }
    return 0;
}

int procura_regiao(int l, int c){
    int i;
    for (i = 1; i < n_regioes; i++)
        if (achou(i, l, c))
            return i;
    return 0;
}

void junta_regioes(int r1, int r2){
    celula *p1, *p2;
    if (r1 == r2)
        return;
    p1 = &regioes[r1];
    p2 = &regioes[r2];
    while (p1->seg != NULL) p1 = p1->seg;
    p1->seg = p2->seg;
    p2->seg = NULL;
}

void mapeia_regioes(void){
    int i, cont = 0;
    celula *p;
    for (i = 1; i < n_regioes; i++){
        p = &regioes[i];
        p = p->seg;
        if (p != NULL){
            cont++;
            while (p != NULL){
                A[p->l][p->c] = cont;
                p = p->seg;
            }
        }
    }
}

void imprime_regioes(void){
    int i;
    for (i = 1; i <= n_regioes; i++)
        if (regioes[i].seg != NULL)
            imprime(i);
}

void monta_regioes(void){
    int i, l, c, r1, r2;

    for (i = 0; i < MAX; i++)
        regioes[i].seg = NULL;

    for (l = 0; l < n; l++){
        for (c = 0; c < m; c++)
            if (A[l][c] == 1){
                r1 = r2 = 0;
                printf("%d %d", l, c);
                if(ocupado_esquerda(l,c)!=0){
                        putchar('e');
                        r1=procura_regiao(l,c-1);//isto esta correto
                        //if(r2==0)
                        insere(r1,l,c);
                }
                if(ocupado_em_cima(l,c)!=0){
                        putchar('c');
                        r2=procura_regiao(l-1,c);
                        if(r1==0)
                             insere(r2,l,c);
                }
                if (r1==0 && r2==0){
                        putchar('i');
                        insere(n_regioes,l,c);
                        n_regioes=n_regioes+1;
                }

                if (r1 != 0 && r2 != 0){
                        putchar('j');
                        junta_regioes(r1,r2);
                }

                imprime_regioes();
        }
    }
}


void imprime_imagem(void){
    int i, j;
    FILE *f;
    f = fopen("D:\\Aulas\\ED\\saida1.txt", "w");
    printf("Saida:\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            fprintf (f, "%d ", A[i][j]);
            printf ("%d ", A[i][j]);
        }
        putc('\n', f);
        putchar('\n');
    }
    fclose(f);
}

void processa_imagem(void){
    monta_regioes();
    mapeia_regioes();
    imprime_imagem();
}

void le_arquivo(void){
    FILE *f;
    char *p;
    #define MAX_STR 255
    char str[MAX_STR];
    int i, j;

    f = fopen("D:\\Aulas\\ED\\teste1.txt", "r");
    fgets(str, MAX_STR, f);
    n = atoi(str);
    p = str;
    while (!isspace(*p)) 
        p++;
    p++;
    m = atoi(p);
    printf ("%d %d\n", n, m);

    i = 0;
    while (fgets(str, MAX_STR, f) != NULL) {
        p = str;
        for (j = 0; j < m; j++){
            A[i][j] = atoi(p);
            p += 2;
        }
        i++;
    }    
    fclose(f);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf ("%d ", A[i][j]);
        putchar('\n');
    }
}
int main(void){
    le_arquivo();
    processa_imagem();
    system("pause");
}
