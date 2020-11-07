typedef struct cel celula;
struct cel {
    int     conteudo;
    celula *prox;
};

int main (void) {
    printf ("sizeof (celula) = %d\n", sizeof (celula));        
    system ("pause");
}
