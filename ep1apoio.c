#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/* tempo: usada para controlar o tempo de execução dos testes*/
double tempo() {
    return (double) clock()/CLOCKS_PER_SEC;
}

/* colocar suas rotinas aqui */
	
int main(int argc,char **argv) {
    double duracao, tempo_inicial, tempo_total, inicio_temp,
        tempo_ordenacao_sel, tempo_ordenacao_ins, tempo_ordenacao_merge,
    	tempo_ordenacao_quick;
    int n, *v, *v_aux, buscas_sel, buscas_ins, buscas_merge, buscas_quick;
    char algoritmo;
	
    srand(time(NULL));
 
    if (argc != 3){
        printf("Uso: %s tipo duracao\n", argv[0]);
        printf("   tipo: s(elecao) ou i(nsercao) ou m(ergesort) ou q(uicksort) ou t(odos)\n");
        printf("   duracao: duracao em segundos\n");
        return(0);
    }
 
    algoritmo = argv[1][0];
 
    if (algoritmo != 's' && algoritmo != 'i' && algoritmo != 'm' && algoritmo != 'q' && algoritmo != 't') {
        printf("opcao nao valida\n");
        return(-1);
    }
 
    sscanf(argv[2], "%lf", &duracao);

    printf("|-------------------------[EP1 - Vale a pena ordenar?]--------------------|\n"
        "|  Algoritmo escolhido: %10s     Duracao dos testes: %9.2f      |\n"
        "|            Tempos de Ordenacao                 Numero de Buscas         |\n"
        "|            Coloque seu nome aqui para identificacao!                    |\n"
        "|-------------------------------------------------------------------------|\n"
        "|   n   | Insercao Selecao Merge. Quick. | Insercao Selecao Merge. Quick. |\n"
        "|-------|-----------------------------------------------------------------|\n",
         algoritmo=='s'?"selecao":algoritmo=='i'?"insercao":algoritmo=='m'?"mergesort"
         :algoritmo=='q'?"quicksort":"todos", duracao);
 
    tempo_inicial = tempo();
    tempo_total = 0;
  
    for (n=2000; tempo_total < duracao; n += 2000) {
        v = malloc(n * sizeof(int));
        if (v == NULL) {
            printf("Erro na alocacao de memoria para o vetor v com %d elementos.\n",n);
            return(-1);
        }
  
        v_aux = malloc(n * sizeof(int));
        if (v_aux == NULL) {
            printf("Erro na alocacao de memoria para o vetor v_aux com %d elementos.\n",n);
            return(-1);
        }
 
        vetor_rand(v, n);
        vetor_copy(v, v_aux, n);
    
        if (algoritmo == 's' || algoritmo == 't') {
            inicio_temp = tempo();
            Selecao(n, v_aux);
            tempo_ordenacao_sel = tempo() - inicio_temp;
            buscas_sel = num_buscas(v, v_aux, n, tempo_ordenacao_sel);
            if (algoritmo != 's')
                vetor_copy(v, v_aux, n);
        }
 
        if (algoritmo == 'i' || algoritmo == 't') {
            inicio_temp = tempo();
            Insercao(n, v_aux);
            tempo_ordenacao_ins = tempo() - inicio_temp;
            buscas_ins = num_buscas(v, v_aux, n, tempo_ordenacao_ins);
            if (algoritmo != 'i')
                vetor_copy(v, v_aux, n);
        }
  
        if (algoritmo == 'm' || algoritmo == 't') {
            inicio_temp = tempo();
            Mergesort(0, n-1, v_aux);
            tempo_ordenacao_merge = abst(tempo() - inicio_temp);
            buscas_merge = num_buscas(v, v_aux, n, tempo_ordenacao_merge);
            if (algoritmo != 'm')
                vetor_copy(v, v_aux, n);
        }
   
        if (algoritmo == 'q' || algoritmo == 't') {
            inicio_temp = tempo();
            Quicksort(0, n-1, v_aux);
            tempo_ordenacao_quick = abst(tempo() - inicio_temp);
            buscas_quick = num_buscas(v, v_aux,n, tempo_ordenacao_quick);
        }
  
        free(v);
        free(v_aux);
        tempo_total = tempo() - tempo_inicial;
    }
    return(0);
}

