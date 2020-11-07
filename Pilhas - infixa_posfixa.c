#include <stdio.h>
#include <stdlib.h>
#define DEBUG
// A função abaixo recebe uma expressão infixa inf e
// devolve a correspondente expressão posfixa.

char *infixaParaPosfixa (char inf[]) {
   char *posf; 
   char *pi; int t; // pilha
   int n, i, j;

   n = strlen (inf);
   posf = malloc (n * sizeof (char));
   pi = malloc (n * sizeof (char));
   t = 0;
   pi[t++] = inf[0];       // empilha '('
   for (j = 0, i = 1; /*X*/ inf[i] != '\0'; ++i) {
      // a pilha está em pi[0..t-1]
#ifdef DEBUG
      int k;
      for (k=0; k < i; k++) putchar (inf[k]);
      putchar ('\t'); putchar ('\t'); putchar ('\t');
      for (k=0; k < t; k++) putchar(pi[k]);
      putchar ('\t'); putchar ('\t');putchar ('\t');
      for (k=0; k < j; k++) putchar (posf[k]);
      putchar('\n');
#endif
      switch (inf[i]) {
         char x;
         case '(': pi[t++] = inf[i];          // empilha
                   break;
         case ')': while (1) {                // desempilha
                      x = pi[--t];
                      if (x == '(') break;
                      posf[j++] = x;
                   }
                   break;
         case '+': 
         case '-': while (1) {
                      x = pi[t-1];
                      if (x == '(') break;
                      --t;                    // desempilha
                      posf[j++] = x;
                   }
                   pi[t++] = inf[i];          // empilha
                   break;
         case '*':
         case '/': while (1) {
                      x = pi[t-1];
                      if (x == '(' || x == '+' || x == '-') 
                         break;
                      --t;
                      posf[j++] = x;
                   }
                   pi[t++] = inf[i];
                   break;
         default:  posf[j++] = inf[i];
      }
   }
   free (pi);
   posf[j] = '\0';      
   return posf;
}

int main (void){
//  char s[256] = "(A*(B*C+D))";
  char s[256] = "(A+B*C)";
//  char s[256] = "(A*(B+C)/D-E)";
//  char s[256] = "(A+B*(C-D*(E-F)-G*H)-I*3)";
//  char s[256] = "((A+B)*D+E/(F+A*D)+C)";
    printf ("%s\n", infixaParaPosfixa(s));
    system("pause");
}
