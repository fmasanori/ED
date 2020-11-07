#include <stdio.h>
#include <stdlib.h>

int linhas [11] = {0, 23, 72, 80, 12, 3, 15, 35, 50, 7, 28};
int cont = 0;
void testa_apagao (int energia_perdida, int s[], int k)
{
  int i, soma = 0;
  for (i = 1; i <= k; i++)
     soma += linhas[s[i]];
  if (soma == energia_perdida){
     printf ("Faltam %d MegaWatts\n", energia_perdida);
     printf ("Linhas com problema:");
     for (i = 1; i <= k; i++)
         printf("%3d", s[i]);
     printf ("\n");
  }
}
void imprima (int s[], int k)
{
   int i;
   for (i = 1; i <= k; i++)
       printf ("%2d", s[i]);
   putchar ('\n');
   if (++cont == 20){
      cont = 0;
      system("pause");
   }
}

int cheques [5] = {0, 61, 62, 63, 64};

void testa_cheques (int desconto, int s[], int k)
// Soma dos subconjuntos (SUBSET SUM Problem) 
{
  int i, soma = 0;
  for (i = 1; i <= k; i++)
     soma += cheques[s[i]];
  if (soma == desconto){
     printf ("Possiveis cheques:");
     for (i = 1; i <= k; i++)
         printf("%3d", s[i]);
     printf ("\n");
  }
}

void subseqLex (int n)
{ 
   int *s, k;    
   s = (int *) malloc ((n+1) * sizeof (int));
   s[0] = 0;
   k = 0;
   while (1) {
      if (s[k] < n) {
         s[k+1] = s[k] + 1;
         k += 1;
      } else {
         s[k-1] += 1;
         k -= 1;
      }
      if (k == 0) 
         break;
      
      imprima (s, k);
      //testa_apagao (35, s, k);
      //testa_cheques(125, s, k);
   }
   system("pause");
   free (s);
} 

void SseqR (int s[], int k, int m, int n) {
     if (m <= n) {
        s[k+1] = m;
        imprima (s, k+1);
        SseqR (s, k+1, m+1, n); /* inclui m */
        SseqR (s, k, m+1, n); /* não inclui m */
     }
}

void SubseqLex2 (int n) {
     int *s;
     s = (int *) malloc ((n+1) * sizeof (int));
     SseqR (s, 0, 1, n);
     free (s);
}

void subseqLexEsp (int n) { 
   int *s, k;    
   s = (int *) malloc ((n+1) * sizeof (int));
   s[1] = 0;
   k = 1;
   while (1) {
      if (s[k] == n) {
         k -= 1; 
         if (k == 0) break;
      } else {
         s[k] += 1;   
         while (s[k] < n) {
            s[k+1] = s[k] + 1;
            k += 1;
         }
      }
      imprima (s, k);
   }
   free (s);
}

// Esta função auxiliar recebe s[1..k] e imprime, 
// em ordem lexicográfica especial,
// todas as subseqüências da forma s[1..k]t[k+1..]
// onde t[k+1..] é uma subseqüência de m..n.
// Em seguida, imprime a seqüência s[1..k].
void recursEsp (int s[], int k, int m, int n) {
   if (m > n) imprima (s, k);
   else {
      s[k+1] = m;
      recursEsp (s, k+1, m+1, n); // inclui m
      recursEsp (s, k,   m+1, n); // não inclui m
   }
}

// Recebe n e imprime todas as subseqüências 
// de 1..n (inclusive a subseqüência vazia).
void subseqLexEsp2 (int n) {
   int *s;    
   s = (int *) malloc ((n+1) * sizeof (int));
   recursEsp (s, 0, 1, n);
   free (s);
}

void rec (int s[], int j, int m, int k, int n) {
   if (j == k) imprima (s, k);
   else {
      if (m <= n - k + j + 1){
          s[j+1] = m;
          rec (s, j+1, m+1, k, n); // inclui m
          rec (s, j, m+1, k, n); // não inclui m
	  }
   }
}

void combina(int n, int k){
   int *s;    
   s = (int *) malloc ((n+1) * sizeof (int));
   rec (s, 0, 1, k, n);
   free (s);
}
int main (void)
{
    int n = 10;
    subseqLex(n);
    
    //subseqLexEsp2(n);
    
    system("pause");
}
