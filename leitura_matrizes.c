#include <stdio.h>
#include <stdlib.h>

#define MAX_STR    80

int main(void){
    int **M;
    char *linha;
    int m, n;
    int i, j;
    FILE *fp;
    char str[MAX_STR];
    char *p;
    
    fp = fopen("D:\\Aulas\\ED\\matrizes.txt", "r");
    if (fp == NULL) exit (EXIT_FAILURE);
    while (1){
          fgets(str, MAX_STR, fp);
          m = atoi(str); 
          p = strchr (str, ' ');
          p++;
          n = atoi(p);
          printf("m=%d n=%d\n", m, n);
          if (m == 0 || n == 0) break;
          
          M = malloc (m * sizeof (int *));
          for (i = 0; i < m; i++)
              M[i] = malloc (n * sizeof (int));
          
          linha = malloc (n*2*sizeof(char)+1);
          // cuidado: aumentei +1 por causa do espaço após o último número
          for (i = 0; i <  m; i++){
              fgets (linha, n*2*sizeof(char)+2, fp);
              p = linha;
              for (j = 0; j < n; j++){
                  M[i][j] = atoi(p);
                  p += 2;  
              }
          }
 
          printf ("Matriz lida:\n");
          for (i = 0; i <  m; i++){
              for (j = 0; j < n; j++)
                  printf ("%2d", M[i][j]);
              putchar ('\n');
          }

          // aqui vai o código do seu programa              
          free(linha);
          free(M);
    }
    printf("Acabaram as matrizes!\n");
    system("pause");
    fclose(fp);
}
