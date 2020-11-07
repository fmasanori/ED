#include <stdio.h>
#include <stdlib.h>

int main(void){
  struct {
    int dia, mes, ano;
  } x;
  struct dma {
    int dia, mes, ano;
  };
  struct dma y;
  x.dia = 31;
  x.mes = 12;
  x.ano = 2013;
  struct dma *p;
  p = &y;
  p->dia = 31;     // (*p).dia = 31
  p->mes = 12;     // (*p).mes = 12
  p->ano = 2013;   // (*p).ano = 2013
  printf ("Dia:%d, Mes:%d, Ano:%d\n", y.dia, y.mes, y.ano);
  system("pause");
}
