#include <stdio.h>
#include <stdlib.h>

int main(void){
   char txt [11] = "ABACATE!!!";
   unsigned char c;
   // lista dos caracteres da tabela ascii
   for (c = 32; c < 255; c++)
       putchar(c);
   // '\0' caractere nulo (final de string)
   // '\t' tabulação horizontal (tab)
   // '\n' mudança de linha (newline)
   // '\a' aviso sonoro (bel)
   txt [4] = '\t';
   printf ("\nTexto com tab: %s\n", txt);
   
   txt [4] = '\0';
   printf ("Texto encurtado: %s\n", txt);
   // beep 
   putchar('\a'); // somente funciona com som ligado :-)
   system("pause");
}
