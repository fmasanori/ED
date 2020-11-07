#include <stdio.h>
#include <stdlib.h>

FILE *fp;          // descritor do arquivo de sa�da
long int  aux = 0;

int randint(int a, int b){
    double r, x, R = RAND_MAX;
    int i;
    r = rand();
    x = r / (R + 1);
    i = (int) (x * (b - a + 1));
    return a + i;
}

void gera_1s (int l, int c, int p){
     int i, j;
     printf ("Gerando matriz %dx%d Prob=%d\n", l, c, p);
     for (i = 0; i < l; i++) {
         for (j = 0; j < c; j++){
             if (randint(1, 100) < p)
                fputc('1', fp);
             else
                fputc('0', fp);
             fputc (' ', fp);
             aux++;   // apenas para indicar que est� vivo o programa
             if (aux == 900000){
                putchar('.');
                aux = 0;
             }
         }
         fputc('\n', fp);
     }
}

#define  MAX         1000
int main (void){
    int qtd_matrizes;
    int m, n;
    int prob;        // probabilidade de ser 1 (valor entre 1..100)
    
    srand (time(NULL));    // inicializa semente do gerador aleat�rio
    
    qtd_matrizes = randint(1, 10);   // n�mero de matrizes a serem geradas
    fp = fopen("D:\\Aulas\\ED\\matrizes.txt", "w");
    
    while (qtd_matrizes--){
          m = randint(5, 10)*MAX;            // linhas
          n = randint(5, 10)*MAX;            // colunas
          fprintf (fp, "%d %d\n", m, n);
          prob = randint(10, 50); // n�o muito esparsa ou densa
          gera_1s(m, n, prob);
    }

    fprintf (fp, "0 0\n"); // final do arquivo
    fclose(fp);
    system ("pause");
}
