#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char *palavra;
typedef unsigned char *texto;
int trivial (palavra a, int m, texto b, int n) {
    int k, r, ocorrs, passos = 0;
    ocorrs = 0;
    for (k = m; k <= n; k++) {
        r = 0;
        passos += 1;
        while (r < m && a[m-r] == b[k-r]) r += 1;
        if (r >= m) ocorrs += 1;
    }
    printf ("K andou %d\n", passos);
    return ocorrs;
}
int BoyerMoore1 (palavra a, int m, texto b, int n) {
    int T1[256], i, k, r, ocorrs;
    /* pré-processamento da palavra a */
    for (i = 0; i < 256; i++) T1[i] = m;
    for (i = 1; i <= m; i++)  T1[a[i]] = m - i; 
    for (i = 1; i <= m; i++) 
       printf ("Letra %c -> T1=%d\n", a[i], T1[a[i]]);     
    ocorrs = 0; k = m; 
    while (k <= n) {
          r = 0;
          while (m-r >= 1 && a[m-r] == b[k-r]) r += 1;
          if (m-r < 1) ocorrs += 1;
          if (k == n) k += 1;
          else { printf ("Vai pular %d letras\n", T1[b[k+1]] + 1);
                 k += T1[b[k+1]] + 1; }
    }
    return ocorrs;
}
/* Recebe uma palavra a[1..m] com 1 <= m <= MAX e um texto b[1..n]
   e devolve o número de ocorrências de a em b.
*/
#define      MAX      256
int BoyerMoore2 (palavra a, int m, texto b, int n) {
    int T2[MAX], i, j, k, r, ocorrs;
    /* pré-processamento da palavra a */
    for (i = m; i >= 1; i--) {
        j = m-1; r = 0;
        while (m-r >= i && j-r >= 1)
        if (a[m-r] == a[j-r]) r += 1;
        else j -= 1, r = 0;
        T2[i] = m - j;
    }
    ocorrs = 0; k = m;
    while (k <= n) {
        r = 0;
        while (m-r >= 1 && a[m-r] == b[k-r]) r += 1;
        if (m-r < 1) ocorrs += 1;
        if (r == 0) k += 1;
        else { printf ("Vai pular %d letras\n", T2[m-r+1]);
               k += T2[m-r+1]; }
    }
    return ocorrs;
}

int main(void)
{
    unsigned char b[256];
    unsigned char a[MAX];
    int m, n, cont;
    // cuidado: o algoritmo ignora byte zero da string
    // ficaremos com o primeiro byte sem uso
#define TESTE        2
#define ALGORITMO    2
if (TESTE == 1){    
    strcpy((char *) &b[1], "ana e mariana gostam de banana");
    strcpy((char *) &a[1], "ana"); }
else if (TESTE == 2) {
    strcpy((char *) &b[1], "Os algoritimos de ordenacao");
    strcpy((char *) &a[1], "algoritimo"); }
else if (TESTE == 3) {
    strcpy((char *) &b[1], "GTAGTATATATATATACTACTAGTAG");
    strcpy((char *) &a[1], "TACTA"); }
else if (TESTE == 4) {
    strcpy((char *) &b[1], "XCBABXCBAAXBCBABX");
    strcpy((char *) &a[1], "BCBA"); }
m = strlen((char *) a) - 1;
n = strlen((char *) b) - 1;
if (ALGORITMO == 1)
    cont = trivial (a, m, b, n);
else if (ALGORITMO == 2)
    cont = BoyerMoore1 (a, m, b, n);
else if (ALGORITMO == 3)
    cont = BoyerMoore2 (a, m, b, n);
    printf ("Encontradas %d ocorrencia(s).\n", cont);
    system("pause");
}

