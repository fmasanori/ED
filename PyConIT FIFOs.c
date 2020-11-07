#define     TAM     6
int A[TAM][TAM] = {{0, 1, 0, 0, 0, 0}, 
                   {0, 0, 1, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0},
                   {0, 0, 1, 0, 1, 0},
                   {1, 0, 0, 0, 0, 0},
                   {0, 1, 0, 0, 0, 0}};
int *Distancias (int n, int o) {
int *d, x, y;
int *f, s, t; 
    d = malloc (n * sizeof (int));
    for (x = 0; x < n; x++) d[x] = -1;
    d[o] = 0;
    f = malloc (n * sizeof (int));
    s = 0; t = 1; f[s] = o; 
    while (s < t) { 
        x = f[s++]; 
        for (y = 0; y < n; y++)
            if (A[x][y] == 1 && d[y] == -1) {
                d[y] = d[x] + 1;
                f[t++] = y; 
            }
    }
    free (f);
    return d;
}
int main (void) {
    int i, j;
    int *resultado;
    resultado = Distancias (TAM, 3);
    printf ("Resultado: ");
    for (i = 0; i < 6; i++)
        printf ("%d ", resultado[i]);
    putchar('\n');
    system ("pause");
}
