#include <stdio.h>
#include <stdlib.h>

struct cel {
    int dia;
    int mes;
    int ano;
};

typedef  struct cel     t_data;

int main(void){
    t_data data;
    t_data *p;
    p = &data;
    p->dia = 16;
    p->mes = 8;
    p->ano = 2011;
    printf ("%d %d %d\n", data.dia, data.mes, data.ano);
    system ("pause");
}






