#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINHAS_DEBUG    20
#define TAM                 8
int contador = 0;

void debug (char *str, int v[]){
     int i;
     printf ("%s", str);
     for (i = 1; i <= TAM; i++)
         printf ("%2d ", v[i]);
     putchar('\n');
     contador++;
     if (contador == MAX_LINHAS_DEBUG){
        system("pause");
        contador = 0;
     }
}
void InsereEmHeap (int m, int v[]) {
     int f = m+1;
     while /*X*/ (f > 1 && v[f/2] < v[f]) {
           int t = v[f/2]; v[f/2] = v[f]; v[f] = t;
           f = f/2;
     }
     debug("Insere: ", v);
}
void SacodeHeap (int m, int v[]) {
     int t, f = 2;
     while /*X*/ (f <= m) {
           if (f < m && v[f] < v[f+1]) ++f;
           if (v[f/2] >= v[f]) break;
           t = v[f/2]; v[f/2] = v[f]; v[f] = t;
           f *= 2;
     }
     debug("Sacode: ", v);
}
void Heapsort (int n, int v[]) {
     int m;
     debug("Inicio: ", v);
     for (m = 1; m < n; m++)
         InsereEmHeap (m, v);
     for (m = n; /*X*/ m > 1; m--) {
         int t = v[1]; v[1] = v[m]; v[m] = t;
         SacodeHeap (m-1, v);
     }
}
int RandomInteger (int low, int high)
{
    int k;
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

void gera_vetor(int v[]){
    int j, i, k;
    for (i = 1; i< TAM+1; i++){
         j = RandomInteger (1, 9);
         for (k = 1; k < i; k++)
            if ( v[k] == j ) 
                break;
         if(k == i) 
            v[i] = j;
         else 
            i--;
    }
}

int main (void){
    int v[TAM+1] = {-1, 3, 1, 2, 7, 6, 4, 5, 0};

    //gera_vetor(v);
    Heapsort(TAM, v);
    debug("Final : ", v);
    system ("pause");
}
